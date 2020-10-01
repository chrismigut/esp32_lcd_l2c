// #include <Arduino.h>
// #include <Wire.h>

// /* find the l2c address of the 20x4 lcd */

// /* References:
//     https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/
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

// const int time_delay = 5000;

// void setup() {
//   Wire.begin();
//   Serial.begin(115200);
//   Serial.println("\nI2C Scanner");

// }

// void loop() {
//   byte error, address;
//   int nDevices = 0;
//   Serial.println("Scanner...");
  
//   for(address = 1; address < 127; address++){
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();
//     if(error == 0){
//       Serial.print("I2C device found at address 0x");
//       if(address < 16){
//         Serial.print("0");
//       }
//       Serial.println(address, HEX);
//       nDevices++;
//     }

//     if(error == 4){
//       Serial.print("Unknown error at address 0x");
//       if(address < 16){
//         Serial.print("0");
//       }
//     }
//   }

//   if(nDevices == 0){
//     Serial.println("No I2C devices found\n");
//   }else{
//     Serial.println("done\n");
//   }
//   delay(time_delay);
// }