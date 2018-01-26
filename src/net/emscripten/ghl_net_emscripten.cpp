
#include <ghl_api.h>
#include <ghl_net.h>
#include <ghl_log.h>
#include <ghl_data.h>
#include <ghl_data_stream.h>
#include "../../ghl_log_impl.h"
#include <emscripten.h>
#include <vector>
static const char* MODULE = "Net";

static void GET_async_wget2_data_onload_func(unsigned, void* arg, void * data, unsigned size) {
	GHL::NetworkRequest* handler = static_cast<GHL::NetworkRequest*>(arg);
	handler->OnResponse(200);
	handler->OnData(reinterpret_cast<GHL::Byte*>(data),size);
	handler->OnComplete();
    handler->Release();
}


static void GET_async_wget2_data_onerror_func(unsigned,void* arg, int code, const char* status) {
	GHL::NetworkRequest* handler = static_cast<GHL::NetworkRequest*>(arg);
	handler->OnResponse(code);
	handler->OnError(status ? status : "unknown");
    handler->OnComplete();
    handler->Release();
}

static void GET_async_wget2_data_onprogress_func(unsigned,void* arg, int loaded, int total) {

}

class NetworkEmscripten : public GHL::Network {
private:
	static size_t m_init_counter;
public:
	NetworkEmscripten() {
		
	}
	~NetworkEmscripten() {
		
	}

	 /// GET request
    virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
        if (!handler)
            return false;
        handler->AddRef();
        emscripten_async_wget2_data(handler->GetURL(),
        	"GET",
        	"",
        	handler,
        	1,
        	&GET_async_wget2_data_onload_func,
        	&GET_async_wget2_data_onerror_func,
        	&GET_async_wget2_data_onprogress_func
        	);
        return true;
    }

    /// POST request
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        if (!handler)
            return false;
        handler->AddRef();
        std::vector<char> updata;
        if (data) {
        	updata.reserve(data->GetSize()+1);
        	updata.resize(data->GetSize());
        	::memcpy(updata.data(),data->GetData(),data->GetSize());
        }
        updata.push_back(0);
        emscripten_async_wget2_data(handler->GetURL(),
        	"POST",
        	updata.data(),
        	handler,
        	1,
        	&GET_async_wget2_data_onload_func,
        	&GET_async_wget2_data_onerror_func,
        	&GET_async_wget2_data_onprogress_func
        	);
        return true;
    }

    virtual bool GHL_CALL PostStream(GHL::NetworkRequest* handler, GHL::DataStream* data) {
         if (!handler)
            return false;
        handler->AddRef();
        std::vector<char> updata;
        if (data) {
            static const size_t CHUNK_SIZE = 1024 * 2;
            while (!data->Eof()) {
                size_t pos = updata.size();
                updata.resize(pos + CHUNK_SIZE);
                size_t readed = data->Read(reinterpret_cast<GHL::Byte*>(&updata[pos]),CHUNK_SIZE);
                updata.resize(pos + readed);
            }
        }
        updata.push_back(0);
        emscripten_async_wget2_data(handler->GetURL(),
            "POST",
            updata.data(),
            handler,
            1,
            &GET_async_wget2_data_onload_func,
            &GET_async_wget2_data_onerror_func,
            &GET_async_wget2_data_onprogress_func
            );
        return true;
    }

    virtual void GHL_CALL Process() {
        //PROFILE(Process);
        
    }
};

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new NetworkEmscripten();
}


GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* n) {
    delete static_cast<NetworkEmscripten*>(n);
}