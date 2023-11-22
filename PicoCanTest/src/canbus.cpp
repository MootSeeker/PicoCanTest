/**
 * @file   canbus.cpp
 *
 * @brief  	Brief description of the content of calculations.c
 * @author 	kevin.perillo, Rotronic AG
 * @date   	22.11.2023 - first implementation
 * @version 1.0.0
 * 
 * MIT License
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright (c) 2023 Rotronic AG
 */
 
#include "canbus.h"
#include <mcp_can.h>

// Define SPI CS Pin of MCP2515
#define SPI_CS_PIN  9               // CS Pin on Adafurit RP2040 CAN Bus feather board 

// Define MCP CAN object 
MCP_CAN CAN( SPI_CS_PIN );                                    

// ..........................................................................................
/*
 *  @brief  Constructor 
 *  @note   Init canbus object 
 *  @param  Can bus speed 
 *  @note   none
 */
canbus::canbus( enCAN_BAUDRATES speed )
{
    // Set initial values
    bus_speed = speed;
    flag = 0; 
    len = 0; 
    memset( buf, '\0', sizeof( buf ));    // Clear buffer on init 
    memset( str, '\0', sizeof( str ));    // Clear buffer on init 

    // Init CAN bus module  ........................................
    if( CAN_OK != CAN.begin(MCP_ANY, bus_speed, MCP_16MHZ))
    {
        // Init CAN failed show error
        ////TODO: Add error handling
    }

    // Set Mode
    CAN.setMode( MCP_NORMAL ); 

    // Init Mask filters ...........................................
    CAN.init_Mask(0,0,0x010F0000);
    CAN.init_Filt(0,0,0x01000000);
    CAN.init_Filt(1,0,0x01010000);
    CAN.init_Mask(1,0,0x010F0000);
    CAN.init_Filt(2,0,0x01030000);
    CAN.init_Filt(3,0,0x01040000);
    CAN.init_Filt(4,0,0x01060000);
    CAN.init_Filt(5,0,0x01070000);
}

// ..........................................................................................
/*
 *  @brief  Deconstructor 
 *  @note   Deinit canbus object 
 *  @param  none
 *  @note   none
 */
canbus::~canbus( )
{
    
} 