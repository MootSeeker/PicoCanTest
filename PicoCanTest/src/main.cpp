#include <Arduino.h>
#include "canbus.h"

// Declare can object with 500k Baudrate 
canbus can( CAN_500K ); 

void setup( ) 
{
    // Init Serial for debug commands
    Serial.begin( 115200 ); 
    // Check if debug interface is initialized without an error
    while(!Serial); 
}

void loop() 
{

}

