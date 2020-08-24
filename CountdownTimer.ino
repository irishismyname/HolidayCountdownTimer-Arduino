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
const unsigned long daysPreset    = 67L;
unsigned long daysUntil           = daysPreset;
unsigned long lastDaysUntil       = daysPreset;
//                                  (h)              (mm)         (ss)
const unsigned long secondsPreset = (15L) *60L*60L + (21L) *60L + (0L);
unsigned long secondsUntil        = secondsPreset;
const unsigned long secondsInDay  = 24L * 60L * 60L;
bool firstScan                    = true;

void setup() { 
  lcd.begin(16, 2);
}

void loop() { 
  lastDaysUntil = daysUntil;
  unsigned long daysUntil = daysPreset + secondsPreset/60L/60L/24L - millis()/1000L/60L/60L/24L;
  
  //Reset seconds every time a new day starts
  if (daysUntil != lastDaysUntil)  {
    secondsUntil = secondsInDay;
  } 

  //display
  lcd.setCursor(0,0);
  lcd.print(nameOfDay + ": " + String(daysUntil) + " Dy");
  lcd.setCursor(0,1);
  lcd.print(String(secondsUntil - millis()/1000L) + " Seconds");

  firstScan = false;
}