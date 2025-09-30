#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputAnalog adc1(A2);√
AudioInputAnalog adc2(A3);
AudioAmplifier amp1;
AudioAmplifier amp2;
AudioEffectDelay delay1;

AudioOutputPT8211_2 pt8211_2_1;
AudioAnalyzePeak peak1;         //xy=512,410
AudioEffectEnvelope envelope1;  //xy=580,488
AudioEffectDelay delay2;
AudioEffectFreeverb freeverb1;
AudioEffectFreeverb freeverb2;
AudioFilterStateVariable filter1;
AudioFilterStateVariable filter2;
AudioEffectGranular granular1;


AudioConnection patchCord1(adc1, amp1);
AudioConnection patchCord13(adc2, amp2);
AudioConnection patchCord24(amp1, delay1);
AudioConnection patchCord255(amp2, delay2);
AudioConnection Patchcord76(amp1, peak1);
AudioConnection Patchcord58(delay1, freeverb1);
AudioConnection Patchcord56(delay2, freeverb2);
AudioConnection PatchCord72(freeverb1, 0, filter1, 0);
AudioConnection PatchCord74(freeverb2, 0, filter2, 0);
AudioConnection patchCord33(filter1, 0, pt8211_2_1, 0);
AudioConnection patchCord70(filter2, 0, pt8211_2_1, 0);




// AudioConnection Patchcord(amp1, granular1);
// AudioConnection patchCord3(granular1, 0, pt8211_2_1, 0);
// AudioConnection patchCord4(granular1, 0, pt8211_2_1, 1);

// AudioConnection patchCord3(amp1, 0, pt8211_2_1, 0); // STRAIGHT PASSTHROUGH FOR TESTING AND SANITY

// File csvFile;


int ledPin = 23;

void setup() {
  Serial.begin(9600);

  AudioMemory(240);
  amp1.gain(0.9);
  analogReadResolution(12);
  delay1.delay(0, 1000);


  pinMode(ledPin, OUTPUT);

  filter1.frequency(2000.0);
  freeverb1.roomsize(0.5);
  freeverb1.damping(0.5);

  // granular1.begin(64, 256);
  // granular1.setSpeed(0.6);

  digitalWrite(ledPin, HIGH);

  delay1.delay(0, 300);

  // csvFile = SD.open("audio.csv", FILE_WRITE);
  // if (!csvFile) {
  //   Serial.println("Failed to open file!");
  //   while(1);
  // }
}


void loop() {
  // granular1.beginFreeze(100);
  // delay(100);
}
