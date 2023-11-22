

#ifndef _INCLUDE_CANBUS_H
#define _INCLUDE_CANBUS_H

#include <stdint.h>

typedef enum 
{
    CAN_OK, 
    CAN_ERROR, 
    CAN_CRC_ERROR, 
    CAN_TIMEOUT_ERROR, 
} enCAN_ERRORS; 

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



// CAN bus class
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