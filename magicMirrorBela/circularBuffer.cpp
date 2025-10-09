//
// Created by cashu on 15/02/2025.
//
#include "circularBuffer.h"
#include <iostream>
#include "interpolation.h"

CircularBuffer::CircularBuffer(unsigned int bufferSize, double numSamplesDelay) {
    // std::cout << "constructor - Circular Buffer" << std::endl;
    this->bufferSize = bufferSize;

   //Allocating buffer
    buffer = new double[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
    this->numSamplesDelay = numSamplesDelay;
    updateDelay();
    sampleOffset = numSamplesDelay - this->numSamplesDelay;
}

CircularBuffer::~CircularBuffer(){
    delete [] buffer;
    buffer = nullptr;
}


void CircularBuffer::setBufferSize(int bufferSize){
    this->bufferSize = bufferSize;

    //Delete old buffer
    if (buffer != nullptr) {
        delete [] buffer;
        buffer = nullptr;
    }

    //Set new buffer with new buffersize
    buffer = new double[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

int CircularBuffer::getBufferSize(){return bufferSize;}

double CircularBuffer::getNumSamplesDelay() {return numSamplesDelay;}


void CircularBuffer::setNumSamplesDelay(double numSamplesDelay) {
    if (numSamplesDelay < 0) {
        std::cout << "CircularBuffer::setNumSamplesDelay - numSamplesDelay exceeds range [0, inf]"
                << numSamplesDelay << std::endl;
    }
    else {
        this->numSamplesDelay = floor(numSamplesDelay);
        sampleOffset = numSamplesDelay - this->numSamplesDelay;
        updateDelay();
    }
}



void CircularBuffer::write(double sample) {
    buffer[writeHead] = sample;
    wrap(++writeHead);
}

//FIXME - this doesnt work
double CircularBuffer::readBetweenSamples() {
  //read the value, put in output , then increment the readHead
    double sample = buffer[readHead];
    readHead++;
    wrap(readHead);
    double nextSample = buffer[readHead];

    //TODO - does this work? -- numSamplesDelay is now double and sampleOffset is calculated with that
    //Interpolating between sample and nextSample
    double output = Interpolation::linMap(sampleOffset, sample, nextSample);

    return output;
}

double CircularBuffer::read() {
    double output = buffer[readHead];
    readHead++;
    wrap(readHead);
    return output;
}

void CircularBuffer::updateDelay() {
    readHead = writeHead - numSamplesDelay + bufferSize;
    //readHead gets changed--> so wrap
    wrap(readHead);
}


void CircularBuffer::wrap(int &head) {
    if(head >= bufferSize) {
        head -= bufferSize;
    }
}
