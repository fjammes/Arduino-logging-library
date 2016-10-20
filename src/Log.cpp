#include "Log.h"

//#define Serial SerialUSB

void Log::init(Level level, long baud) {
    _level = level;
    _baud = baud;
    Serial.begin(_baud);
    SerialUSB.begin(_baud);
    while (millis()<5000 and !SerialUSB);
    if (SerialUSB) {
        logSerial = &SerialUSB;
    }
    else if (Serial) {
        logSerial = &Serial;
    }
    logSerial->print("Logger ready");
}

void Log::log(Level level, char const * const msg, ...) {
    if (level <= _level) {
        char loglevel[8];
        sprintf(loglevel, "%s:", LevelNames[level]);
        logSerial->print(loglevel);
        va_list args;
        va_start(args, msg);
        print(msg,args);
        logSerial->print(CR);
    }
}

void Log::print(const char *format, va_list args) {
    //
    // loop through format string
    for (; *format != 0; ++format) {
        if (*format == '%') {
            ++format;
            if (*format == '\0') break;
            if (*format == '%') {
                logSerial->print(*format);
                continue;
            }
            if( *format == 's' ) {
                register char *s = (char *)va_arg( args, int );
                logSerial->print(s);
                continue;
            }
            if( *format == 'd' || *format == 'i') {
                logSerial->print(va_arg( args, int ),DEC);
                continue;
            }
            if( *format == 'x' ) {
                logSerial->print(va_arg( args, int ),HEX);
                continue;
            }
            if( *format == 'X' ) {
                logSerial->print("0x");
                logSerial->print(va_arg( args, int ),HEX);
                continue;
            }
            if( *format == 'b' ) {
                logSerial->print(va_arg( args, int ),BIN);
                continue;
            }
            if( *format == 'B' ) {
                logSerial->print("0b");
                logSerial->print(va_arg( args, int ),BIN);
                continue;
            }
            if( *format == 'l' ) {
                logSerial->print(va_arg( args, long ),DEC);
                continue;
            }
            if( *format == 'f' ) {
                logSerial->print(va_arg( args, double ),6);
                continue;
            }

            if( *format == 'c' ) {
                logSerial->print(va_arg( args, int ));
                continue;
            }
            if( *format == 't' ) {
                if (va_arg( args, int ) == 1) {
                    logSerial->print("T");
                }
                else {
                    logSerial->print("F");
                }
                continue;
            }
            if( *format == 'T' ) {
                if (va_arg( args, int ) == 1) {
                    logSerial->print("true");
                }
                else {
                    logSerial->print("false");
                }
                continue;
            }

        }
        logSerial->print(*format);
    }
}

Log logger = Log();






