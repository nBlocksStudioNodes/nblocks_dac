#include "DAC.h"

/// DAC
nBlock_DAC::nBlock_DAC(PinName pinDAC): _dac(pinDAC) {
    return;
}

void nBlock_DAC::triggerInput(uint32_t inputNumber, uint32_t value) {
    // Input 0 triggers a read regardless of value
    float finput;
    if (value < 65535) {
        finput = (float)value/65535; //make floating normalized 0-1
        _dac = finput;                 
    }
}

