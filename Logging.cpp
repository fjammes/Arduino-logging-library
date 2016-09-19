#include "Logging.h"

void Logging::Init(int level){
    _level = constrain(level,LOG_LEVEL_NOOUTPUT,LOG_LEVEL_VERBOSE);
}

void Logging::Error(char* msg, ...){
    if (LOG_LEVEL_ERRORS <= _level) {   
		print ("ERROR: ",0);
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}


void Logging::Info(char* msg, ...){
    if (LOG_LEVEL_INFOS <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}

void Logging::Debug(char* msg, ...){
    if (LOG_LEVEL_DEBUG <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}


void Logging::Verbose(char* msg, ...){
    if (LOG_LEVEL_VERBOSE <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}



 void Logging::print(const char *format, va_list args) {
    //
    // loop through format string
    for (; *format != 0; ++format) {
        if (*format == '%') {
            ++format;
            if (*format == '\0') break;
            if (*format == '%') {
                USB.print(*format);
                continue;
            }
            if( *format == 's' ) {
				register char *s = (char *)va_arg( args, int );
				USB.print(s);
				continue;
			}
            if( *format == 'd' || *format == 'i') {
				USB.print(va_arg( args, int ),DEC);
				continue;
			}
            if( *format == 'x' ) {
				USB.print(va_arg( args, int ),HEX);
				continue;
			}
            if( *format == 'X' ) {
				USB.print("0x");
				USB.print(va_arg( args, int ),HEX);
				continue;
			}
            if( *format == 'b' ) {
				USB.print(va_arg( args, int ),BIN);
				continue;
			}
            if( *format == 'B' ) {
				USB.print("0b");
				USB.print(va_arg( args, int ),BIN);
				continue;
			}
            if( *format == 'l' ) {
				USB.print(va_arg( args, long ),DEC);
				continue;
			}

            if( *format == 'c' ) {
				USB.print(va_arg( args, int ));
				continue;
			}
            if( *format == 't' ) {
				if (va_arg( args, int ) == 1) {
					USB.print("T");
				}
				else {
					USB.print("F");				
				}
				continue;
			}
            if( *format == 'T' ) {
				if (va_arg( args, int ) == 1) {
					USB.print("true");
				}
				else {
					USB.print("false");				
				}
				continue;
			}

        }
        USB.print(*format);
    }
 }
 
 Logging Log = Logging();

 
 
  




