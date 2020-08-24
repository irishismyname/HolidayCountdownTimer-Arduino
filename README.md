# HolidayCountdownTimer-Arduino
This is a very simple countdown timer I build with my daughter every year in the fall to make 16x2 countdown timers for Halloween, Thanksgiving, Christmas, and her birthday. I used the schematic from [makerguides.com](https://www.makerguides.com/character-lcd-arduino-tutorial/). The gist of it is captured in this diagram from makerguies.com: ![Circuit Schematic](https://www.makerguides.com/wp-content/uploads/2019/05/16x2-character-lcd-with-arduino-uno-wiring-diagram-schematic.jpg).
## Setup
1. Set the constant `nameOfDay` to the name of the event you're counting down to. You may have to abbrevaite if it's not fitting on the screen.
2. Set the constant `daysPreset` to the number of whole days until the event.
3. Set the constant `secondsPreset` to represent the number of seconds left in the day today.  
**Note:** You can fill `daysPreset` and `secondsPreset` in based on another countdown timer such as [Halloween](https://days.to/until/halloween), [Thanksgiving](https://days.to/until/thanksgiving), or [Christmas](https://days.to/until/christmas). 
## Build/Run
Nothing new here, just open the file in the Arduino IDE and upload it [(Reference)](https://www.arduino.cc/en/Main/Howto). Every time you reboot this, it will reset the countdown to start from the presets defined above, so be ready to change those 😅.
## Troubleshooting
If I had any sense, I would have written down some troubleshooting tips as they occurred. Needless to say... I did not. If the LCD has a row of white boxes, the wiring is not correct. If you get some jumbled up mess on the screen, also probably not wired correctly. Don't forget to adjust the potentiometer until it looks right!
## Enhancements
This of course would benefit greatly from a [realtime clock](https://www.adafruit.com/product/3296), but most of this code would be useless if you had one.
