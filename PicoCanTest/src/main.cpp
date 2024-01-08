#include <Arduino.h>
#include <led.h>

// Create LED object
LED led; 

void setup( ) 
{
  pinMode( 13 , OUTPUT ); 
  // Init Serial Port
  Serial.begin( 115200 );
   
  led.begin( ); 
}

void loop( ) 
{
  led.led_toggle( ); 
  
  Serial.println(" Hello World! ");
}




