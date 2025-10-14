//
// Created by cashu on 13/09/2025.
//
#include "readAudio.h"

//For Dylan:
//HOW TO USE -
// 1. call 'readFromFile' with the timestamp of the file you want to read
//    --> now there is a buffer with the data from the binary file
// 2. use 'read' to get the values out of the buffer

ReadAudio::ReadAudio(int bufferSize){
       //std::cout << "ReadAudio - constructor" << std::endl;

    this->bufferSize = bufferSize;

    //Allocating buffer
    buffer = new double[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

ReadAudio::~ReadAudio(){
    // std::cout << "ReadAudio - destructor" << std::endl;
    deleteBuffer();
}

void ReadAudio::readFromFile(int timestamp){
	std::string filename = SOURCE_DIR + "audioBinaries/" + std::to_string(timestamp) + ".dat";

    //reconstructs the filename when given the proper timestamp
    fin.open(filename, std::ios::in | std::ios::binary);

    if (!fin) {
            std::cout << "ReadAudio::readFromFile: Error opening file!" << std::endl;
    }
    else {
        //writes the binary file to the array 'buffer'
        fin.read(reinterpret_cast<char*>(buffer), bufferSize * sizeof(double));
        fin.close();

        //std::cout << "ReadAudio::readFromFile= " << filename << "\n ReadAudio Buffer= " << buffer <<std::endl;
    }
}

//you can call this after calling readFromFile to read from array 'buffer'
double ReadAudio::read(){
    double output = buffer[readHead];
    readHead++;

    //std::cout << "readAudio::read()" << std::endl;
    if(readHead == bufferSize){
        deleteBuffer();
        readHead = 0;
    }

    return output;
}


void ReadAudio::deleteBuffer(){
  if(buffer == nullptr){
    std::cout << "ReadAudio::deleteBuffer(); buffer already deleted" << std::endl;
  }
  else{
    delete [] buffer;
    buffer = nullptr;
  }
}
