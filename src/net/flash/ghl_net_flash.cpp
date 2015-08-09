
#include <ghl_api.h>
#include <ghl_net.h>
#include <ghl_log.h>
#include <ghl_data.h>

#include <AS3/AS3.h>
#include <Flash++.h>

#include <iostream>

#include "../../ghl_log_impl.h"

static const char* MODULE = "Net";

using namespace AS3::ui;

static var completeHandler(void *arg, var as3Args) {
    flash::events::Event e = var(as3Args[0]);
    flash::net::URLLoader loader = var(e->target);
    AS3::ui::flash::utils::ByteArray ba = var(loader->data);
    GHL::NetworkRequest* handler = (GHL::NetworkRequest*)arg;
    int size = ba->bytesAvailable;
    //LOG_INFO(  "completeEvent: " << size << "bytes" );
    
    GHL::Byte* d = (GHL::Byte*)::malloc(size);
    ba->position = 0;
    ba->readBytes(AS3::ui::internal::get_ram(),(int)d,size,(void*)d);
    handler->OnData(d,size);
    ::free(d);
    
    handler->OnComplete();
    handler->Release();
    return internal::_undefined;
}

static var errorHandler(void *arg, var as3Args) {
    LOG_INFO(  "errorEvent" );
    GHL::NetworkRequest* handler = (GHL::NetworkRequest*)arg;
    
    handler->OnError("IO");
    handler->Release();
    return internal::_undefined;
}


class NetworkFlash : public GHL::Network {
    /// GET request
    virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
        if (!handler)
            return false;
        flash::net::URLRequest urlRequest = flash::net::URLRequest::_new(handler->GetURL());
        urlRequest->method = flash::net::URLRequestMethod::GET;
        flash::net::URLLoader loader = flash::net::URLLoader::_new();
        loader->dataFormat = flash::net::URLLoaderDataFormat::BINARY;
        loader->addEventListener(flash::events::Event::COMPLETE, Function::_new(&completeHandler, handler));
        loader->addEventListener(flash::events::IOErrorEvent::IO_ERROR, Function::_new(&errorHandler, handler));
        handler->AddRef();
        try
        {
            loader->load(urlRequest);
        }
        catch (var e)
        {
            char *err = internal::utf8_toString(e);
            LOG_ERROR(  "failed load url: " << err );
            handler->OnError(err);
            free(err);
            handler->Release();
            return false;
        }
        return true;
    }
    /// POST request
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        if (!handler)
            return false;
        flash::net::URLRequest urlRequest = flash::net::URLRequest::_new(handler->GetURL());
        urlRequest->method = flash::net::URLRequestMethod::POST;
        if (data) {
            AS3::ui::flash::utils::ByteArray ba = AS3::ui::flash::utils::ByteArray::_new();
            ba->endian = AS3::ui::flash::utils::Endian::__LITTLE_ENDIAN;
            ba->writeBytes(
                           AS3::ui::internal::get_ram(), (int)data->GetData(), data->GetSize(), (void*)data->GetData());
            urlRequest->data = ba;
        }
        flash::net::URLLoader loader = flash::net::URLLoader::_new();
        loader->dataFormat = flash::net::URLLoaderDataFormat::BINARY;
        loader->addEventListener(flash::events::Event::COMPLETE, Function::_new(&completeHandler, handler));
        loader->addEventListener(flash::events::IOErrorEvent::IO_ERROR, Function::_new(&errorHandler, handler));
        handler->AddRef();
        try
        {
            loader->load(urlRequest);
        }
        catch (var e)
        {
            char *err = internal::utf8_toString(e);
            LOG_ERROR(  "failed load url: " << err );
            handler->OnError(err);
            free(err);
            handler->Release();
            return false;
        }
        return true;
    }

    virtual void GHL_CALL Process() {}
};

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new NetworkFlash();
}


GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* n) {
    delete static_cast<NetworkFlash*>(n);
}