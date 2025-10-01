//
// Created by cashu on 10/09/2025.
//

#pragma once
#include "global.h"
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
//#include <StandardCplusplus.h>

class SaveAudio {
public:
  SaveAudio(int maxBufferLength);
  ~SaveAudio();

  void writeToFile(int timestamp);
  void write(double sample);
  int getBufferSize();

private:
  bool writeToFileBool = true;
  int bufferSize = 0;
  Vector<double> buffer;

  File fout;
};
