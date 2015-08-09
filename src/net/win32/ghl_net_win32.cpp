
#include <ghl_api.h>
#include <ghl_net.h>
#include <ghl_log.h>
#include <ghl_data.h>

#include <iostream>

#include "../../ghl_log_impl.h"

static const char* MODULE = "Net";


class NetworkWin32 : public GHL::Network {
    /// GET request
    virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
        if (!handler)
            return false;
        
        return true;
    }
    /// POST request
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        if (!handler)
            return false;
        return true;
    }

    virtual void GHL_CALL Process() {}
};

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new NetworkWin32();
}


GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* n) {
    delete static_cast<NetworkWin32*>(n);
}