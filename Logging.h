//
//  Logging.h
//  
//
//  Created by Roman Hayer on 08.05.18.
//

#ifndef logging_h
#define logging_h
#include <Arduino.h>

#define LOG_INIT Logging logger
#define LOG_LOGGER logger

#define LOG_INFO(a) \
logger.log(Logging::INFO,a)

#define LOG_INFO1(a,b) \
logger.log(Logging::INFO,a,b)

#define LOG_INFO2(a,b,c) \
logger.log(Logging::INFO,a,b,c)




class Logging {
private:
    int currentLogLevel;
public:
    
    enum LogLevel {
        OFF = 0, INFO = 1, WARN = 2, ERROR = 4
    };

    Logging (int logLevel=INFO+ERROR,int baudRate=115200);
    void log(int logLevel, const char* logMessage,...);
    void setLogLevel(int logLevel);
};


#endif /* logging_h */
