//
// Created by cashu on 10/09/2025.
//

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <Arduino.h>
#include <SD.h>


class SaveAudio {
public:
  SaveAudio();
  ~SaveAudio();

  void writeToFile(int timestamp);
  void write(double sample);
  unsigned int getBufferSize();



private:
  unsigned int bufferSize = 0;
  std::vector<double> buffer;

  const std::string sourcePath = SOURCE_DIR;
  std::fstream fout;
};
