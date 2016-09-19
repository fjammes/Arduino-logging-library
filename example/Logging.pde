#include <Logging.h>

/*  
 *  ------ Waspmote Pro Code Example -------- 
 *  
 *  Explanation: This is the basic Code for Waspmote Pro
 *  
 *  Copyright (C) 2013 Libelium Comunicaciones Distribuidas S.L. 
 *  http://www.libelium.com 
 *  
 *  This program is free software: you can redistribute it and/or modify  
 *  it under the terms of the GNU General Public License as published by  
 *  the Free Software Foundation, either version 3 of the License, or  
 *  (at your option) any later version.  
 *   
 *  This program is distributed in the hope that it will be useful,  
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of  
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
 *  GNU General Public License for more details.  
 *   
 *  You should have received a copy of the GNU General Public License  
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  
 */
     
// Put your libraries here (#include ...)

// we need a Log object

#define LOGLEVEL LOG_LEVEL_DEBUG

int myInt1, myInt2;
long myLong1, myLong2;
bool myBool1, myBool2;
char* myString = "this is a string";

void setup() {
    Log.Init(LOGLEVEL);
    Log.Info(CR"******************************************"CR);
    Log.Info("My favorite output stuff in future :-)"CR);
    Log.Info("******************************************"CR);
    myInt1 = 232;
    myInt2 = 32199;
    myLong1 = 99403020;
    myLong2 = 45021;
    myBool1 = true;
    myBool2 = !myBool1;
}

void loop() {
    Log.Info("Display my integers myInt1 %d, myInt2 %d"CR, myInt1, myInt2);
    Log.Info("Display as hex myInt1=%x, myInt1=%X"CR, myInt1, myInt1);
    Log.Info("Display as hex myInt2=%x, myInt2=%X"CR, myInt2, myInt2);
    Log.Info("Display as binary myInt1=%b, myInt1=%B"CR, myInt1, myInt1);
    Log.Info("Display as binary myInt2=%b, myInt2=%B"CR, myInt2, myInt2);
    Log.Info("Display my longs myLong1 %l, myLong2=%l"CR, myLong1, myLong2);
    Log.Info("Display my bool myBool1=%t, myBool2=%T"CR, myBool1, myBool2);
    Log.Info("Output: %s"CR, myString);
    Log.Error("is this an real error? %T"CR, myBool2);
    Log.Debug("%d, %d, %l, %l, %t, %T"CR, myInt1, myInt2,
              myLong1, myLong2,
              myBool1, myBool2);
    Log.Info(CR"have fun with this Log"CR);
    delay(5000);
}

