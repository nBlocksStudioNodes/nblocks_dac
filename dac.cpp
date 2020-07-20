#include "DAC.h"

/// DAC
nBlock_DAC::nBlock_DAC(PinName pinDAC, uint16_t preset): _dac(pinDAC) {
    _preset = (float)preset/65535;
    _dac = _preset;
    pritf("preset= %f ",_preset)
    return;
}

void nBlock_DAC::triggerInput(uint32_t inputNumber, uint32_t value) {
    // Input 0 triggers a read regardless of value
    float fval;
    if (value < 65535) {
        fval = (float)value/65535; //make floating normalized 0-1
        _dac = fval;                 
    }
}

