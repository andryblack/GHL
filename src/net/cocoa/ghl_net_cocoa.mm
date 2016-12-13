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
        m_handler->OnResponse(GHL::UInt32(code));
        NSDictionary* headers = ((NSHTTPURLResponse*)response).allHeaderFields;
        for (NSString* key in headers.allKeys) {
            NSString* val = [headers objectForKey:key];
            m_handler->OnHeader([key UTF8String],[val UTF8String]);
        }
    }
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data
{
    m_handler->OnData(static_cast<const GHL::Byte*>(data.bytes), GHL::UInt32(data.length));
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    m_handler->OnComplete();
    [connection release];
    m_handler->Release();
    m_handler = 0;
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error
{
    if (error) {
        const char* err = error.description.UTF8String;
        m_handler->OnError(err);
    } else {
        m_handler->OnError("unknown");
    }
    [connection release];
    m_handler->Release();
    m_handler = 0;
}

- (nullable NSCachedURLResponse *)connection:(NSURLConnection *)connection willCacheResponse:(NSCachedURLResponse *)cachedResponse {
    return nil;
}

-(BOOL)complete
{
    return m_handler!=0;
}

@end

class GHL_Network_Cocoa : public GHL::Network {
private:
    std::list<GHLHttpRequest*> m_requests;
    void clearRequests(bool all=false) {
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
        clearRequests(true);
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
        request.cachePolicy  = NSURLRequestReloadIgnoringLocalCacheData;
        
        GHL::UInt32 heades = handler->GetHeadersCount();
        bool has_encoding = false;
        for (GHL::UInt32 i=0;i<heades;++i) {
            NSString* name = [NSString stringWithUTF8String:handler->GetHeaderName(i)];
            if ([name isEqualToString:@"Accept-Encoding"]) {
                has_encoding = true;
            }
            [request addValue:[NSString stringWithUTF8String:handler->GetHeaderValue(i)]
                forHTTPHeaderField:name];
        }
        if (!has_encoding) {
            [request setValue:@"gzip" forHTTPHeaderField:@"Accept-Encoding"];

        }
        return request;
    }
    
    /// GET request
    virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
        clearRequests(false);
        
        if (!handler)
            return false;
        
        NSMutableURLRequest* req = createRequest( handler );
        if (!req)
            return false;
        
        GHLHttpRequest* request = [[GHLHttpRequest alloc] initWithRequest:handler];
        NSURLConnection* conn = [[NSURLConnection alloc] initWithRequest:req
                                                       delegate:request startImmediately:NO];
        if ( !conn ) {
            [request release];
            return false;
        }
        
        m_requests.push_back(request);
        [conn start];
        return true;
    }
    /// POST request
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        clearRequests(false);
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
            [request release];
            return false;
        }
        
        m_requests.push_back(request);
        [conn start];
        
        return true;
    }
    
    virtual void GHL_CALL Process() {}

};

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new GHL_Network_Cocoa();
}

GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* vfs) {
    delete static_cast<GHL_Network_Cocoa*>(vfs);
}
