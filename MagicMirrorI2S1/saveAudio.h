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

  //length of array as maxBufferLength
  float storage_array[88200];

  File fout;
};
