//
// Created by cashu on 10/09/2025.
//

#pragma once
#include "global.h"
#include <fstream>
#include <vector>


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
  std::vector<double> buffer;

  std::fstream fout;
};
