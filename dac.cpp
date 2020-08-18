#include "DAC.h"

/// DAC
nBlock_DAC::nBlock_DAC(PinName pinDAC, uint16_t preset): _dac(pinDAC) {
    _preset = (float)preset/65535;
    _dac = _preset;
    return;
}

void nBlock_DAC::triggerInput(nBlocks_Message message) {
    float fval;

    // Input 0 triggers a read regardless of value
    if (message.inputNumber == 0) {
		// Select a different writing method depending on data type
		if (message.dataType == OUTPUT_TYPE_FLOAT) {
			// Float: Make sure we have a value in the [0.0, 1.0] range
			fval = message.floatValue;
			if (fval > 1.0) fval = 1.0;
			if (fval < 0.0) fval = 0.0;
			_dac = fval;
		}
		else if (message.dataType == OUTPUT_TYPE_INT) {
			// Int: convert to float by normalizing to 65535
			if (value < 65535) {
				fval = (float)value/65535; //make floating normalized 0-1
				_dac = fval;                 
			}
		}
		else {
			// Unknown data type. Just ignore and fail silently
		}
    }	
	
}

