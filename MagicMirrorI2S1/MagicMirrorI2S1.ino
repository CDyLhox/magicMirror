#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "audioFolderInit.h"
#include "global.h"
#include "saveAudio.h" 
#include "readAudio.h"

// GUItool: begin automatically generated code
AudioInputAnalog adc1(A2);
AudioAmplifier amp1;
AudioEffectDelay delay1;
AudioOutputPT8211_2 pt8211_2_1;
AudioOutputI2S i2s1;            //TODO: i2s1 ombouwen
AudioAnalyzePeak peak1;         //xy=512,410
AudioEffectEnvelope envelope1;  //xy=580,48
AudioControlSGTL5000 sgtl5000_1;
AudioRecordQueue queue1;

AudioConnection patchCord1(adc1, amp1);
AudioConnection patchCord2(amp1, delay1);
AudioConnection Patchcord(amp1, peak1);
AudioConnection Patchcord5(delay1, envelope1);
AudioConnection patchCord3(envelope1, 0, i2s1, 0);
AudioConnection patchCord4(envelope1, 0, i2s1, 1);
AudioConnection PatchCord6(envelope1, 0, queue1, 0);




//Audioplayer initialisation
const int chipSelect = 10;
audioFolderInit* folderInit;

//AudioSaverReaderinitilisaion
SaveAudio* audioSaver;
ReadAudio* audioReader; 


int gainPotPin = 21;
float gainPotRead = 1;
int ledPin = 23;
int peakValuePot = 20;
float peakValuePotRead;
float peakVal;

void setup() {

  //quick serial because i like em nice and responsive 
  Serial.begin(115200);

  //While not serial, dont do shit.
  while (!Serial) {
    ;
  }
  
  folderInit = new audioFolderInit(chipSelect);
  Serial.println("i made it past audiofolder");
  audioSaver = new SaveAudio();
  audioReader = new ReadAudio(44100/2);
  Serial.println("i made a saveaudi");

  //setup the audiomem please also the alanog read reso q
  AudioMemory(240);
  analogReadResolution(12);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  //From here on out its audio functions
  //sset the speaker on, set the amp gain, yuh, and set the delay, delay, 
  amp1.gain(1.0);
  delay1.delay(0, 1000);

  sgtl5000_1.enable();
  sgtl5000_1.volume(20);

  delay1.delay(0, 300);

  //Envelope functions
  envelope1.attack(10);
  envelope1.hold(50);
  envelope1.decay(100);
  envelope1.sustain(0.5);
  envelope1.release(300);

  // start the que to record the incoming mic values
  queue1.begin();
  playTestAudio();
}


void loop() {

 // printMyInfo();
  if (queue1.available() > 0) { printMyAudio(); }

  gainPotRead = analogRead(gainPotPin);

  peakValuePotRead = analogRead(peakValuePot);
  amp1.gain(gainPotRead / 2000);  // Resolution of 0 to 4 instead of 0 to 4048

  if (peak1.available()) {
    peakVal = peak1.read();

    if (peakVal > peakValuePotRead / 4000) {  // root 4000 cause you want it from 0 to 1

      envelope1.noteOn();
      delay(300);
      envelope1.noteOff();
    }
  }
}

void printMyInfo() {
  Serial.print("peakvaluepotread / 2000:  ");
  Serial.println(peakValuePotRead / 4000);
  Serial.print("gainPotRead / 2000:       ");
  Serial.println(gainPotRead / 2000);
  Serial.print("peakValue:                ");
  Serial.println(peakVal);
}

void printMyAudio() {
  int16_t* block = queue1.readBuffer();
  if (block) {
    for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
      int16_t sample = block[i];
      double normalized = sample / 32768.0;
      audioSaver->write(normalized);
      //Serial.println(normalized, 6); //the normalised print is hard on the workload of the cpu
    }
    queue1.freeBuffer();
  }
  
}

void playTestAudio(){
  audioReader->readFromFile(49060);
 //Serial.println(audioReader->read()); 
 Serial.println("hallo we zijn er voorbij"); 
}
