#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "i2c_address_locator.h"

/* find the l2c address of the 20x4 lcd (assume only 1 device)*/

/* References:
    https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/
    binary to hex: https://stackoverflow.com/a/41173236
*/

/* Parts List:
    lcd model SCL2004A:
    jameco part no: 2304015  
    https://www.jameco.com/shop/ProductDisplay?catalogId=10001&langId=-1&storeId=10001&productId=2304015 

    MELIFE ESP32 model: B07Q576VWZ
    https://www.amazon.com/MELIFE-Development-Dual-Mode-Microcontroller-Integrated/dp/B07Q576VWZ/ref=sr_1_3?dchild=1&keywords=ESP32&qid=1601348830&sr=8-3
*/

/* ESP32 Pins:
    22 : SCL
    21 : SDA
*/

const uint8_t ROWS = 4;
const uint8_t COLS = 20;


// thought that i might had to convert binary value to hex string.. l2c lib already handles this
// void binary_to_hex_converter(byte input_binary, char * output_hex, bit_order order){
//   byte mask = 0xF0;

//   if(order == high_order){
//     input_binary &= mask;
//   }

//   if(order == low_order){
//     input_binary <<= 4;
//   }

//   switch (input_binary)
//   {
//   case 0x10:
//     *output_hex = '1';
//     break;
//   case 0x20:
//     *output_hex = '2';
//     break;
//   case 0x30:
//     *output_hex = '3';
//     break;
//   case 0x40:
//     *output_hex = '4';
//     break;
//   case 0x50:
//     *output_hex = '5';
//     break;
//   case 0x60:
//     *output_hex = '6';
//     break;
//   case 0x70:
//     *output_hex = '7';
//     break;
//   case 0x80:
//     *output_hex = '8';
//     break;
//   case 0x90:
//     *output_hex = '9';
//     break;
//   case 0xA0:
//     *output_hex = 'A';
//     break;
//   case 0xB0:
//     *output_hex = 'B';
//     break;
//   case 0xC0:
//     *output_hex = 'C';
//     break;
//   case 0xD0:
//     *output_hex = 'D';
//     break;
//   case 0xE0:
//     *output_hex = 'E';
//     break;
//   case 0xF0:
//     *output_hex = 'F';
//     break; 
//   }
// }


// char* binary_to_hex(byte input_byte){

//   uint8_t hex_address_size = 5;
//   char * hex_letter = (char*)malloc(sizeof(char));
//   char * hex_address = (char*) malloc (sizeof(char) * hex_address_size);
//   hex_address[0] = '0';
//   hex_address[1] = 'x';

//   binary_to_hex_converter(input_byte, hex_letter, high_order);
//   hex_address[2] = *hex_letter;

//   binary_to_hex_converter(input_byte, hex_letter, low_order);
//   hex_address[3] = *hex_letter;
//   hex_address[4] = '\0';

//   free(hex_letter);
//   Serial.print("I2C address found: ");
//   Serial.println(hex_address);
//   return hex_address;
// }

const byte address = find_i2c_address();
LiquidCrystal_I2C lcd(address, COLS, ROWS);


void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");

  // byte l2c_address;
  // int response_code = find_l2c_address(&l2c_address);
  // switch (response_code)
  // {
  //   case address_found:
  //     break;
  //   case address_not_found:
  //     Serial.println(responses[address_not_found].message);
  //     exit(address_not_found);
  //   case no_device_connected:
  //     Serial.println(responses[no_device_connected].message);
  //     exit(no_device_connected);
  //   default:
  //     Serial.println(responses[no_device_connected].message);
  //     exit(no_device_connected);
  // }



  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("***************");
  lcd.setCursor(0,3);
  lcd.print("***************");

  delay(4000);
  lcd.setCursor(0,2);
  lcd.print("Hello World");
  


}

void loop() {
  // byte error, address;
  // int nDervices = 0;
  // Serial.println("Scanner...");
  
  // for(address = 1; address < 127; address++){
  //   Wire.beginTransmission(address);
  //   error = Wire.endTransmission();
  //   if(error == 0){
  //     Serial.print("I2C device found at address 0x");
  //     if(address < 16){
  //       Serial.print("0");
  //     }
  //     Serial.println(address, HEX);
  //     nDervices++;
  //   }

  //   if(error == 4){
  //     Serial.print("Unknown error at address 0x");
  //     if(address < 16){
  //       Serial.print("0");
  //     }
  //   }
  // }

  // if(nDervices == 0){
  //   Serial.println("No I2C devices found\n");
  // }else{
  //   Serial.println("done\n");
  // }
}