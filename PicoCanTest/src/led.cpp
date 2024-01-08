#include "led.h"

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(NUMPIXELS, neoLedPin, NEO_GRB + NEO_KHZ800);

// ................................................................................
/* 
 *  @brief  Constructor of led object
 *  @note   initialize the led object with it's default values
 *  @param  -
 *  @return -
 */
LED::LED( )
{
    // Set pin modes ...............................................................
    pinMode( LED_PIN, OUTPUT ); // LED Pin
    

    // Reset LED value .............................................................
    led_value = HIGH; 

    // Set led by default to off
    digitalWrite( LED_PIN, led_value );
}

LED::~LED( )
{

}

void LED::begin( void )
{
    pinMode( neoPowerPin, OUTPUT ); // Neopixel power pin

    // Set neopixel led ............................................................
    digitalWrite( neoPowerPin, HIGH ); // Turn on neopixel led
    pixels.begin( ); // Start object 
    delay( 100 ); 
    pixels.clear( ); // clear old random data
    pixels.setPixelColor( 1, pixels.Color(0, 100, 0)); // set color to led 1
    pixels.show( ); // show color on led 1
}

void LED::led_toggle( void )
{
    digitalWrite( 13, HIGH ); 
    delay(250); 
    digitalWrite( 13, LOW ); 
    delay(250); 
}