#ifndef BINARY_TO_HEX_H 
#define BINARY_TO_HEX_H 

#include "i2c_address_locator.h"

enum bit_order {
    high_order  = 0,
    low_order   = 1 
};

char* binary_to_hex(byte input_byte);

#endif