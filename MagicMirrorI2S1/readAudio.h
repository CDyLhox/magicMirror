//
// Created by cashu on 13/09/2025.
//

#pragma once
#include "global.h"
#include <iostream>
#include <fstream>


class ReadAudio {
public:
  ReadAudio(int bufferSize);
  ~ReadAudio();

  void deleteBuffer();
  void readFromFile(int timestamp);
  double read();

private:

  double *buffer = nullptr;
  int bufferSize = 0;
  int readHead = 0;

  File fin;
};

