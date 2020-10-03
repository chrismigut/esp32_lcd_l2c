// #include <Arduino.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include "i2c_address_locator.h"

// /* find the l2c address of the 20x4 lcd (assume only 1 device)*/

// /* References:
//     https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/
//     binary to hex: https://stackoverflow.com/a/41173236
// */

// /* Parts List:
//     lcd model SCL2004A:
//     jameco part no: 2304015  
//     https://www.jameco.com/shop/ProductDisplay?catalogId=10001&langId=-1&storeId=10001&productId=2304015 

//     MELIFE ESP32 model: B07Q576VWZ
//     https://www.amazon.com/MELIFE-Development-Dual-Mode-Microcontroller-Integrated/dp/B07Q576VWZ/ref=sr_1_3?dchild=1&keywords=ESP32&qid=1601348830&sr=8-3
// */

// /* ESP32 Pins:
//     22 : SCL
//     21 : SDA
// */

// /* I2C Defualt Address
//     4x20 lcd: 0x27
// */

// const uint8_t ROWS = 4;
// const uint8_t COLS = 20;

// const uint8_t TIME_DELAY = 2000;

// void display_text(LiquidCrystal_I2C lcd, char * text_to_display, bool scroll_enabled){
//   lcd.setCursor(0,0);

//   if(scroll_enabled){lcd.scrollDisplayRight();}
  
//   lcd.print(text_to_display);
// }

// void setup() {
//   Wire.begin();
//   Serial.begin(115200);
//   Serial.println("\nI2C Scanner");

//   LiquidCrystal_I2C lcd(find_i2c_address(), COLS, ROWS);

//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0,0);
//   lcd.print("***************");
//   lcd.setCursor(0,3);
//   lcd.print("***************");

//   delay(4000);
//   lcd.setCursor(0,2);
//   lcd.print("Hello World");
  
//   delay(TIME_DELAY);
//   lcd.clear();

//   display_text(lcd, "test", true);

// }

// void loop() {
// }