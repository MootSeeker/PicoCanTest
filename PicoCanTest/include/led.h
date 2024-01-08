#ifndef LED_H
#define LED_H

#include "stdint.h"

#define LED_PIN 13

// Define pins for Neopixel
#define neoLedPin   ( 21 )
#define neoPowerPin ( 20 )

// Define amount of neopixel leds
#define NUMPIXELS   ( 1 )

// LED class driver 
class LED
{
    public: 
        LED( ); 
        ~LED( ); 

        void begin( void ); 
        void led_toggle( void ); 

    private:
        uint8_t led_value; 
}; 

#endif