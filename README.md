# Logging library for Libelium Waspmote
by Fabrice Jammes - 2016

Forked from https://github.com/mrRobot62/Arduino-logging-library

# CURRENT VERSION

1.0)24-FEB-2012 beta version.

# Description

Easy to use logging library, like log4j or log4net. After getting a logger object, you will have
methods like Error, Info, Warn, Debug, Verbose to log informations over RS232.
Depending on the current loglevel lower logleves are not printed out.
It is possible to work with variable argument lists during output.
Detailed description is included in doc folder

# HOW TO IMPORT/INSTALL

```
cd <ide-install-path>/waspmote-pro-ide-v04-linux64/libraries
sudo git clone git@github.com:fjammes/WaspLogging.git
```

Open example project which is included in the `example` directory. Try it, like it :-)

# Some benefits:

!Use formated strings with wildcards
||border=0
||!wildcard	||!Comment	||Example 			||
||%s ||replace with an string (char*) ||logger.Info("String %s",myString); ||
||%c ||replace with an character ||logger.Info("use %c as input",myChar); ||
||%d ||replace with an integer value ||logger.Info("current value %d",myValue); ||
||%l ||replace with an long value ||logger.Info("current long %l",myLong); ||
||%x ||replace and convert integer value into hex ||logger.Info ("as hex %x), myValue); ||
||%X ||like %x but combine with 0x123AB ||logger.Info ("as hex %X), myValue); ||
||%b ||replace and convert integer value into binary ||logger.Info ("as bin %b), myValue); ||
||%B ||like %x but combine with 0b10100011 ||logger.Info ("as bin %B), myValue); ||
||%t ||replace and convert boolean value into "t" or "f" ||logger.Info ("is it true? %t), myBool); ||
||%T ||like %t but convert into "true" or "false" ||logger.Info ("is it true? %T), myBool); ||

!Methods for output
||border=0
||!Methode ||!Comment ||
||Error ||print messages with loglevel >= LOGLEVEL_ERROR ||
||Info ||print messages with loglevel >= LOGLEVEL_INFO ||
||Debug ||print messages with loglevel >= LOGLEVEL_DEBUG ||
||Verbose ||print messages with loglevel >= LOGLEVEL_VERGBOSE ||
