#include "binary_to_hex.h"


// thought that i might had to convert binary value to hex string.. l2c lib already handles this
void binary_to_hex_converter(byte input_binary, char * output_hex, bit_order order){
  byte mask = 0xF0;

  if(order == high_order){
    input_binary &= mask;
  }

  if(order == low_order){
    input_binary <<= 4;
  }

  switch (input_binary)
  {
  case 0x10:
    *output_hex = '1';
    break;
  case 0x20:
    *output_hex = '2';
    break;
  case 0x30:
    *output_hex = '3';
    break;
  case 0x40:
    *output_hex = '4';
    break;
  case 0x50:
    *output_hex = '5';
    break;
  case 0x60:
    *output_hex = '6';
    break;
  case 0x70:
    *output_hex = '7';
    break;
  case 0x80:
    *output_hex = '8';
    break;
  case 0x90:
    *output_hex = '9';
    break;
  case 0xA0:
    *output_hex = 'A';
    break;
  case 0xB0:
    *output_hex = 'B';
    break;
  case 0xC0:
    *output_hex = 'C';
    break;
  case 0xD0:
    *output_hex = 'D';
    break;
  case 0xE0:
    *output_hex = 'E';
    break;
  case 0xF0:
    *output_hex = 'F';
    break; 
  }
}


char* binary_to_hex(byte input_byte){

  uint8_t hex_address_size = 5;
  char * hex_letter = (char*)malloc(sizeof(char));
  char * hex_address = (char*) malloc (sizeof(char) * hex_address_size);
  hex_address[0] = '0';
  hex_address[1] = 'x';

  binary_to_hex_converter(input_byte, hex_letter, high_order);
  hex_address[2] = *hex_letter;

  binary_to_hex_converter(input_byte, hex_letter, low_order);
  hex_address[3] = *hex_letter;
  hex_address[4] = '\0';

  free(hex_letter);
  Serial.print("I2C address found: ");
  Serial.println(hex_address);
  return hex_address;
}
