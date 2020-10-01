#ifndef I2C_ADDRESS_LOCATOR_H
#define I2C_ADDRESS_LOCATOR_H

#include <Wire.h>
#include <Arduino.h>

enum response_type{
  address_found       = 0,
  address_not_found   = 1,
  no_device_connected = 2
};

typedef struct response
{
  const enum response_type type;
  const char * message;
} Response;

const Response responses[] = {
  {.type = address_found, .message = "[SUCCESS] L2C Address found for lcd device"},
  {.type = address_not_found, .message = "[ERROR] Unable to find L2C address for lcd device. Wifi libray error, please look at documentation on Wire.endTransmission()"},
  {.type = no_device_connected, .message = "[ERROR] No device connected"}
}; 

byte find_i2c_address();

#endif


/*
  find address to i2c at runtime which would than init the lcd 
*/