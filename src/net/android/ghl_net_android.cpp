
#include <ghl_api.h>
#include <ghl_net.h>
#include <ghl_log.h>
#include <ghl_data.h>
#include <android/native_activity.h>
#include <jni.h>
#include <assert.h>
#include <iostream>
#include <list>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "../../ghl_log_impl.h"
#include <ghl_data_stream.h>

static const char* MODULE = "Net";

namespace GHL {
    extern ANativeActivity* g_native_activity;
}

struct slock {
    pthread_mutex_t& m;
    slock(pthread_mutex_t& m) : m(m) {
        pthread_mutex_lock(&m);
    }
    ~slock() {
        pthread_mutex_unlock(&m);
    }
};

struct time_profile {
    clock_t start;
    const char* name;
    explicit time_profile(const char* name) : name(name) {
        start = clock();
    }
    ~time_profile() {
        clock_t t = clock() - start;
        ILOG_INFO(name << " spent " << t);
    }
};
#define PROFILE(name) time_profile name(#name);

GHL_API jstring GHL_CALL GHL_JNI_CreateStringUTF8(JNIEnv* env,const char* str);

struct jni_string
{
    jstring jstr;
    JNIEnv* env;
    explicit jni_string(const char* str, JNIEnv* env) : env(env) {
        jstr = GHL_JNI_CreateStringUTF8(env,str);
    }
    explicit jni_string(jobject obj, JNIEnv* env) : jstr((jstring)obj),env(env){
    }
    ~jni_string() {
        env->DeleteLocalRef( jstr );
    }

    static std::string extract( const jstring jstr , JNIEnv* env ) {
        if ( !jstr ) {
            LOG_ERROR("jni_string::extract general error:" << jstr);
            return std::string();
        }
        jsize size = env->GetStringUTFLength( jstr );
        if( size == 0 ) {
            return std::string();
        }
        jboolean is_copy = JNI_FALSE;
        const char* psz  = env->GetStringUTFChars( jstr, &is_copy );
        if ( !psz ) {
            LOG_ERROR( "jni_string::extract fault");
            return std::string();
        }
        
        std::string result( psz, size );
        env->ReleaseStringUTFChars( jstr, psz );

        return result;
    }
    std::string str() { return extract(jstr,env);}
};

struct jni_object
{
    jobject jobj;
    JNIEnv* env;
    explicit jni_object(jobject obj,JNIEnv* env) : jobj(obj),env(env) {
    }
    ~jni_object() {
        if(jobj) env->DeleteLocalRef( jobj );
    }
};
struct jni_global_object
{
    jobject jobj;
    JNIEnv* env;
    explicit jni_global_object(jobject obj,JNIEnv* env) : jobj(obj),env(env) {
        if (jobj) jobj = env->NewGlobalRef(jobj);
    }
    ~jni_global_object() {
        if (jobj) {
            env->DeleteGlobalRef( jobj );
        }
    }
};

static std::string jni_object_to_string(jobject obj,JNIEnv* env)
{
    jni_object clazz(env->GetObjectClass(obj),env);
    jmethodID getMessageID__ = env->GetMethodID((jclass)clazz.jobj, "toString", "()Ljava/lang/String;");
    if(getMessageID__)
    {
        jni_string jmsg(env->CallObjectMethod(obj, getMessageID__),env);
        return jmsg.str();
    }
    return "not found toString";
}

static bool check_exception( JNIEnv* env ) {
    if (env->ExceptionCheck()) {
        jthrowable t__ = env->ExceptionOccurred();
        if (!t__) { 
            LOG_ERROR("not found exception"); 
        } else { \
           env->ExceptionClear();
           LOG_ERROR("details: " << jni_object_to_string(t__,env)); 
           env->DeleteLocalRef(t__);
        } 
        return true;
    }
    return false;
} 
static const size_t BUFFER_SIZE = 1024*128;

class NetworkTaskBase {
public:
    static jclass  m_URL_class;
    static jmethodID m_URL_ctr;
    static jmethodID m_URL_openConnection;
    
    static jmethodID  m_HttpURLConnection_setDoOutput;
    static jmethodID  m_HttpURLConnection_connect;
    static jmethodID  m_HttpURLConnection_setRequestProperty;
    static jmethodID  m_HttpURLConnection_getResponseCode;
    static jmethodID  m_HttpURLConnection_getHeaderFieldKey;
    static jmethodID  m_HttpURLConnection_getHeaderField;
    static jmethodID  m_HttpURLConnection_setChunkedStreamingMode;
    static jmethodID  m_HttpURLConnection_setInstanceFollowRedirects;
    static jmethodID  m_HttpURLConnection_getOutputStream;
    static jmethodID  m_HttpURLConnection_getInputStream;
    static jmethodID  m_HttpURLConnection_getErrorStream;
    static jmethodID  m_HttpURLConnection_disconnect;

    static jmethodID  m_InputStream_read;
    static jmethodID  m_OutputStream_write;
protected:
    std::string             m_url;
    jni_global_object       m_connection;
    GHL::NetworkRequest*    m_handler;
    jni_global_object       m_buffer;
    size_t                  m_buffer_size;
    enum state_t {
        S_INIT,
        S_CONNECT,
        S_WRITE,
        S_WRITE_MORE,
        S_READ,
        S_COMPLETE,
        S_ERROR,
    } m_state;
    std::string m_error;
    int m_response_code;
    GHL::UInt32 m_headers_count;
    bool    m_response_received;

    explicit NetworkTaskBase(JNIEnv* env,GHL::NetworkRequest* handler) : m_connection(0,env),
        m_handler(handler),m_buffer(0,env),m_response_code(0) {
        //PROFILE(NetworkTask_ctr);
        m_handler->AddRef();
        m_state = S_INIT;
        m_headers_count = m_handler->GetHeadersCount();
        m_response_received = false;
        m_buffer_size = 0;
        jobject buf_loc = env->NewByteArray(BUFFER_SIZE);
        m_buffer.jobj = env->NewGlobalRef(buf_loc);
        m_url = handler->GetURL();
        env->DeleteLocalRef(buf_loc);
    }
public:
    virtual ~NetworkTaskBase() {
         m_handler->Release();
    }
    bool IsComplete() {
        return m_state == S_COMPLETE || m_state == S_ERROR;
    }

    bool DoRead(JNIEnv* env) {
        //PROFILE(ProcessBackground_S_READ);
        bool is_success = (m_response_code == 0) || (
            m_response_code < 400);
        jni_object read_stream(env->CallObjectMethod(m_connection.jobj,
            is_success ? m_HttpURLConnection_getInputStream : m_HttpURLConnection_getErrorStream),env);
        if (check_exception(env)) {
            m_state = S_ERROR;
            m_error = "getInputStream failed";
            return true;
        } 
        int readed = env->CallIntMethod(read_stream.jobj,m_InputStream_read,m_buffer.jobj,m_buffer_size,BUFFER_SIZE-m_buffer_size);
        //ILOG_INFO("readed " << readed);
        if (check_exception(env) || !read_stream.jobj) {
            m_state = S_ERROR;
            m_error = "read failed";
            return true;
        } 
        if (readed == -1) {
            //ILOG_INFO("S_READ->S_COMPLETE");
            m_state = S_COMPLETE;
            return true;
        } else {
            m_buffer_size += readed;
            if (m_buffer_size>=BUFFER_SIZE) {
                //ILOG_INFO("buffer full");
                return true;
            }
        }
        return false;
    }

    bool ProcessBackground( JNIEnv* env ) {
        switch (m_state) {
            case S_INIT: {
                jni_string url_str(m_url.c_str(),env);
                jni_object url(env->NewObject(m_URL_class,m_URL_ctr,url_str.jstr),env);
                if (check_exception(env)) {
                    m_state = S_ERROR;
                    //ILOG_INFO("S_INIT->S_ERROR 1");
                    m_error = "create url failed";
                    return true;
                }
                jni_object connection(env->CallObjectMethod(url.jobj,m_URL_openConnection),env);
                if (check_exception(env)) {
                    m_state = S_ERROR;
                    //ILOG_INFO("S_INIT->S_ERROR 1");
                    m_error = "open connection failed";
                    return true;
                }
                m_connection.jobj = env->NewGlobalRef(connection.jobj);
                env->CallVoidMethod(m_connection.jobj,m_HttpURLConnection_setInstanceFollowRedirects,JNI_TRUE);
                if (m_headers_count == 0) {
                    UpdateInitState();
                    return false;
                }
                return true;
            } break;
            case S_WRITE: {
                env->CallVoidMethod(m_connection.jobj,m_HttpURLConnection_setDoOutput,JNI_TRUE);
                if (check_exception(env)) {
                    m_state = S_ERROR;
                    //ILOG_INFO("S_WRITE->S_ERROR 1");
                    m_error = "set output failed";
                    return true;
                }
                if (!ConfigureStream(env)) {
                    return true;
                }
                jni_object out_stream(env->CallObjectMethod(m_connection.jobj,m_HttpURLConnection_getOutputStream),env);
                if (check_exception(env)) {
                    m_state = S_ERROR;
                    //ILOG_INFO("S_WRITE->S_ERROR 2");
                    m_error = "getOutputStream failed";
                    return true;
                }
                if (ProcessWriteStream(env,out_stream)) {
                    return true;
                } else {
                    return false;
                }
                
            } break;
            case S_WRITE_MORE: {
                jni_object out_stream(env->CallObjectMethod(m_connection.jobj,m_HttpURLConnection_getOutputStream),env);
                if (check_exception(env)) {
                    m_state = S_ERROR;
                    //ILOG_INFO("S_WRITE->S_ERROR 2");
                    m_error = "getOutputStream failed";
                    return true;
                }
                if (ProcessWriteStream(env,out_stream)) {
                    return true;
                } else {
                    return false;
                }
            } break;
            case S_CONNECT: {
                env->CallVoidMethod(m_connection.jobj,m_HttpURLConnection_connect);
                if (check_exception(env)) {
                    m_state = S_ERROR;
                    //ILOG_INFO("S_CONNECT->S_ERROR");
                    m_error = "connect failed";
                    return true;
                } 
                m_response_code = env->CallIntMethod(m_connection.jobj,m_HttpURLConnection_getResponseCode);
                if (check_exception(env)) {
                    m_state = S_ERROR;
                    //ILOG_INFO("S_CONNECT->S_ERROR");
                    m_error = "get response code failed";
                    return true;
                }
                m_response_received = true;
                m_state = S_READ;
                if (DoRead(env)) {
                    return true;
                }
            } break;
            case S_READ: {
                if (DoRead(env)) {
                    return true;
                }
            } break;
            case S_ERROR: {
                return true;
            } break;
        }     
        return false;
    }


    void FlushData(JNIEnv* env) {
        if (m_buffer_size) {
            //ILOG_INFO("flush " << m_buffer_size);
            //PROFILE(FlushData);
            jboolean is_copy = JNI_FALSE;
            jbyte* data = (env->GetByteArrayElements((jbyteArray)m_buffer.jobj,&is_copy));
            m_handler->OnData(reinterpret_cast<GHL::Byte*>(data),m_buffer_size);
            env->ReleaseByteArrayElements((jbyteArray)m_buffer.jobj,data,JNI_ABORT);
            m_buffer_size = 0;
        }
    }

   
    bool ProcessMain(JNIEnv* env) {
        //PROFILE(ProcessMain)
        if (m_response_received) {
            m_handler->OnResponse(m_response_code);
            for (int j = 1; ; j++) {
                jni_string key( env->CallObjectMethod(m_connection.jobj,m_HttpURLConnection_getHeaderFieldKey,j) ,env );
                jni_string value( env->CallObjectMethod(m_connection.jobj,m_HttpURLConnection_getHeaderField,j)  ,env);
                if (!key.jstr || !value.jstr) break;
                m_handler->OnHeader(key.str().c_str(),value.str().c_str());
            }  // end for
            m_response_received = false;
        }
        switch (m_state) {
            case S_INIT: {

                GHL::UInt32 count = m_handler->GetHeadersCount();
                for (GHL::UInt32 i = 0;i<count; ++i) {
                    jni_string name_str(m_handler->GetHeaderName(i),env);
                    jni_string value_str(m_handler->GetHeaderValue(i),env);
                    env->CallVoidMethod(m_connection.jobj,m_HttpURLConnection_setRequestProperty,
                        name_str.jstr,value_str.jstr);
                }

                UpdateInitState();

                return true;

            } break;
            case S_READ: {
                //PROFILE(ProcessMainS_READ);
                FlushData(env);
                return true;
            } break;
            case S_COMPLETE: {
                //PROFILE(ProcessMainS_COMPLETE);
                FlushData(env);
                m_handler->OnComplete(); 
                return true;
            }
            case S_ERROR: {
                //PROFILE(ProcessMainS_ERROR);
                LOG_ERROR(m_error);
                m_handler->OnError(m_error.c_str());
                m_handler->OnComplete();
                return true;
            }
        }
        return false;
    }
    virtual void UpdateInitState() = 0;
    virtual bool ConfigureStream(JNIEnv* env) { return true; }
    virtual bool ProcessWriteStream(JNIEnv* env,jni_object& stream) = 0;
};

class NetworkTask : public NetworkTaskBase {
public:
    
private:
    
    const GHL::Data*  m_send_data;
    
public:
    explicit NetworkTask(JNIEnv* env,GHL::NetworkRequest* handler,
        const GHL::Data* send_data) : NetworkTaskBase(env,handler),m_send_data(send_data) {
        if (m_send_data) {
            m_send_data->AddRef();
        }
    }
    
    ~NetworkTask() {
        if (m_send_data) {
            m_send_data->Release();
        }
    }

    void UpdateInitState() {
        if (m_send_data) {
            //ILOG_INFO("S_INIT->S_WRITE");
            m_state = S_WRITE;
        } else {
            //ILOG_INFO("S_INIT->S_CONNECT");
            m_state = S_CONNECT;
        }
    }

    bool ProcessWriteStream(JNIEnv* env,jni_object& out_stream) {
        jbyteArray arr = env->NewByteArray(m_send_data->GetSize());
        if (check_exception(env)) {
            m_state = S_ERROR;
            //ILOG_INFO("S_WRITE->S_ERROR 3");
            m_error = "create byte array failed";
            return true;
        }
        env->SetByteArrayRegion(arr,0,m_send_data->GetSize(),
            reinterpret_cast<const jbyte*>(m_send_data->GetData()));
        env->CallVoidMethod(out_stream.jobj,m_OutputStream_write,arr);
        env->DeleteLocalRef(arr);
        if (check_exception(env)) {
            m_state = S_ERROR;
            //ILOG_INFO("S_WRITE->S_ERROR 4");
            m_error = "send failed";
            return true;
        } 
        //PROFILE(ProcessBackground_S_WRITE_S_CONNECT);
        //ILOG_INFO("S_WRITE->S_CONNECT");
        m_state = S_CONNECT;
        return false;
    }
};

class NetworkStreamTask : public NetworkTaskBase {
public:
    
private:
    
    GHL::DataStream*  m_send_data;
    jni_global_object m_out_buffer;
    GHL::Byte m_out_raw_buffer[BUFFER_SIZE];
public:
    explicit NetworkStreamTask(JNIEnv* env,GHL::NetworkRequest* handler,
        GHL::DataStream* send_data) : NetworkTaskBase(env,handler),m_send_data(send_data),m_out_buffer(0,env) {
        if (m_send_data) {
            m_send_data->AddRef();
        }
        jobject buf_loc = env->NewByteArray(BUFFER_SIZE);
        m_out_buffer.jobj = env->NewGlobalRef(buf_loc);
        env->DeleteLocalRef(buf_loc);
    }
    
    ~NetworkStreamTask() {
        if (m_send_data) {
            m_send_data->Release();
        }
    }

    void UpdateInitState() {
        m_state = S_WRITE;
    }

    virtual bool ConfigureStream(JNIEnv* env) { 
        env->CallVoidMethod(m_connection.jobj,m_HttpURLConnection_setChunkedStreamingMode,(jint)BUFFER_SIZE);
        if (check_exception(env)) {
            m_state = S_ERROR;
            //ILOG_INFO("S_WRITE->S_ERROR 1");
            m_error = "set chunked failed";
            return false;
        }
        return true;
    }

    virtual bool ProcessWriteStream(JNIEnv* env,jni_object& out_stream) {
        GHL::UInt32 readed = m_send_data->Read(m_out_raw_buffer,BUFFER_SIZE);
        if (readed) {
            env->SetByteArrayRegion((jbyteArray)m_out_buffer.jobj,0,readed,
                reinterpret_cast<const jbyte*>(m_out_raw_buffer));
            env->CallVoidMethod(out_stream.jobj,m_OutputStream_write,m_out_buffer.jobj);

            if (check_exception(env)) {
                m_state = S_ERROR;
                //ILOG_INFO("S_WRITE->S_ERROR 4");
                m_error = "send failed";
                return true;
            } 
            m_state = S_WRITE_MORE;
            return true;
        } 
        //PROFILE(ProcessBackground_S_WRITE_S_CONNECT);
        //ILOG_INFO("S_WRITE->S_CONNECT");
        m_state = S_CONNECT;
        return false;
    }
};

static JavaVM* jvm = 0;
static jmethodID get_method(JNIEnv* env,jclass c,const char* name,const char* sign) {
    jmethodID m = env->GetMethodID(c,name,sign); 
    if (check_exception(env)) {
        return 0;
    }
    return m;
}

#define THREADS_POOL_SIZE 4

class NetworkAndroid : public GHL::Network {
private:
    std::list<NetworkTaskBase*> m_to_bg_tasks;
    std::list<NetworkTaskBase*> m_to_fg_tasks;
    size_t  m_num_requests;
    
    pthread_mutex_t m_lock;
    pthread_mutex_t m_list_lock;
    
    pthread_t       m_threads[THREADS_POOL_SIZE];
    size_t          m_num_threads;
    bool m_stop;
public:
    NetworkAndroid() {
        LOG_INFO("NetworkAndroid");
        assert(GHL::g_native_activity);
        JNIEnv* env = GHL::g_native_activity->env;
        if (check_exception(env)) {
            LOG_INFO("clear pending exception");
        }
        NetworkTaskBase::m_URL_class = (jclass)env->NewGlobalRef((jobject)env->FindClass("java/net/URL"));
        NetworkTaskBase::m_URL_ctr = get_method(env,NetworkTaskBase::m_URL_class,"<init>","(Ljava/lang/String;)V"); 
        assert(NetworkTaskBase::m_URL_ctr);
        NetworkTaskBase::m_URL_openConnection = get_method(env,NetworkTaskBase::m_URL_class,"openConnection","()Ljava/net/URLConnection;"); 
        assert(NetworkTask::m_URL_openConnection);

        jclass HttpURLConnection_class = env->FindClass("java/net/HttpURLConnection");
        NetworkTaskBase::m_HttpURLConnection_setDoOutput = get_method(env,HttpURLConnection_class,"setDoOutput","(Z)V");
        assert(NetworkTaskBase::m_HttpURLConnection_setDoOutput);
        NetworkTaskBase::m_HttpURLConnection_connect = get_method(env,HttpURLConnection_class,"connect","()V");
        assert(NetworkTaskBase::m_HttpURLConnection_connect);
        NetworkTaskBase::m_HttpURLConnection_disconnect = get_method(env,HttpURLConnection_class,"disconnect","()V");
        assert(NetworkTaskBase::m_HttpURLConnection_disconnect);
        NetworkTaskBase::m_HttpURLConnection_setChunkedStreamingMode = get_method(env,HttpURLConnection_class,"setChunkedStreamingMode","(I)V");
        assert(NetworkTaskBase::m_HttpURLConnection_setChunkedStreamingMode);
        NetworkTaskBase::m_HttpURLConnection_setInstanceFollowRedirects = get_method(env,HttpURLConnection_class,"setInstanceFollowRedirects","(Z)V");
        assert(NetworkTaskBase::m_HttpURLConnection_setInstanceFollowRedirects);
        NetworkTaskBase::m_HttpURLConnection_getInputStream = get_method(env,HttpURLConnection_class,"getInputStream","()Ljava/io/InputStream;");
        assert(NetworkTaskBase::m_HttpURLConnection_getInputStream);
        NetworkTaskBase::m_HttpURLConnection_getOutputStream = get_method(env,HttpURLConnection_class,"getOutputStream","()Ljava/io/OutputStream;");
        assert(NetworkTaskBase::m_HttpURLConnection_getOutputStream);
        NetworkTaskBase::m_HttpURLConnection_getErrorStream = get_method(env,HttpURLConnection_class,"getErrorStream","()Ljava/io/InputStream;");
        assert(NetworkTaskBase::m_HttpURLConnection_getErrorStream);
        NetworkTaskBase::m_HttpURLConnection_getHeaderFieldKey = get_method(env,HttpURLConnection_class,"getHeaderFieldKey","(I)Ljava/lang/String;");
        assert(NetworkTaskBase::m_HttpURLConnection_getHeaderFieldKey);
        NetworkTaskBase::m_HttpURLConnection_getHeaderField = get_method(env,HttpURLConnection_class,"getHeaderField","(I)Ljava/lang/String;");
        assert(NetworkTaskBase::m_HttpURLConnection_getHeaderField);
        NetworkTaskBase::m_HttpURLConnection_setRequestProperty = get_method(env,HttpURLConnection_class,"setRequestProperty","(Ljava/lang/String;Ljava/lang/String;)V");
        assert(NetworkTaskBase::m_HttpURLConnection_setRequestProperty);
        NetworkTaskBase::m_HttpURLConnection_getResponseCode = get_method(env,HttpURLConnection_class,"getResponseCode","()I");
        assert(NetworkTaskBase::m_HttpURLConnection_getResponseCode);
        if (check_exception(env)) {
            LOG_INFO("exception on get method");
            assert(false);
        }
        jclass InputStream = env->FindClass("java/io/InputStream");
        assert(InputStream);
        NetworkTaskBase::m_InputStream_read = get_method(env,InputStream,"read","([BII)I");
        assert(NetworkTask::m_InputStream_read);
        env->DeleteLocalRef(InputStream);

        jclass OutputStream = env->FindClass("java/io/OutputStream");
        assert(OutputStream);
        NetworkTaskBase::m_OutputStream_write = get_method(env,OutputStream,"write","([B)V");
        assert(NetworkTaskBase::m_OutputStream_write);
        env->DeleteLocalRef(OutputStream);

        env->DeleteLocalRef(HttpURLConnection_class);

        pthread_mutex_init( &m_lock, NULL );
        pthread_mutex_init( &m_list_lock, NULL );
        m_stop = false;
        env->GetJavaVM(&jvm);
        memset(m_threads,0,sizeof(m_threads));
        m_num_threads = 1;
        m_num_requests = 0;
        pthread_create( &m_threads[0], 0, thread_thunk, this );
    }
    ~NetworkAndroid() {
        LOG_INFO("~NetworkAndroid");
        assert(GHL::g_native_activity);
        JNIEnv* env = GHL::g_native_activity->env;
        env->DeleteGlobalRef(NetworkTaskBase::m_URL_class);
        
        {
            slock l(m_lock);
            m_stop = true;
        }
        for (size_t i=0;i<m_num_threads;++i) {
            if (m_threads[i])
                pthread_join( m_threads[i], 0 );
        }
        for (std::list<NetworkTaskBase*>::iterator it = m_to_bg_tasks.begin();it!=m_to_bg_tasks.end();++it) {
            delete *it;
        }
        for (std::list<NetworkTaskBase*>::iterator it = m_to_fg_tasks.begin();it!=m_to_fg_tasks.end();++it) {
            delete *it;
        }
        pthread_mutex_destroy( &m_lock );
        pthread_mutex_destroy( &m_list_lock );
    }
    void StartNewThread() {
        if (m_num_threads < THREADS_POOL_SIZE) {
            //ILOG_INFO("start new thread:" << m_num_threads+1);
            pthread_create( &m_threads[m_num_threads], 0, thread_thunk, this );
            ++m_num_threads;
        }
    }
    /// GET request
    virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
        if (!handler)
            return false;
        //PROFILE(Get);
        JNIEnv* env = GHL::g_native_activity->env;
        {
            slock l(m_list_lock);
            ++m_num_requests;
            //ILOG_INFO("add request:" << m_num_requests);
            m_to_bg_tasks.push_back(new NetworkTask(env,handler,0));
        }
        return true;
    }
    /// POST request
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        if (!handler)
            return false;
        //PROFILE(Post);
        JNIEnv* env = GHL::g_native_activity->env;
        
        {
            //PROFILE(Post_m_list_lock);
            slock l(m_list_lock);
            ++m_num_requests;
            //ILOG_INFO("add request:" << m_num_requests);
            m_to_bg_tasks.push_back(new NetworkTask(env,handler,data));
        }
        return true;
    }

    virtual bool GHL_CALL PostStream(GHL::NetworkRequest* handler, GHL::DataStream* data) {
        if (!handler)
            return false;
        if (!data)
            return false;
        JNIEnv* env = GHL::g_native_activity->env;
        {
            //PROFILE(Post_m_list_lock);
            slock l(m_list_lock);
            ++m_num_requests;
            //ILOG_INFO("add request:" << m_num_requests);
            m_to_bg_tasks.push_back(new NetworkStreamTask(env,handler,data));
        }
        
        return true;
    }
    virtual void GHL_CALL Process() {
        //PROFILE(Process);
        JNIEnv* env = GHL::g_native_activity->env;
        std::list<NetworkTaskBase*> fg_tasks;
        {
            slock l(m_list_lock);
            fg_tasks.swap(m_to_fg_tasks);
            if (m_to_bg_tasks.size() > m_num_threads) {
                StartNewThread();
            } 
        }
        
        for (std::list<NetworkTaskBase*>::iterator it = fg_tasks.begin();it!=fg_tasks.end();++it) {
            if ((*it)->ProcessMain(env)) {
                if ((*it)->IsComplete()) {
                    slock l(m_list_lock);
                    assert(m_num_requests);
                    --m_num_requests;
                    //ILOG_INFO("stop request:" << m_num_requests);
                    //ILOG_INFO("fg->delete");
                    delete *it;
                } else {
                    //ILOG_INFO("fg->to_bg");
                    slock l(m_list_lock);
                    m_to_bg_tasks.push_back(*it);
                }
            } else {
                slock l(m_list_lock);
                m_to_fg_tasks.push_back(*it);
            }
        }
    }

    bool ProcessBackground(JNIEnv* env,int& counter) {
        NetworkTaskBase* task = 0;
        {
            slock l(m_list_lock);
            if (!m_to_bg_tasks.empty()) {
                task = m_to_bg_tasks.front();
                m_to_bg_tasks.pop_front();
                counter = 1000;
            } else {
                // terminate pool threads on idle 1s
                pthread_t self = pthread_self();
                if ((m_num_threads >1) && 
                    (self == m_threads[m_num_threads-1]) && 
                    (m_num_requests==0)) {
                    if (--counter < 0) {
                        //ILOG_INFO("stop thread:" << m_num_threads-1);
                        --m_num_threads;
                        return true;
                    }
                }
            }
        }
        if (task) {
            if (task->ProcessBackground(env)) {
                slock l(m_list_lock);
                m_to_fg_tasks.push_back(task);
            } else {
                slock l(m_list_lock);
                m_to_bg_tasks.push_back(task);
                return false;
            }
        }
        {
            slock s(m_lock);
            if (m_stop) {
                return true;
            }
        }
        usleep(1000);
        return false;
    }
    static void *thread_thunk( void *arg ) {
        JNIEnv* env = 0;
        pthread_setname_np(pthread_self(),"GHL_Network");

        jvm->AttachCurrentThread(&env,0);

        int counter = 1000;
        while (true) {
            if (static_cast<NetworkAndroid*>(arg)->ProcessBackground(env,counter)) {
                break;
            }
        }

        jvm->DetachCurrentThread();
        return 0;
    }
};

jclass     NetworkTaskBase::m_URL_class = 0;
jmethodID  NetworkTaskBase::m_URL_ctr = 0;
jmethodID  NetworkTaskBase::m_URL_openConnection = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_setDoOutput = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_connect = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_setRequestProperty = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_getResponseCode = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_getHeaderFieldKey = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_getHeaderField = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_setChunkedStreamingMode = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_setInstanceFollowRedirects = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_getOutputStream = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_getInputStream = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_getErrorStream = 0;
jmethodID  NetworkTaskBase::m_HttpURLConnection_disconnect = 0;
jmethodID  NetworkTaskBase::m_InputStream_read = 0;
jmethodID  NetworkTaskBase::m_OutputStream_write = 0;

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new NetworkAndroid();
}


GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* n) {
    delete static_cast<NetworkAndroid*>(n);
}