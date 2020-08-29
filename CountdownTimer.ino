//This creates a countdown timer to the presets defined in daysPreset and secondsPreset
//and outputs to a 16 character x 2 line LCD

//Pinout
//Function        LCD       : Arduino
//-----------------------------------
//Ground          VSS or GND: GND
//Power           VDD or VCC: 5v
//Contrast        Vo  or VE :  output from 50k pot across 5v and GND
//Register Select RS        : pin 2
//Read/write      RW        : GND
//Enable          E         : pin 3
//Data 4          D4        : pin 4
//Data 5          D5        : pin 5
//Data 6          D6        : pin 6
//Data 7          D7        : pin 7
//LED Power       A         : 5v
//LED GND         L         : GND

#include <LiquidCrystal.h>

//               (RS E  D4 D5 D6 D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const String nameOfDay            = "Halloween";
//                                  (d)
const unsigned long daysPreset    = 62L;
unsigned long daysUntil           = daysPreset;
unsigned long lastDaysUntil       = daysPreset;
unsigned long dayNumber           = 1L;
//                                  (h)             (mm)         (ss)
unsigned long secondsPreset       = (16L) *60L*60L + (13L) *60L + (0L);
const unsigned long secondsInDay  = 24L * 60L * 60L;
unsigned long millisLeftInDay = secondsPreset * 1000L;
bool firstScan                    = true;

void setup() { 
  lcd.begin(16, 2);
}

void loop() {
  millisLeftInDay = secondsPreset*1000L*dayNumber - millis();

  if (millis() > secondsInDay * 1000L * dayNumber) {
    daysUntil -= 1L;
    secondsPreset = secondsInDay;
    dayNumber += 1L;
  } 
  
  //display
  lcd.setCursor(0,0);
  lcd.print(nameOfDay + ": " + String(daysUntil) + " Dy");
  lcd.setCursor(0,1);
  lcd.print(String(secondsPreset*dayNumber - millis()/1000L) + " Seconds");

  firstScan = false;
}