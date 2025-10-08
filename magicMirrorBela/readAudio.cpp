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
       std::cout << "ReadAudio - constructor" << std::endl;

    this->bufferSize = bufferSize;

    //Allocating buffer
    int16_t* buffer;
buffer = new int16_t[bufferSize];
    
    //LEMme try it this way cause teensy likes int16_t audio
    //buffer = new double[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

ReadAudio::~ReadAudio(){
    std::cout << "ReadAudio - destructor" << std::endl;
    deleteBuffer();
}

void ReadAudio::readFromFile(int timestamp){
  std::string filename = SOURCE_DIR_BIN + "/" + std::to_string(timestamp) + ".dat";

    //reconstructs the filename when given the proper timestamp
    fin.open(filename, std::ios::in | std::ios::binary);

    if (!fin) {
            std::cout << "ReadAudio::readFromFile. Error opening file!" << std::endl;
    }
    else {

        std::cout << "ReadAudio::readFromFile, fileread succes 👍" << std::endl;
        //writes the binary file to the array 'buffer'
        fin.read(reinterpret_cast<char*>(buffer), bufferSize * sizeof(double));
        fin.close();

        //clearing everything for next use
        readHead = 0;
        deleteBuffer();
    }
}

//you can call this after calling readFromFile to read from array 'buffer'
double ReadAudio::read(){
    Serial.println("readAudio::Read()");
    //Again, added int16t for the audio of teensy
    int16_t output = buffer[readHead];
    readHead++;

    return output;
}


void ReadAudio::deleteBuffer(){
    delete [] buffer;
    buffer = nullptr;
}
