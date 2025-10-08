//
// Created by cashu on 10/09/2025.
//

#pragma once
#include "global.h"
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>


class SaveAudio {
public:
  SaveAudio();
  ~SaveAudio();

  void writeToFile(int timestamp);
  void write(double sample);
  int getBufferSize();

private:
  bool writeToFileBool = true;
  int bufferSize = 0;
  Vector<double> buffer;

  //length of array as maxBufferLength
  //THIS MIGHT BE TOO MUCH --> USE 2 BUFFERS BUCKET BRIGADE!!!!!! steeds kleine buffers wegschrijven
  double storage_array[44100];

  File fout;
};
