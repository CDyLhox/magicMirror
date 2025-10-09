//
// Created by cashu on 15/02/2025.
//
#pragma once

class CircularBuffer {
public:
  CircularBuffer() = default;
  CircularBuffer(unsigned int bufferSize, double numSamplesDelay);
  ~CircularBuffer();

  void setBufferSize(int bufferSize);
  int getBufferSize();
  //numSamplesDelay double to read between samples
  void setNumSamplesDelay(double numSamplesDelay);
  double getNumSamplesDelay();

  //updateDelay gets called in setNumSamplesDelay
  void updateDelay();
  void wrap(int &head);

  double read();
  double readBetweenSamples();
  void write(double sample);

private:
  double* buffer= nullptr;
  int bufferSize;

  int readHead = 0;
  int writeHead = 0;
  double sampleOffset = 0.0;
  double numSamplesDelay = 0.0;

};
