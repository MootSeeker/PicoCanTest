#ifndef MCP25625_H
#define MCP25625_H

#include <SPI.h>

#include "CANController.h"

#define MCP2515_DEFAULT_CLOCK_FREQUENCY ( 16000000UL )

#define MCP2515_DEFAULT_CS_PIN          ( 5 )
#define MCP2515_DEFAULT_INT_PIN         ( 1 )

typedef enum
{
    CAN_OK              = 0x00, 
    CAN_ERROR           = 0x01, 
    CAN_ERROR_ALLTXBUSY = 0x02,
    CAN_ERROR_FAILINIT  = 0x03,
    CAN_ERROR_FAILTX    = 0x04,
    CAN_ERROR_NOMSG     = 0x05
}EN_CAN_ERRORS; 

class MCP2515 : public CANControllerClass 
{
    public:
        MCP2515( );
        virtual ~MCP2515( );

        virtual int begin(long baudRate);
        virtual void end();

        virtual int endPacket();
        virtual int parsePacket();
        virtual void onReceive(void(*callback)(int));

        using CANControllerClass::filter;
        virtual int filter(int id, int mask);
        using CANControllerClass::filterExtended;
        virtual int filterExtended(long id, long mask);

        virtual int observe();
        virtual int loopback();
        virtual int sleep();
        virtual int wakeup();

        void setPins(int cs = MCP2515_DEFAULT_CS_PIN, int irq = MCP2515_DEFAULT_INT_PIN);
        void setSPIFrequency(uint32_t frequency);
        void setClockFrequency(long clockFrequency);

        void dumpRegisters(Stream& out);

    private:
        void reset();
        void handleInterrupt();

        uint8_t readRegister(uint8_t address);
        void modifyRegister(uint8_t address, uint8_t mask, uint8_t value);
        void writeRegister(uint8_t address, uint8_t value);

        static void onInterrupt();

    private:
        SPISettings _spiSettings;
        int _csPin;
        int _intPin;
        long _clockFrequency;
};

extern MCP2515 CAN;


#endif /* END: MCP25625.h */