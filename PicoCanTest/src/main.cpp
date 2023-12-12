#include <Arduino.h>

void setup( ) 
{
    // Init Serial for debug commands
    Serial.begin( 115200 ); 
    // Check if debug interface is initialized without an error
    while( !Serial ); 

    Serial.println(" Pico is working by Visual Studio "); 
}

void loop( ) 
{
    Serial.println( "Pico is working I don't know! "); 
    delay( 1000 ); 
}

