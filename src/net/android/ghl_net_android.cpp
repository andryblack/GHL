
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

#include "../../ghl_log_impl.h"

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

struct jni_string
{
    jstring jstr;
    JNIEnv* env;
    explicit jni_string(const char* str, JNIEnv* env) : env(env) {
        jstr = env->NewStringUTF( str );
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
    jclass clazz = env->GetObjectClass(obj);
    if (!clazz) return "not found class";
    jmethodID getMessageID__ = env->GetMethodID(clazz, "toString", "()Ljava/lang/String;");
    if(getMessageID__)
    {
        jstring jmsg__ = (jstring) env->CallObjectMethod(obj, getMessageID__);
        if (jmsg__) {
           return jni_string::extract(jmsg__,env);
        }
        return "empty toString result";
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
        } 
        return true;
    }
    return false;
} 
static const size_t BUFFER_SIZE = 256;

class NetworkTask {
public:
    static jmethodID  m_HttpURLConnection_setDoOutput;
    static jmethodID  m_HttpURLConnection_connect;
    static jmethodID  m_HttpURLConnection_setRequestProperty;
    static jmethodID  m_HttpURLConnection_getResponseCode;
    static jmethodID  m_HttpURLConnection_getHeaderFieldKey;
    static jmethodID  m_HttpURLConnection_getHeaderField;
    static jmethodID  m_HttpURLConnection_getOutputStream;
    static jmethodID  m_HttpURLConnection_getInputStream;
    static jmethodID  m_HttpURLConnection_disconnect;
    static jmethodID  m_InputStream_read;
    static jmethodID  m_OutputStream_write;
private:
    jni_global_object       m_connection;
    GHL::NetworkRequest*    m_handler;
    jni_global_object       m_buffer;
    size_t                  m_buffer_size;
    enum state_t {
        S_CONNECT,
        S_RESPONSE,
        S_RESPONSE_R,
        S_WRITE,
        S_READ,
        S_READ_R,
        S_COMPLETE,
        S_ERROR,
    } m_state;
    std::string m_error;
    GHL::Data*  m_send_data;
    pthread_mutex_t&     m_lock;
public:
    explicit NetworkTask(JNIEnv* env,jobject conn,GHL::NetworkRequest* handler,
         GHL::Data* send_data,pthread_mutex_t& m) : m_connection(conn,env),
        m_handler(handler),m_buffer(0,env),m_send_data(send_data),m_lock(m) {
        m_handler->AddRef();
        m_state = S_CONNECT;
        GHL::UInt32 count = m_handler->GetHeadersCount();
        for (GHL::UInt32 i = 0;i<count; ++i) {
            jni_string name_str(m_handler->GetHeaderName(i),env);
            jni_string value_str(m_handler->GetHeaderValue(i),env);
            env->CallVoidMethod(m_connection.jobj,m_HttpURLConnection_setRequestProperty,
                name_str.jstr,value_str.jstr);
        }
        m_buffer_size = 0;
        m_buffer.jobj = env->NewGlobalRef(env->NewByteArray(BUFFER_SIZE));

        if (m_send_data) {
            m_send_data->AddRef();
            m_state = S_WRITE;
        }
    }
    ~NetworkTask() {
        m_handler->Release();
        if (m_send_data) {
            m_send_data->Release();
        }
    }
    bool ProcessBackground( JNIEnv* env ) {
        state_t s;
        {
            slock l(m_lock);
            s = m_state;
        }
        switch (s) {
            case S_WRITE: {
                env->CallVoidMethod(m_connection.jobj,m_HttpURLConnection_setDoOutput,JNI_TRUE);
                if (check_exception(env)) {
                    slock l(m_lock);
                    m_state = S_ERROR;
                    m_error = "set output failed";
                    return true;
                }
                jni_object out_stream(env->CallObjectMethod(m_connection.jobj,m_HttpURLConnection_getOutputStream),env);
                if (check_exception(env)) {
                    slock l(m_lock);
                    m_state = S_ERROR;
                    m_error = "getOutputStream failed";
                    return true;
                }
                jbyteArray arr = env->NewByteArray(m_send_data->GetSize());
                if (check_exception(env)) {
                    slock l(m_lock);
                    m_state = S_ERROR;
                    m_error = "create byte array failed";
                    return true;
                }
                env->SetByteArrayRegion(arr,0,m_send_data->GetSize(),
                    reinterpret_cast<const jbyte*>(m_send_data->GetData()));
                env->CallVoidMethod(out_stream.jobj,m_OutputStream_write,arr);
                env->DeleteLocalRef(arr);
                if (check_exception(env)) {
                    slock l(m_lock);
                    m_state = S_ERROR;
                    m_error = "send failed";
                    return true;
                } else {
                    slock l(m_lock);
                    m_state = S_CONNECT;
                }
            } break;
            case S_CONNECT: {
                env->CallVoidMethod(m_connection.jobj,m_HttpURLConnection_connect);
                if (check_exception(env)) {
                    slock l(m_lock);
                    m_state = S_ERROR;
                    m_error = "connect failed";
                    return true;
                } else {
                    slock l(m_lock);
                    m_state = S_RESPONSE;
                }
            } break;
            case S_RESPONSE_R: {
                {
                    slock l(m_lock);
                    m_state = S_READ;
                }
            };
            case S_READ: {
                jni_object read_stream(env->CallObjectMethod(m_connection.jobj,m_HttpURLConnection_getInputStream),env);
                if (check_exception(env)) {
                    slock l(m_lock);
                    m_state = S_ERROR;
                    m_error = "getInputStream failed";
                    return true;
                } 
                int readed = env->CallIntMethod(read_stream.jobj,m_InputStream_read,m_buffer.jobj,m_buffer_size,BUFFER_SIZE-m_buffer_size);
                //LOG_INFO("readed " << readed);
                if (check_exception(env)) {
                    slock l(m_lock);
                    m_state = S_ERROR;
                    m_error = "read failed";
                    return true;
                } 
                if (readed == -1) {
                    slock l(m_lock);
                    m_state = S_COMPLETE;
                    return true;
                } else {
                    slock l(m_lock);
                    m_buffer_size += readed;
                    if (m_buffer_size>=BUFFER_SIZE) {
                        //LOG_INFO("buffer full");
                        m_state = S_READ_R;
                    }
                }
            } break;
        }     
        return false;
    }

    void FlushData(JNIEnv* env) {
        if (m_buffer_size) {
            //LOG_INFO("flush " << m_buffer_size);
            jboolean is_copy = JNI_FALSE;
            jbyte* data = (env->GetByteArrayElements((jbyteArray)m_buffer.jobj,&is_copy));
            m_handler->OnData(reinterpret_cast<GHL::Byte*>(data),m_buffer_size);
            env->ReleaseByteArrayElements((jbyteArray)m_buffer.jobj,data,JNI_ABORT);
            m_buffer_size = 0;
        }
    }

    bool ProcessMain(JNIEnv* env) {
        state_t s;
        {
            slock l(m_lock);
            s = m_state;
        }
        switch (s) {
            case S_RESPONSE: {
                slock l(m_lock);
                int response_code = env->CallIntMethod(m_connection.jobj,m_HttpURLConnection_getResponseCode);
                if (check_exception(env)) {
                    m_state = S_ERROR;
                    m_error = "get response code failed";
                    return false;
                }
                m_handler->OnResponse(response_code);
                for (int j = 1; ; j++) {
                    jni_string key( env->CallObjectMethod(m_connection.jobj,m_HttpURLConnection_getHeaderFieldKey,j) ,env );
                    jni_string value( env->CallObjectMethod(m_connection.jobj,m_HttpURLConnection_getHeaderField,j)  ,env);
                    if (!key.jstr || !value.jstr) break;
                    m_handler->OnHeader(key.str().c_str(),value.str().c_str());
                }  // end for
                m_state = S_RESPONSE_R;
            } break;
            case S_READ_R: {
                slock l(m_lock);
                FlushData(env);
                m_state = S_READ;
            } break;
            case S_COMPLETE: {
                slock l(m_lock);
                FlushData(env);
                m_handler->OnComplete(); 
                return true;
            }
            case S_ERROR: {
                slock l(m_lock);
                LOG_ERROR(m_error);
                m_handler->OnError(m_error.c_str());
                m_handler->OnComplete();
                return true;
            }
        }
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

class NetworkAndroid : public GHL::Network {
private:
    jclass  m_URL_class;
    jmethodID m_URL_ctr;
    jmethodID m_URL_openConnection;
    std::list<NetworkTask*> m_tasks;
    pthread_mutex_t m_lock;
    pthread_mutex_t m_list_lock;
    
    pthread_t       m_thread;
    bool m_stop;
public:
    NetworkAndroid() {
        LOG_INFO("NetworkAndroid");
        assert(GHL::g_native_activity);
        JNIEnv* env = GHL::g_native_activity->env;
        if (check_exception(env)) {
            LOG_INFO("clear pending exception");
        }
        m_URL_class = (jclass)env->NewGlobalRef((jobject)env->FindClass("java/net/URL"));
        m_URL_ctr = get_method(env,m_URL_class,"<init>","(Ljava/lang/String;)V"); 
        assert(m_URL_ctr);
        m_URL_openConnection = get_method(env,m_URL_class,"openConnection","()Ljava/net/URLConnection;"); 
        assert(m_URL_openConnection);

        jclass HttpURLConnection_class = env->FindClass("java/net/HttpURLConnection");
        NetworkTask::m_HttpURLConnection_setDoOutput = get_method(env,HttpURLConnection_class,"setDoOutput","(Z)V");
        assert(NetworkTask::m_HttpURLConnection_setDoOutput);
        NetworkTask::m_HttpURLConnection_connect = get_method(env,HttpURLConnection_class,"connect","()V");
        assert(NetworkTask::m_HttpURLConnection_connect);
        NetworkTask::m_HttpURLConnection_disconnect = get_method(env,HttpURLConnection_class,"disconnect","()V");
        assert(NetworkTask::m_HttpURLConnection_disconnect);
        NetworkTask::m_HttpURLConnection_getInputStream = get_method(env,HttpURLConnection_class,"getInputStream","()Ljava/io/InputStream;");
        assert(NetworkTask::m_HttpURLConnection_getInputStream);
        NetworkTask::m_HttpURLConnection_getOutputStream = get_method(env,HttpURLConnection_class,"getOutputStream","()Ljava/io/OutputStream;");
        assert(NetworkTask::m_HttpURLConnection_getOutputStream);
        NetworkTask::m_HttpURLConnection_getHeaderFieldKey = get_method(env,HttpURLConnection_class,"getHeaderFieldKey","(I)Ljava/lang/String;");
        assert(NetworkTask::m_HttpURLConnection_getHeaderFieldKey);
        NetworkTask::m_HttpURLConnection_getHeaderField = get_method(env,HttpURLConnection_class,"getHeaderField","(I)Ljava/lang/String;");
        assert(NetworkTask::m_HttpURLConnection_getHeaderField);
        NetworkTask::m_HttpURLConnection_setRequestProperty = get_method(env,HttpURLConnection_class,"setRequestProperty","(Ljava/lang/String;Ljava/lang/String;)V");
        assert(NetworkTask::m_HttpURLConnection_setRequestProperty);
        NetworkTask::m_HttpURLConnection_getResponseCode = get_method(env,HttpURLConnection_class,"getResponseCode","()I");
        assert(NetworkTask::m_HttpURLConnection_getResponseCode);
        if (check_exception(env)) {
            LOG_INFO("exception on get method");
            assert(false);
        }
        jclass InputStream = env->FindClass("java/io/InputStream");
        assert(InputStream);
        NetworkTask::m_InputStream_read = get_method(env,InputStream,"read","([BII)I");
        assert(NetworkTask::m_InputStream_read);
        env->DeleteLocalRef(InputStream);

        jclass OutputStream = env->FindClass("java/io/OutputStream");
        assert(OutputStream);
        NetworkTask::m_OutputStream_write = get_method(env,OutputStream,"write","([B)V");
        assert(NetworkTask::m_OutputStream_write);
        env->DeleteLocalRef(OutputStream);

        env->DeleteLocalRef(HttpURLConnection_class);

        pthread_mutex_init( &m_lock, NULL );
        pthread_mutex_init( &m_list_lock, NULL );
        m_stop = false;
        env->GetJavaVM(&jvm);
        pthread_create( &m_thread, 0, thread_thunk, this );
    }
    ~NetworkAndroid() {
        LOG_INFO("~NetworkAndroid");
        assert(GHL::g_native_activity);
        JNIEnv* env = GHL::g_native_activity->env;
        env->DeleteGlobalRef(m_URL_class);
        
        {
            slock l(m_lock);
            m_stop = true;
        }
        pthread_join( m_thread, 0 );
        for (std::list<NetworkTask*>::iterator it = m_tasks.begin();it!=m_tasks.end();++it) {
            delete *it;
        }
        pthread_mutex_destroy( &m_lock );
        pthread_mutex_destroy( &m_list_lock );
    }
    /// GET request
    virtual bool GHL_CALL Get(GHL::NetworkRequest* handler) {
        if (!handler)
            return false;
        JNIEnv* env = GHL::g_native_activity->env;
        jni_string url_str(handler->GetURL(),env);
        jni_object url(env->NewObject(m_URL_class,m_URL_ctr,url_str.jstr),env);
        jobject connection = (env->CallObjectMethod(url.jobj,m_URL_openConnection));
        if (check_exception(env)) {
            return false;
        }
        {
            slock l(m_list_lock);
            m_tasks.push_back(new NetworkTask(env,connection,handler,0,m_lock));
        }
        return true;
    }
    /// POST request
    virtual bool GHL_CALL Post(GHL::NetworkRequest* handler,const GHL::Data* data) {
        if (!handler)
            return false;
        JNIEnv* env = GHL::g_native_activity->env;
        jni_string url_str(handler->GetURL(),env);
        jni_object url(env->NewObject(m_URL_class,m_URL_ctr,url_str.jstr),env);
        jobject connection = (env->CallObjectMethod(url.jobj,m_URL_openConnection));
        if (check_exception(env)) {
            return false;
        }
        {
            slock l(m_list_lock);
            m_tasks.push_back(new NetworkTask(env,connection,handler,data->Clone(),m_lock));
        }
        return true;
    }
    virtual void GHL_CALL Process() {
        JNIEnv* env = GHL::g_native_activity->env;
        for (std::list<NetworkTask*>::iterator it = m_tasks.begin();it!=m_tasks.end();) {
            if ((*it)->ProcessMain(env)) {
                slock s(m_list_lock);
                delete *it;
                it = m_tasks.erase(it);
            } else {
                ++it;
            }
        }
    }
    bool ProcessBackground(JNIEnv* env) {
        {
            slock l(m_list_lock);
            for (std::list<NetworkTask*>::iterator it = m_tasks.begin();it!=m_tasks.end();++it) {
                {
                    slock s(m_lock);
                    if (m_stop) return true;
                }
                
                if ((*it)->ProcessBackground(env)) {
                } 
            }
        }
        {
            slock s(m_lock);
            return m_stop;
        }
        return false;
    }
    static void *thread_thunk( void *arg ) {
        JNIEnv* env = 0;
        jvm->AttachCurrentThread(&env,0);

        while (true) {
            if (static_cast<NetworkAndroid*>(arg)->ProcessBackground(env))
                break;
            
            usleep(100);
        }

        jvm->DetachCurrentThread();
        return 0;
    }
};

jmethodID  NetworkTask::m_HttpURLConnection_setDoOutput = 0;
jmethodID  NetworkTask::m_HttpURLConnection_connect = 0;
jmethodID  NetworkTask::m_HttpURLConnection_setRequestProperty = 0;
jmethodID  NetworkTask::m_HttpURLConnection_getResponseCode = 0;
jmethodID  NetworkTask::m_HttpURLConnection_getHeaderFieldKey = 0;
jmethodID  NetworkTask::m_HttpURLConnection_getHeaderField = 0;
jmethodID  NetworkTask::m_HttpURLConnection_getOutputStream = 0;
jmethodID  NetworkTask::m_HttpURLConnection_getInputStream = 0;
jmethodID  NetworkTask::m_HttpURLConnection_disconnect = 0;
jmethodID  NetworkTask::m_InputStream_read = 0;
jmethodID  NetworkTask::m_OutputStream_write = 0;

GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork() {
    return new NetworkAndroid();
}


GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* n) {
    delete static_cast<NetworkAndroid*>(n);
}