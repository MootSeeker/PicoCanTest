#include "led.h"

#include <Arduino.h>


// ................................................................................
/* 
 *  @brief  Constructor of led object
 *  @note   
 *  @param  -
 *  @return -
 */
LED::LED( )
{
    // Set pin mode of LED pin
    pinMode( LED_PIN, OUTPUT ); 

    // Reset LED value
    led_value = LOW; 

    // Set led by default to off
    digitalWrite( LED_PIN, led_value ); 
}

LED::~LED( )
{

}