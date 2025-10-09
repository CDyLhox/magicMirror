#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S i2s1;
AudioInputAnalog adc1(A2);
AudioAmplifier amp1;
AudioEffectDelay delay1;
AudioEffectFreeverb freeverb1;
AudioFilterStateVariable filter1;
AudioOutputI2S audioShield;
AudioControlSGTL5000 sgtl5000_1;

AudioConnection patchCord1(i2s1, 0, amp1, 0);
AudioConnection patchCord2(amp1, 0, delay1, 0);
AudioConnection patchCord3(delay1, 0, freeverb1, 0);
AudioConnection patchCord4(freeverb1, 0, filter1, 0);

//AudioConnection patchCord5(filter1, 0, audioShield, 0);
//AudioConnection patchCord6(filter1, 0, audioShield, 1);

AudioConnection patchCord5(adc1, 0, audioShield, 0);
AudioConnection patchCord6(adc1, 0, audioShield, 1);
int ledPin = 23;

void setup() {

  sgtl5000_1.enable();
  sgtl5000_1.volume(1);
  sgtl5000_1.inputSelect(AUDIO_INPUT_MIC);
  sgtl5000_1.micGain(30);

  Serial.begin(9600);

  Serial.println("MictestMagicMir2.ino -- setup§");
  AudioMemory(120);
  amp1.gain(2);


  analogReadResolution(12);


  pinMode(ledPin, OUTPUT);

  filter1.frequency(2000.0);
  freeverb1.roomsize(0.5);
  freeverb1.damping(0.5);


  digitalWrite(ledPin, HIGH);

  delay1.delay(0, 300);

}


void loop() {
}
