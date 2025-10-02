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
       Serial.println("ReadAudio - constructor");

    this->bufferSize = bufferSize;

    //Allocating buffer
    buffer = new double[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

ReadAudio::~ReadAudio(){
    Serial.println("ReadAudio - destructor");
    deleteBuffer();
}

void ReadAudio::readFromFile(int timestamp){

  String filename = SOURCE_DIR_BIN + "/" + timestamp + ".dat";

    //reconstructs the filename when given the proper timestamp

    //FIXME: deze is broken, na een tijdje schrijft hij alleen nog lege timestamps weg
    fin = SD.open(filename.c_str(), FILE_READ);

    if (!fin) {
            Serial.println("Error opening file!");
    }
    else {
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
    double output = buffer[readHead];
    readHead++;

    return output;
}


void ReadAudio::deleteBuffer(){
    delete [] buffer;
    buffer = nullptr;
}
