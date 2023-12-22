#ifndef LED_H
#define LED_H

#include "stdint.h"

#define LED_PIN 13

// LED class driver 
class LED
{
    public: 
        LED( ); 
        ~LED( ); 

    private:
        uint8_t led_value; 
}; 

#endif