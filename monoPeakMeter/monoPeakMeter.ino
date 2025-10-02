/* Mono Peak Meter

   Scrolling peak audio level meter in the Arduino Serial Monitor
   adjusted for a mems microphone
   This example code is in the public domain
*/

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=119,52
AudioInputAnalog adc1(A2);
                                        //
AudioAnalyzePeak         peak1;          //xy=379,43
AudioConnection          patchCord1(adc1, 0, peak1, 0);
// GUItool: end automatically generated code

void setup() {
  AudioMemory(4);
  Serial.begin(9600);
}

// for best effect make your terminal/monitor a minimum of 31 chars wide and as high as you can.

elapsedMillis fps;

void loop() {
  if (fps > 24) {
    if (peak1.available()) {
      fps = 0;
      int monoPeak = peak1.read() * 30.0;
      Serial.print("|");
      for (int cnt=0; cnt<monoPeak; cnt++) {
        Serial.print(">");
      }

      Serial.println();
    }
  }
}
