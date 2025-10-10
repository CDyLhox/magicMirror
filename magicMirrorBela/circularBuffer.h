//
// Created by cashu on 15/02/2025.
//
#pragma once

class CircularBuffer {
public:
  CircularBuffer() = default;
  CircularBuffer(unsigned int bufferSize, int numSamplesDelay);
  ~CircularBuffer();

  void setBufferSize(int bufferSize);
  int getBufferSize();
  //numSamplesDelay double to read between samples
  void setNumSamplesDelay(int numSamplesDelay);
  int getNumSamplesDelay();

  //updateDelay gets called in setNumSamplesDelay
  void updateDelay();
  void wrap(int &head);

  double read();
  void write(double sample);

private:
  double* buffer= nullptr;
  int bufferSize;

  int readHead = 0;
  int writeHead = 0;
  int numSamplesDelay = 0;

};
