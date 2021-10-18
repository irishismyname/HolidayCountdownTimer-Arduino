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

const String nameOfDay             = "Christmas";

//                                   (d)
const unsigned long daysPreset     = 20L;
unsigned long daysUntil            = daysPreset;
unsigned long lastDaysUntil        = daysPreset;
unsigned long dayNumber            = 1L;

//                                    (h)             (mm)         (ss)
const unsigned long mSecondsPreset = ((4L) *60L*60L + (59L) *60L + (0L)) * 1000L;
unsigned long mSecondsInToday      = mSecondsPreset;
const unsigned long mSecondsInDay  = 24L * 60L * 60L * 1000L;
const unsigned long mSecondsTotal  = daysUntil * mSecondsInDay + mSecondsPreset;

bool firstDay                      = true;
bool done                          = false;

String messageLine1;
String messageLine2;

void setup() { 
  lcd.begin(16, 2);
}

void loop() {
  if (firstDay && millis() > mSecondsPreset) {
    dayNumber += 1;
    daysUntil -= 1;
    firstDay = false;
    mSecondsInToday = mSecondsInDay;
  } else if (millis() > mSecondsPreset && millis() - mSecondsPreset > (dayNumber - 1L) * mSecondsInDay) {
    dayNumber += 1;
    daysUntil -= 1;
    mSecondsInToday = mSecondsInDay;
  }

  if (millis() >= mSecondsTotal) {
    done = true;
  }

  if (done) {
    messageLine1 = "It's " + nameOfDay + "!";
  } else {
    messageLine1 = nameOfDay + " " + String(daysUntil) + " Day";
    messageLine2 = String(( mSecondsPreset + mSecondsInToday * (dayNumber - 1L) - millis() )/1000L) + " Seconds";
  }
  
  //display
  lcd.setCursor(0,0);
  lcd.print(messageLine1);
  lcd.setCursor(0,1);
  lcd.print(messageLine2);
}