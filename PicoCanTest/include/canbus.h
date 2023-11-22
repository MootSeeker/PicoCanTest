/**
 * @file   canbus.h
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

#ifndef _INCLUDE_CANBUS_H
#define _INCLUDE_CANBUS_H

// Includes 
#include <stdint.h>

//................................................................................
/**
 * @brief  Enumeration for canbus errors
 */
typedef enum 
{
    CAN_OK, 
    CAN_ERROR, 
    CAN_CRC_ERROR, 
    CAN_TIMEOUT_ERROR, 
} enCAN_ERRORS; 

//................................................................................
/**
 * @brief  Enumeration for the bus speed setting
 */
typedef enum
{
    CAN_5K     = 1,
    CAN_10K    = 2,
    CAN_20K    = 3,
    CAN_25K    = 4,
    CAN_31K25  = 5,
    CAN_33K    = 6,
    CAN_40K    = 7,
    CAN_50K    = 8,
    CAN_80K    = 9,
    CAN_83K3   = 10,
    CAN_95K    = 11,
    CAN_100K   = 12,
    CAN_125K   = 13,
    CAN_200K   = 14,
    CAN_250K   = 15,
    CAN_500K   = 16,
    CAN_666K   = 17,
    CAN_1000K  = 18
}enCAN_BAUDRATES; 



//................................................................................
/**
 * @brief CAN bus communication class.
 * 
 * @note  This class provides a simple interface for sending and receiving messages
 *        on a CAN bus. It includes functionality for setting the bus speed, sending
 *        and receiving messages, and handling related information.
 */
class canbus
{
    public: 
    canbus( enCAN_BAUDRATES bus_speed ); 
    ~canbus( ); 

    enCAN_ERRORS send_message( );
    enCAN_ERRORS receive_message( ); 

    private: 
    // Bus information 
    enCAN_BAUDRATES bus_speed;
    uint8_t flag; 
    uint16_t len; 
    uint8_t buf[8]; 
    uint8_t str[20]; 
}; 

#endif // END : _INCLUDE_CANBUS_HPP