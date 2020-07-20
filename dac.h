#ifndef __NB_DAC
#define __NB_DAC

#include "mbed.h"
#include "nworkbench.h"

class nBlock_DAC: public nBlockSimpleNode<1> {
public:
    nBlock_DAC(PinName pinDAC);
    void triggerInput(uint32_t inputNumber, uint32_t value);
private:
    AnalogOut _dac;
};





#endif
