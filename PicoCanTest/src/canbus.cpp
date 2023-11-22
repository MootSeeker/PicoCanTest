

#include "canbus.h"
#include <mcp_can.h>

/* Please modify SPI_CS_PIN to adapt to your board.

   CANBed V1        - 17
   CANBed M0        - 3
   CAN Bus Shield   - 9
   CANBed 2040      - 9
   CANBed Dual      - 9
   OBD-2G Dev Kit   - 9
   OBD-II GPS Kit   - 9
   Hud Dev Kit      - 9

   Seeed Studio CAN-Bus Breakout Board for XIAO and QT Py - D7
*/

#define SPI_CS_PIN  9 

MCP_CAN CAN( SPI_CS_PIN );                                    // Set CS pin

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