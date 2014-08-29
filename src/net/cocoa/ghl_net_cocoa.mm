#include "../ghl_net_common.h"
#include "ghl_data.h"
#import <Foundation/Foundation.h>
#include <list>

@interface GHLHttpRequest : NSObject<NSURLConnectionDataDelegate>
{
    GHL::NetworkRequest*     m_handler;
}
@end

@implementation GHLHttpRequest

-(id)initWithRequest:(GHL::NetworkRequest*)request
{
    self = [super init];
    if( self ) {
        request->AddRef();
        m_handler = request;
        return self;
    }
    
    return self;
}

-(void)dealloc
{
    if (m_handler) m_handler->Release();
    [super dealloc];
}



- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response
{
    if ([response isKindOfClass:[NSHTTPURLResponse class]] ) {
        NSInteger code = ((NSHTTPURLResponse*)response).statusCode;
        m_handler->OnResponse(code);
        NSDictionary* headers = ((NSHTTPURLResponse*)response).allHeaderFields;
        for (NSString* key in headers.allKeys) {
            NSString* val = [headers objectForKey:key];
            m_handler->OnHeader([key UTF8String],[val UTF8String]);
        }
    }
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data
{
    m_handler->OnData(static_cast<const GHL::Byte*>(data.bytes), data.length);
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    m_handler->OnComplete();
    [connection release];
    m_handler->Release();
    m_handler = 0;
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error
{
    m_handler->OnError("unknown");
    [connection release];
    m_handler->Release();
    m_handler = 0;
}

-(BOOL)complete
{
    return m_handler!=0;
}

@end

class GHL_Network_Cocoa : public GHL::Network {
private:
    std::list<GHLHttpRequest*> m_requests;
    void cleaRequests(bool all=false) {
        std::list<GHLHttpRequest*>::iterator it = m_requests.begin();
        while (it!=m_requests.end()) {
            if (all || [*it complete]) {
                [*it release];
                it = m_requests.erase(it);
            } else {
                ++it;
            }
        }
    }
public:
    GHL_Network_Cocoa() {
        
    }
    ~GHL_Network_Cocoa() {
        cleaRequests(true);
    }
    
    NSMutableURLRequest* createRequest(GHL::NetworkRequest* handler) {
        
        // construct URL
        const char* inurl = handler->GetURL();
        if (!inurl)
            return NULL;
        NSString* url = [NSString stringWithUTF8String: inurl];
        if ( !url ) {
            return NULL;
        }
        
        NSURL *urlObject = [NSURL URLWithString: url];
        if (!urlObject) {
            return NULL;
        }
        
        NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:urlObject];
        GHL::UInt32 heades = handler->GetHeadersCount();
        for (GHL::UInt32 i=0;i<heades;++i) {
            [request addValue:[NSString stringWithUTF8String:handler->GetHeaderValue(i)]
                forHTTPHeaderField:[NSString stringWithUTF8String:handler->GetHeaderName(i)]];
        }
        return request;
    }
    
    /// GET request
    virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
        cleaRequests(false);
        
        if (!handler)
            return false;
        
        NSMutableURLRequest* req = createRequest( handler );
        if (!req)
            return false;
        
        GHLHttpRequest* request = [[GHLHttpRequest alloc] initWithRequest:handler];
        NSURLConnection* conn = [[NSURLConnection alloc] initWithRequest:req
                                                       delegate:request startImmediately:NO];
        if ( !conn ) {
            return false;
        }
        
        m_requests.push_back(request);
        [conn start];
        return true;
    }
    /// POST request
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        cleaRequests(false);
        if (!handler)
            return false;
        if (!data)
            return false;
        
        
        NSMutableURLRequest* req = createRequest( handler );
        if (!req)
            return false;
        req.HTTPMethod = @"POST";
        req.HTTPBody = [NSData dataWithBytes:data->GetData() length:data->GetSize()];
        GHLHttpRequest* request = [[GHLHttpRequest alloc] initWithRequest:handler];
        NSURLConnection* conn = [[NSURLConnection alloc] initWithRequest:req
                                                                delegate:request startImmediately:NO];
        if ( !conn ) {
            return false;
        }
        
        m_requests.push_back(request);
        [conn start];
        
        return true;
    }

};

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new GHL_Network_Cocoa();
}

GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* vfs) {
    delete static_cast<GHL_Network_Cocoa*>(vfs);
}
