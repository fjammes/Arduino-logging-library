#include "Log.h"

void Log::init(Level level, long baud){
    _level = level;
    _baud = baud;
    Serial.begin(_baud);
}

void Log::log(Level level, char* msg, ...){
    if (level <= _level) {
    	char loglevel[8];
    	sprintf(loglevel, "%s:", LevelNames[level]);
		Serial.print(loglevel);
        va_list args;
        va_start(args, msg);
        print(msg,args);
        Serial.print(CR);
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
                Serial.print(*format);
                continue;
            }
            if( *format == 's' ) {
				register char *s = (char *)va_arg( args, int );
				Serial.print(s);
				continue;
			}
            if( *format == 'd' || *format == 'i') {
				Serial.print(va_arg( args, int ),DEC);
				continue;
			}
            if( *format == 'x' ) {
				Serial.print(va_arg( args, int ),HEX);
				continue;
			}
            if( *format == 'X' ) {
				Serial.print("0x");
				Serial.print(va_arg( args, int ),HEX);
				continue;
			}
            if( *format == 'b' ) {
				Serial.print(va_arg( args, int ),BIN);
				continue;
			}
            if( *format == 'B' ) {
				Serial.print("0b");
				Serial.print(va_arg( args, int ),BIN);
				continue;
			}
            if( *format == 'l' ) {
				Serial.print(va_arg( args, long ),DEC);
				continue;
			}
            if( *format == 'f' ) {
                Serial.print(va_arg( args, double ),6);
            	continue;
            }

            if( *format == 'c' ) {
				Serial.print(va_arg( args, int ));
				continue;
			}
            if( *format == 't' ) {
				if (va_arg( args, int ) == 1) {
					Serial.print("T");
				}
				else {
					Serial.print("F");				
				}
				continue;
			}
            if( *format == 'T' ) {
				if (va_arg( args, int ) == 1) {
					Serial.print("true");
				}
				else {
					Serial.print("false");				
				}
				continue;
			}

        }
        Serial.print(*format);
    }
 }

 Log logger = Log();
 
  




