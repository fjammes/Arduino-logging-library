#ifndef LOG_H
#define LOG_H
#include <inttypes.h>
#include <stdarg.h>
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define CR "\r\n"

#define LOG_INIT(level, baud_rate) \
    do { \
        logger.init(level, baud_rate); \
    } while (false)

#define LOG_TRACE(msg...) \
    do { \
        logger.log(Log::TRACE, msg); \
    } while (false)

#define LOG_DEBUG(msg...) \
    do { \
        logger.log(Log::DEBUG, msg); \
    } while (false)

#define LOG_INFO(msg...) \
    do { \
        logger.log(Log::INFO, msg); \
    } while (false)

#define LOG_WARN(msg...) \
    do { \
        logger.log(Log::WARN, msg); \
    } while (false)

#define LOG_ERROR(msg...) \
    do { \
        logger.log(Log::ERROR, msg); \
    } while (false)

#define LOG_FATAL(msg...) \
    do { \
        logger.log(Log::FATAL, msg); \
    } while (false)

/**
* Logging is a helper class to output informations over
* RS232. If you know log4j or log4net, this logging class
* is more or less similar ;-)
* Different loglevels can be used to extend or reduce output
* All methods are able to handle any number of output parameters.
* All methods print out a formated string (like printf).
* To reduce output and program size, reduce loglevel.
*
* Output format string can contain below wildcards. Every wildcard
* must be start with percent sign (\%)
*
* Depending on loglevel, source code is excluded from compile !
*
* Wildcards
*
* \%s	replace with an string (char*)
* \%c	replace with an character
* \%d	replace with an integer value
* \%l	replace with an long value
* \%x	replace and convert integer value into hex
* \%X	like %x but combine with 0x123AB
* \%b	replace and convert integer value into binary
* \%B	like %x but combine with 0b10100011
* \%t	replace and convert boolean value into "t" or "f"
* \%T	like %t but convert into "true" or "false"
* </ul>
* Loglevels
*
* 0    LOG_LEVEL_NOOUTPUT    no output
* 1    LOG_LEVEL_ERROR    only errors
* 2    LOG_LEVEL_INFO    errors and info
* 3    LOG_LEVEL_DEBUG    errors, info and debug
* 4    LOG_LEVEL_VERBOSE    all
*
*/
class Log {
public:

    enum Level { FATAL, ERROR, WARN, INFO, DEBUG, TRACE };
    char const *const LevelNames[6] = { "FATAL", "ERROR", "WARN", "INFO", "DEBUG", "TRACE" };

    /**
     * default Constructor
     */
    Log() {} ;

    /**
    * Initializing, must be called as first.
    * \param void
    * \return void
    *
    */
    void init(Log::Level level, long baud);


    /**
    * Output an log message with a given log level.
    * Output message contains level followed by original msg
    * \param msg format string to output
    * \param ... any number of variables
    * \return void
    */
    void log(Level level, char const * const msg, ...);

private:
    int _level = Log::TRACE;
    long _baud;

    Stream* logSerial;

    void print(const char *format, va_list args);


};

extern Log logger;

#endif




