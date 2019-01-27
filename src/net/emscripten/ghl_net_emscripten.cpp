
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

extern "C" EMSCRIPTEN_KEEPALIVE void GHL_NetworkEmscripten_onLoad(GHL::NetworkRequest* handler,void* data, unsigned size) {
    handler->OnResponse(200);
    handler->OnData(reinterpret_cast<GHL::Byte*>(data),size);
    handler->OnComplete();
    handler->Release();
}
extern "C" EMSCRIPTEN_KEEPALIVE void GHL_NetworkEmscripten_onError(GHL::NetworkRequest* handler,int code, const char* status) {
    handler->OnResponse(code);
    handler->OnError(status ? status : "unknown");
    handler->OnComplete();
    handler->Release();
}

extern "C" EMSCRIPTEN_KEEPALIVE const char* GHL_NetworkEmscripten_getURL(GHL::NetworkRequest* handler) {
    return handler->GetURL();
}
extern "C" EMSCRIPTEN_KEEPALIVE GHL::UInt32 GHL_NetworkEmscripten_getHeadersCount(GHL::NetworkRequest* handler) {
    return handler->GetHeadersCount();
}
extern "C" EMSCRIPTEN_KEEPALIVE const char* GHL_NetworkEmscripten_getHeaderName(GHL::NetworkRequest* handler,GHL::UInt32 i) {
    return handler->GetHeaderName(i);
}
extern "C" EMSCRIPTEN_KEEPALIVE const char* GHL_NetworkEmscripten_getHeaderValue(GHL::NetworkRequest* handler,GHL::UInt32 i) {
    return handler->GetHeaderValue(i);
}
extern "C" EMSCRIPTEN_KEEPALIVE void GHL_NetworkEmscripten_onFetchHeader(GHL::NetworkRequest* handler,const char* key, const char* value) {
    handler->OnHeader(key,value);
}
extern "C" EMSCRIPTEN_KEEPALIVE void GHL_NetworkEmscripten_onFetchResponse(GHL::NetworkRequest* handler,int code) {
    handler->OnResponse(code);
}
extern "C" EMSCRIPTEN_KEEPALIVE void GHL_NetworkEmscripten_onFetchData(GHL::NetworkRequest* handler,const GHL::Byte* data, GHL::UInt32 size) {
    handler->OnData(data,size);
}  
extern "C" EMSCRIPTEN_KEEPALIVE void GHL_NetworkEmscripten_onFetchEnd(GHL::NetworkRequest* handler) {
    handler->OnComplete();
    handler->Release();
}   
extern "C" EMSCRIPTEN_KEEPALIVE void GHL_NetworkEmscripten_onFetchError(GHL::NetworkRequest* handler,const char* status) {
    handler->OnError(status ? status : "unknown");
    handler->OnComplete();
    handler->Release();
}   

class NetworkEmscripten : public GHL::Network {
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

    void PostBinary(GHL::NetworkRequest* handler,const GHL::Byte* data, GHL::UInt32 data_size) {
        handler->AddRef();
        EM_ASM({
            var _handler = $0;
            var _url = Pointer_stringify(Module['_GHL_NetworkEmscripten_getURL'](_handler));
            var http = new XMLHttpRequest();
            var handle = Browser.getNextWgetRequestHandle();
            http.open('POST', _url, true);
            http.responseType = 'arraybuffer';

            http.onload = function http_onload(e) {
              if (http.status == 200) {
                var byteArray = new Uint8Array(http.response);
                var buffer = _malloc(byteArray.length);
                HEAPU8.set(byteArray, buffer);
                Module['_GHL_NetworkEmscripten_onLoad'](_handler,buffer,byteArray.length);
                 _free(buffer);
              } else {
                var length = lengthBytesUTF8(http.statusText)+1;
                var buffer = Module._malloc(length);
                stringToUTF8(http.statusText,buffer,length);
                Module['_GHL_NetworkEmscripten_onError'](_handler,http.status, buffer);
                _free(buffer);
              }
              delete Browser.wgetRequests[handle];
            };
            http.onerror = function http_onerror(e) {
                var length = lengthBytesUTF8(http.statusText)+1;
                var buffer = Module._malloc(length);
                stringToUTF8(http.statusText,buffer,length);
                Module['_GHL_NetworkEmscripten_onError'](_handler,http.status, buffer);
                _free(buffer);
                delete Browser.wgetRequests[handle];
            };
            http.onabort = function http_onabort(e) {
                delete Browser.wgetRequests[handle];
            };

            var headers_cnt = Module['_GHL_NetworkEmscripten_getHeadersCount'](_handler);
            for (var i=0;i<headers_cnt;i++) {
                var name =  Module['_GHL_NetworkEmscripten_getHeaderName'](_handler,i);
                var value = Module['_GHL_NetworkEmscripten_getHeaderValue'](_handler,i);
                http.setRequestHeader(Pointer_stringify(name),Pointer_stringify(value));
            };

            var data = HEAPU8.subarray($1,$1+$2);
            http.send(data);

            Browser.wgetRequests[handle] = http;
        },handler,data,data_size);

    }

    /// POST request
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        if (!handler)
            return false;
        
        PostBinary(handler,data->GetData(),data->GetSize());
  
        return true;
    }

    virtual bool GHL_CALL PostStream(GHL::NetworkRequest* handler, GHL::DataStream* data) {
         if (!handler)
            return false;
        handler->AddRef();
        std::vector<GHL::Byte> updata;
        if (data) {
            static const size_t CHUNK_SIZE = 1024 * 2;
            while (!data->Eof()) {
                size_t pos = updata.size();
                updata.resize(pos + CHUNK_SIZE);
                size_t readed = data->Read(&updata[pos],CHUNK_SIZE);
                updata.resize(pos + readed);
            }
        }

        PostBinary(handler,updata.data(),updata.size());
        
        return true;
    }

    virtual void GHL_CALL Process() {
        //PROFILE(Process);
        
    }
};

class NetworkEmscriptenFetch : public NetworkEmscripten {
    bool m_fetch_suported;
public:
    NetworkEmscriptenFetch() {
        m_fetch_suported = EM_ASM_INT({
            function isFetchAPIsupported() {
                return 'fetch' in window;
            };
            function isFetchResponseBodySupported() {
                  var response_support = ('Response' in window);
                  if (!response_support ) {
                    return response_support;
                  }
                  var test_response = new Response();
                  var body_support = ('body' in test_response);
                  return body_support; 
            };
            try {
                if (!isFetchAPIsupported()) {
                    console.log('fetch api dnt supported');
                    return 0;
                };
                if (!isFetchResponseBodySupported()) {
                    console.log('fetch response body dnt supported');
                    return 0;
                };
            } catch (e) {
                console.log('failed check response body support');
                return 0;
            };
            console.log('fetch api supported, use it');
            Module.GHL_NetworkEmscripten_fetch = function( _handler, _req ) {
                var _url = Pointer_stringify(Module['_GHL_NetworkEmscripten_getURL'](_handler));
                _req.headers = new Headers();
                var _headers_cnt = Module['_GHL_NetworkEmscripten_getHeadersCount'](_handler);
                for (var i=0;i<_headers_cnt;i++) {
                    var name =  Module['_GHL_NetworkEmscripten_getHeaderName'](_handler,i);
                    var value = Module['_GHL_NetworkEmscripten_getHeaderValue'](_handler,i);
                    _req.headers.append(Pointer_stringify(name),Pointer_stringify(value));
                };
                var onerr = function( e ) {
                  if (_handler != 0) { 
                    var err = ' ' + e; 
                    var length = lengthBytesUTF8(err)+1; 
                    var buffer = Module._malloc(length); 
                    stringToUTF8(err,buffer,length); 
                    Module['_GHL_NetworkEmscripten_onFetchError'](_handler, buffer); 
                    _free(buffer); 
                    _handler = 0; 
                  };
                };
    
                var pump = function( reader ) {
                    return reader.read().then(function(rres) {
                        if (rres.done) {
                            Module['_GHL_NetworkEmscripten_onFetchEnd'](_handler);
                            _handler = 0;
                            return;
                        };
                        const chunk = rres.value; 
                        var buffer = _malloc(chunk.length); 
                        HEAPU8.set(chunk, buffer); 
                        Module['_GHL_NetworkEmscripten_onFetchData'](_handler,buffer,chunk.length); 
                        _free(buffer);
                        return pump(reader);
                    }).catch(onerr);
                };
                fetch(_url,_req)
                    .then(function( res ) {
                        Module['_GHL_NetworkEmscripten_onFetchResponse'](_handler,res.status);
                        res.headers.forEach(function(value, key ) {
                            var length = lengthBytesUTF8(key)+1;
                            var buffer_key = Module._malloc(length);
                            stringToUTF8(key,buffer_key,length);
                            length = lengthBytesUTF8(value)+1;
                            var buffer_value = Module._malloc(length);
                            stringToUTF8(value,buffer_value,length);
                            Module['_GHL_NetworkEmscripten_onFetchHeader'](_handler,buffer_key,buffer_value);
                            _free(buffer_key);
                            _free(buffer_value);
                        });
                        return pump(res.body.getReader());
                    })
                    .catch(onerr);
            };
            return 1;
        });
    }
    virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
       if (!handler)
            return false;
        if (!m_fetch_suported) {
            return NetworkEmscripten::Get(handler);
        }
        handler->AddRef();
        EM_ASM({
            var _handler = $0;
            var _req = {};
            _req.method = 'GET';
            
            Module.GHL_NetworkEmscripten_fetch(_handler,_req);
            
        },handler);
        return true;
    }
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        if (!handler)
            return false;
        if (!m_fetch_suported) {
            return NetworkEmscripten::Post(handler,data);
        }
        handler->AddRef();
        EM_ASM({
            var _handler = $0;
            var _req = {};
            _req.method = 'POST';
            _req.body = HEAPU8.subarray($1,$1+$2);
            Module.GHL_NetworkEmscripten_fetch(_handler,_req);
            
        },handler,data->GetData(),data->GetSize());
  
        return true;
    }
    virtual bool GHL_CALL PostStream(GHL::NetworkRequest* handler, GHL::DataStream* data) {
         if (!handler)
            return false;
        if (!m_fetch_suported) {
            return NetworkEmscripten::PostStream(handler,data);
        }
        handler->AddRef();
        std::vector<GHL::Byte> updata;
        if (data) {
            static const size_t CHUNK_SIZE = 1024 * 2;
            while (!data->Eof()) {
                size_t pos = updata.size();
                updata.resize(pos + CHUNK_SIZE);
                size_t readed = data->Read(&updata[pos],CHUNK_SIZE);
                updata.resize(pos + readed);
            }
        }

        /// @todo read stream from js
        EM_ASM({
            var _handler = $0;
            var _req = {};
            _req.method = 'POST';
            _req.body = HEAPU8.subarray($1,$1+$2);
            Module.GHL_NetworkEmscripten_fetch(_handler,_req);
            
        },handler,updata.data(),updata.size());
        
        return true;
    }
};

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new NetworkEmscriptenFetch();
}


GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* n) {
    delete static_cast<NetworkEmscriptenFetch*>(n);
}