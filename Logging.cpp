//
//  Logging.cpp
//  
//
//  Created by Roman Hayer on 08.05.18.
//

#include "Logging.h"

Logging::Logging(int logLevel,int baudRate)
{
    Serial.begin(baudRate);    
    this->currentLogLevel = logLevel;
    
}

void Logging::setLogLevel(int logLevel) {
    this->currentLogLevel = logLevel;
}
void Logging::log(int logLevel, const char* logMessage,...)
{
    char logString[128];
    va_list va;
    String prefix;
    
    switch(logLevel) {
        case INFO:
            prefix="INFO: ";
            break;
        case WARN:
            prefix="WARNING: ";
            break;
        case ERROR:
            prefix="ERROR: ";
            break;
    }
    
    prefix.concat(logMessage);
    if ((logLevel & this->currentLogLevel) > 0) {
        va_start(va,logMessage);
        vsnprintf(logString,128,prefix.c_str(),va);
        //logString[sizeof(logString)/sizeof(logString[0])-1]='\0';
        va_end(va);
        
        Serial.println(logString);
    }
}

