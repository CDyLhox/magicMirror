//
// Created by cashu on 10/09/2025.
//

#pragma once
#include "global.h"
#include <SD.h>

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
  std::string file = test.dat

  std::string sourcePath = SOURCE_DIR;
};