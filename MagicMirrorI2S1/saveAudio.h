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
  Vector<float> buffer;

  //length of array as maxBufferLength (now 10 sec)
  float storage_array[441000];

  File fout;
};
