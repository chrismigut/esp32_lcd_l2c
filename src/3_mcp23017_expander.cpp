#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include "i2c_address_locator.h"

/* pactice using the mcp23017 expander*/

/* References:
    http://ww1.microchip.com/downloads/en/devicedoc/20001952c.pdf/
    https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
*/

/* Parts List:
    mcp23017:
    https://www.amazon.com/MCP23017-input-output-port-expander/dp/B00I6OEWJM/ref=pd_di_sccai_4/133-0371938-1959646?_encoding=UTF8&pd_rd_i=B00I6OEWJM&pd_rd_r=f016e794-b9bd-462b-89f9-b25632a9c5cd&pd_rd_w=4yx92&pd_rd_wg=nBjmX&pf_rd_p=5415687b-2c9d-46da-88a4-bbcfe8e07f3c&pf_rd_r=JRAM71N89YWGQ4R55TAG&psc=1&refRID=JRAM71N89YWGQ4R55TAG

    MELIFE ESP32 model: B07Q576VWZ
    https://www.amazon.com/MELIFE-Development-Dual-Mode-Microcontroller-Integrated/dp/B07Q576VWZ/ref=sr_1_3?dchild=1&keywords=ESP32&qid=1601348830&sr=8-3
*/

/* ESP32 Pins:
    22 : SCL
    21 : SDA
*/

/* mcp23017 expander
    setting the address of AO, A1, A2 to ground
*/

Adafruit_MCP23017 mcp; 
const int TIME_DELAY = 1000;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner - looking for mcp23017 address");
  Serial.print("address: ");

  mcp.begin();

  delay(TIME_DELAY);
  //Serial.println(find_i2c_address());
  delay(TIME_DELAY);


  // set the 16 IO pins to a default value of output
  for(int i = 0; i < 16; i++){
      mcp.pinMode(i, OUTPUT);
  }  
}

void loop() {
    for(int i = 0; i < 16; i++){
        mcp.digitalWrite(i, HIGH);
        Serial.printf("pin %d: High\n", i);
        delay(TIME_DELAY);

        mcp.digitalWrite(i, LOW);
        Serial.printf("pin %d: Low\n", i);
        delay(TIME_DELAY);
    }
}