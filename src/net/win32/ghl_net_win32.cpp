
#include <ghl_api.h>
#include <ghl_net.h>
#include <ghl_log.h>
#include <ghl_data.h>

#include <iostream>
#include <vector>

#include "../../ghl_log_impl.h"

static const char* MODULE = "Net";

#include <Windows.h>
#include <Winhttp.h>
#include <cassert>

class NetworkWin32;

class NetworkWin32_Request {
public:
	WCHAR*	szURL;
	WCHAR szHost[256];
	URL_COMPONENTS urlComp;
	NetworkWin32*	m_context;
	GHL::NetworkRequest* m_req;
	HINTERNET hConnect;
	HINTERNET hRequest;
	std::string m_error;
	const GHL::Data* m_post_data;
	GHL::Byte*	m_buffer;
	DWORD m_buffer_size;
	enum State {
		S_INIT,
		S_CONNECTED,
		S_RECEIVE,
		S_COMPLETE,
		S_ERROR
	} m_state;
	bool m_parse_state;
	NetworkWin32_Request(NetworkWin32* context, GHL::NetworkRequest* req) : szURL(0), m_context(context), m_req(req) {
		hConnect = 0;
		hRequest = 0;
		m_buffer = 0;
		m_buffer_size = 0;
		m_post_data = 0;
		m_state = S_INIT;
		m_parse_state = false;
		m_req->AddRef();
		UINT32 l = MultiByteToWideChar(CP_UTF8, 0, req->GetURL(), -1, NULL, 0);
		szURL = new WCHAR[l];
		MultiByteToWideChar(CP_UTF8, 0, req->GetURL(), -1, szURL, l);
	}
	~NetworkWin32_Request() {
		cleanup();

		m_req->Release();
		delete[] szURL;
		if (m_post_data) {
			m_post_data->Release();
			m_post_data = 0;
		}
	}
	bool load_url() {
		ZeroMemory(&urlComp, sizeof(urlComp));
		urlComp.dwStructSize = sizeof(urlComp);
		// Use allocated buffer to store the Host Name.
		urlComp.lpszHostName = szHost;
		urlComp.dwHostNameLength = sizeof(szHost) / sizeof(szHost[0]);

		// Set non-zero lengths to obtain pointer a to the URL Path.
		// NOTE: If we threat this pointer as a null-terminated string,
		//       it gives us access to additional information as well. 
		urlComp.dwUrlPathLength = (DWORD)-1;

		// Crack HTTP scheme.
		urlComp.dwSchemeLength = (DWORD)-1;

		// Crack the URL.
		if (!WinHttpCrackUrl(szURL, 0, 0, &urlComp))
		{
			LOG_ERROR("failed parse url");
			return false;
		}

		return true;
	}

	static VOID CALLBACK
		AsyncCallback(
		IN HINTERNET hInternet,
		IN DWORD_PTR dwContext,
		IN DWORD dwInternetStatus,
		IN LPVOID lpvStatusInformation OPTIONAL,
		IN DWORD dwStatusInformationLength
		);

	bool get();
	bool post(const GHL::Data* data);

	void cleanup();
};

class NetworkWin32 : public GHL::Network {
public:
	HINTERNET hSession;
	CRITICAL_SECTION	critical;

	struct ScopedLock {
		NetworkWin32* m;
		ScopedLock(NetworkWin32* m) : m(m) {
			EnterCriticalSection(&m->critical);
		}
		~ScopedLock() {
			LeaveCriticalSection(&m->critical);
		}
	};

	std::vector<NetworkWin32_Request*> m_requests;

	NetworkWin32() {
		InitializeCriticalSection(&critical);
		hSession = WinHttpOpen(L"GHL HTTP Client/1.0",
			WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
			WINHTTP_NO_PROXY_NAME,
			WINHTTP_NO_PROXY_BYPASS, WINHTTP_FLAG_ASYNC);
		if (!hSession) {
			LOG_ERROR("failed open session");
		}
	}

	~NetworkWin32() {
		WinHttpCloseHandle(hSession);
		DeleteCriticalSection(&critical);
	}

	/// GET request
	virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
		if (!handler)
			return false;
		NetworkWin32_Request* req = new NetworkWin32_Request(this, handler);
		if (!req->get()) {
			delete req;
			return false;
		}
		m_requests.push_back(req);
		return true;
	}
	/// POST request
	virtual bool GHL_CALL Post(GHL::NetworkRequest* handler, const GHL::Data* data) {
		if (!handler)
			return false;
		NetworkWin32_Request* req = new NetworkWin32_Request(this, handler);
		if (!req->post(data)) {
			delete req;
			return false;
		}
		m_requests.push_back(req);
		return true;
	}

	virtual bool GHL_CALL PostStream(GHL::NetworkRequest* handler, GHL::DataStream* data) {
        if (!handler)
            return false;
        if (!data)
            return false;
        
        // @todo
        return false;
    }

	virtual void GHL_CALL Process() {
		ScopedLock lock(this);
		for (std::vector<NetworkWin32_Request*>::iterator it = m_requests.begin(); it != m_requests.end();) {
			if (!(*it)->m_parse_state) {
				++it;
				continue;
			}
			(*it)->m_parse_state = false;

			if ((*it)->m_state == NetworkWin32_Request::S_COMPLETE) {
				(*it)->m_req->OnComplete();
				delete *it;
				it = m_requests.erase(it);
				continue;
			}
			else if ((*it)->m_state == NetworkWin32_Request::S_ERROR) {
				(*it)->m_req->OnError((*it)->m_error.c_str());
				delete *it;
				it = m_requests.erase(it);
				continue;
			}
			else if ((*it)->m_state == NetworkWin32_Request::S_CONNECTED) {
				DWORD dwStatusCode = 0;
				DWORD dwTemp = sizeof(dwStatusCode);
				if (WinHttpQueryHeaders((*it)->hRequest, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
					NULL, &dwStatusCode, &dwTemp, NULL)) {
					(*it)->m_req->OnResponse(dwStatusCode);
				}
				if (WinHttpQueryDataAvailable((*it)->hRequest, NULL) == FALSE) {
					(*it)->m_req->OnError("WinHttpQueryDataAvailable");
					delete *it;
					it = m_requests.erase(it);
					continue;
				}
			}
			else if ((*it)->m_state == NetworkWin32_Request::S_RECEIVE) {
			
				(*it)->m_req->OnData((*it)->m_buffer, (*it)->m_buffer_size);
				delete[](*it)->m_buffer;
				(*it)->m_buffer = 0;
				if (WinHttpQueryDataAvailable((*it)->hRequest, NULL) == FALSE) {
					(*it)->m_req->OnError("WinHttpQueryDataAvailable");
					delete *it;
					it = m_requests.erase(it);
					continue;
				}
			}
			else {

			}
				
			++it;
			
		}
	}

	
};



bool NetworkWin32_Request::get() {
	if (!load_url())
		return false;
	hConnect = WinHttpConnect(m_context->hSession, szHost,
		urlComp.nPort, 0);
	if (hConnect == NULL) {
		LOG_ERROR("failed connect");
		return false;
	}
	DWORD dwOpenRequestFlag = (INTERNET_SCHEME_HTTPS == urlComp.nScheme) ?
		WINHTTP_FLAG_SECURE : 0;
	hRequest = WinHttpOpenRequest(hConnect,
		L"GET", urlComp.lpszUrlPath,
		NULL, WINHTTP_NO_REFERER,
		WINHTTP_DEFAULT_ACCEPT_TYPES,
		dwOpenRequestFlag);
	if (hRequest == NULL) {
		LOG_ERROR("failed open request");
		return false;
	}
	WINHTTP_STATUS_CALLBACK pCallback = WinHttpSetStatusCallback(hRequest,
		(WINHTTP_STATUS_CALLBACK)&NetworkWin32_Request::AsyncCallback,
		WINHTTP_CALLBACK_FLAG_ALL_COMPLETIONS ,
		0);
	if (!WinHttpSendRequest(hRequest,
		WINHTTP_NO_ADDITIONAL_HEADERS, 0,
		WINHTTP_NO_REQUEST_DATA, 0, 0,
		(DWORD_PTR)this))
	{
		LOG_ERROR("failed send request");
		return false;
	}
	return true;
}

bool NetworkWin32_Request::post(const GHL::Data* data) {
	if (!load_url()) {
		return false;
	}
	hConnect = WinHttpConnect(m_context->hSession, szHost,
		urlComp.nPort, 0);
	if (hConnect == NULL) {
		LOG_ERROR("failed connect");
		return false;
	}
	DWORD dwOpenRequestFlag = (INTERNET_SCHEME_HTTPS == urlComp.nScheme) ?
		WINHTTP_FLAG_SECURE : 0;
	hRequest = WinHttpOpenRequest(hConnect,
		L"POST", urlComp.lpszUrlPath,
		NULL, WINHTTP_NO_REFERER,
		WINHTTP_DEFAULT_ACCEPT_TYPES,
		dwOpenRequestFlag);
	if (hRequest == NULL) {
		LOG_ERROR("failed open request");
		return false;
	}
	m_post_data = data->Clone();
	WINHTTP_STATUS_CALLBACK pCallback = WinHttpSetStatusCallback(hRequest,
		(WINHTTP_STATUS_CALLBACK)&NetworkWin32_Request::AsyncCallback,
		WINHTTP_CALLBACK_FLAG_ALL_COMPLETIONS |
		WINHTTP_CALLBACK_FLAG_REDIRECT,
		0);
	if (!WinHttpSendRequest(hRequest,
		WINHTTP_NO_ADDITIONAL_HEADERS, 0,
		(LPVOID)m_post_data->GetData(), m_post_data->GetSize(), m_post_data->GetSize(),
		(DWORD_PTR)this))
	{
		LOG_ERROR("failed send request");
		return false;
	}
	return true;
}

void NetworkWin32_Request::cleanup() {
	
	if (hRequest) {
		WinHttpSetStatusCallback(hRequest,
			NULL,
			0,
			0);

		WinHttpCloseHandle(hRequest);
		hRequest = NULL;
	}
	if (hConnect)
	{
		WinHttpCloseHandle(hConnect);
		hConnect = NULL;
	}
}

VOID CALLBACK
NetworkWin32_Request::AsyncCallback(
IN HINTERNET hInternet,
IN DWORD_PTR dwContext,
IN DWORD dwInternetStatus,
IN LPVOID lpvStatusInformation OPTIONAL,
IN DWORD dwStatusInformationLength
) {
	NetworkWin32_Request* _this = reinterpret_cast<NetworkWin32_Request*>(dwContext);
	switch (dwInternetStatus) {
	case WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE:
		
		// Prepare the request handle to receive a response.
		if (WinHttpReceiveResponse(_this->hRequest, NULL) == FALSE)
		{
			NetworkWin32::ScopedLock lock(_this->m_context);
			_this->m_state = S_ERROR;
			_this->m_parse_state = true;
			_this->m_error = "WinHttpReceiveResponse";
			_this->cleanup();
		}
		break;

	case WINHTTP_CALLBACK_STATUS_REQUEST_ERROR: {
		NetworkWin32::ScopedLock lock(_this->m_context);
		_this->m_state = S_ERROR;
		_this->m_parse_state = true;
		_this->m_error = "WINHTTP_CALLBACK_STATUS_REQUEST_ERROR";
		_this->cleanup();
	} break;

	case WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE: {
		NetworkWin32::ScopedLock lock(_this->m_context);
		_this->m_state = S_CONNECTED;
		_this->m_parse_state = true;
	}break;
	case WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE: {
		DWORD dwSize = *((LPDWORD)lpvStatusInformation);
		if (dwSize == 0) {
			NetworkWin32::ScopedLock lock(_this->m_context);
			_this->m_state = S_COMPLETE;
			_this->m_parse_state = true;
			_this->cleanup();
		}
		else {

			GHL::Byte* lpOutBuffer = new GHL::Byte[dwSize];
			
			// Read the available data.
			if (WinHttpReadData(_this->hRequest, (LPVOID)lpOutBuffer,
				dwSize, NULL) == FALSE)
			{
				NetworkWin32::ScopedLock lock(_this->m_context);
				assert(!_this->m_parse_state);
				_this->m_state = S_ERROR;
				_this->m_parse_state = true;
				_this->m_error = "WinHttpReadData";
				_this->cleanup();
				delete[] lpOutBuffer;
			}
		}
	}break;

	case WINHTTP_CALLBACK_STATUS_READ_COMPLETE:
		
		if (dwStatusInformationLength != 0)
		{
			//TransferAndDeleteBuffers(cpContext, (LPSTR)lpvStatusInformation, dwStatusInformationLength);

			NetworkWin32::ScopedLock lock(_this->m_context);
			assert(!_this->m_parse_state);
			_this->m_state = S_RECEIVE;
			_this->m_parse_state = true;
			_this->m_buffer = (GHL::Byte*)lpvStatusInformation;
			_this->m_buffer_size = dwStatusInformationLength;

			//std::string msg(reinterpret_cast<const char*>(_this->m_buffer), _this->m_buffer_size);
			//LOG_INFO(msg);
			
			// Check for more data.
			//if (QueryData(cpContext) == FALSE)
			//{
			//	Cleanup(cpContext);
			//}
		}
		break;
	}
	
}

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new NetworkWin32();
}


GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* n) {
    delete static_cast<NetworkWin32*>(n);
}

