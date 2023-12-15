/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
  (C)2017 Semtech
*/

#ifndef SX1308_H
#define SX1308_H

#include "mbed.h"

class SX1308 {

public:
    SX1308(PinName slaveSelectPin, PinName mosi, PinName miso, PinName sclk, PinName interrupt, PinName Reset);
    virtual bool   init();
    void           dig_reset();
    void           spiWrite(uint8_t reg, uint8_t val);
    void           spiWriteBurstF(uint8_t reg, uint8_t * val, int size);
    void           spiWriteBurst(uint8_t reg, uint8_t * val, int size);
    void           spiWriteBurstM(uint8_t reg, uint8_t * val, int size);
    void           spiWriteBurstE(uint8_t reg, uint8_t * val, int size);
    uint8_t        spiRead(uint8_t reg);
    uint8_t        spiReadBurstF(uint8_t reg, uint8_t *data, int size);
    uint8_t        spiReadBurstM(uint8_t reg, uint8_t *data, int size);
    uint8_t        spiReadBurstE(uint8_t reg, uint8_t *data, int size);
    uint8_t        spiReadBurst(uint8_t reg, uint8_t *data, int size);
    volatile uint8_t waittxend;
    uint8_t        txongoing;
    Timer          timerstm32ref;
    uint32_t       offtmstpstm32;
    uint32_t       offtmstpstm32ref;
    bool           firsttx;

private:
    void           isr0();
    uint8_t        _interruptPin;
    DigitalOut     _slaveSelectPin;
    DigitalOut     _reset;
    SPI            _spi;
    InterruptIn    _interrupt;
};

#endif
