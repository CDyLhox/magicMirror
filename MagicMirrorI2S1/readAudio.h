//
// Created by cashu on 13/09/2025.
//
//TODO - having a buffer inside save and read audio isnt very pretty,
// fix later and make it a class of its own

#pragma once
#include <iostream>
#include <fstream>
#include <Arduino.h>
#include <SD.h>


class ReadAudio {
public:
  ReadAudio(unsigned int bufferSize);
  ~ReadAudio();

  void deleteBuffer();
  void readFromFile(int timestamp);
  double read();

private:

  double *buffer = nullptr;
  unsigned int bufferSize = 0;

  const std::string sourcePath = SOURCE_DIR;
  std::fstream fin;

  int readHead = 0;
};

