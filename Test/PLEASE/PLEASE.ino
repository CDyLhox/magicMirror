#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

AudioInputI2S     i2s1;
AudioOutputI2S    audioShield;
AudioControlSGTL5000 sgtl5000_1;
AudioConnection   patch1(i2s1, 0, audioShield, 0);
AudioConnection   patch2(i2s1, 1, audioShield, 1);

void setup() {
  AudioMemory(12);
  Serial.begin(115200);
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(AUDIO_INPUT_MIC);  // or LINEIN if using line input
  sgtl5000_1.micGain(30);
  sgtl5000_1.volume(0.7);
}
void loop() {}

