#include "i2c_address_locator.h"

int find_first_l2c_address(byte * l2c_address){
  byte error, address;

   for(address = 1; address < 127; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if(error == 0){
      *l2c_address = address;
      return address_found;
    }

    if(error == 4){
      *l2c_address = 0;
      return address_not_found;
    }
   }
   return no_device_connected;
}


byte find_i2c_address(){
  byte l2c_address;
  int response_code = find_first_l2c_address(&l2c_address);

  switch (response_code)
  {
    case address_found:
      Serial.println(responses[address_found].message);
      break;
    case address_not_found:
      Serial.println(responses[address_not_found].message);
      exit(address_not_found);
    case no_device_connected:
      Serial.println(responses[no_device_connected].message);
      exit(no_device_connected);
    default:
      Serial.println(responses[no_device_connected].message);
      exit(no_device_connected);
  }
  return l2c_address;
} 