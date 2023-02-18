/*
  Mini Weather STation

  The project is designed to measure the temperature 
  and humidity and output it on a display.

  This sketch demonstrates the use the DHT11 sensor and LCD module
  Using the LiquidCrystal and DFRobot_DHT11 library

  The circuit:
  LCD:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   10K resistor:
  DHT:
   ends to +5V and ground
   wiper/signal to LCD VO pin (pin 3)

  written by Busoye Tolulope Matthew 
  GDSC UI Hardware/IOT

*/

// include the library code:
#include <LiquidCrystal.h>
#include <DFRobot_DHT11.h>
// define pin in which the dht11 is connected to
#define DHT11_PIN 7

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DFRobot_DHT11 DHT;
// Declare the bit array for the degree symbol to be displayed by the lcd module
byte customChar[8] = {
  0b00110,
  0b01001,
  0b01001,
  0b00110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  // set up the LCD's number of columns and rows:

  lcd.createChar(2, customChar);
  lcd.begin(16, 2);

//  lcd.write((uint8_t)2);
}


void loop() {
  // set the cursor to (0,0):

    char buffer[50] = {0};
  
    DHT.read(DHT11_PIN);
    sprintf(buffer, "The current temperature is: %d %cC", DHT.temperature,2);
    lcdPrint(buffer);
  
    delay(3000);
    sprintf(buffer, "The current humidity is: %d %%", DHT.humidity);
    lcdPrint(buffer);
  
    delay(3000);

}


// A print function to print a string on the lcd module
void lcdPrint(const char* string) {
  lcd.clear();
  lcd.noAutoscroll();
  lcd.setCursor(0, 0);
  int i = 0;
  while (i < strlen(string)) {
    if (i == 16) {
      lcd.setCursor(0, 1);
    }

    lcd.print(string[i]);
    i++;
  }
  lcd.noAutoscroll();
}
