#include <QDebug>
#include <ghl_log.h>



GHL_API void GHL_CALL GHL_Log( GHL::LogLevel level,const char* message) {
    (void)level;
    qDebug() << message;
}
