//
// Created by cashu on 13/09/2025.
//
#include "readAudio.h"

// For Dylan:
// HOW TO USE -
//  1. call 'readFromFile' with the timestamp of the file you want to read
//     --> now there is a buffer with the data from the binary file
//  2. use 'read' to get the values out of the buffer

ReadAudio::ReadAudio(int bufferSize)
{

    Serial.println("ReadAudio - constructorStart");
    this->bufferSize = bufferSize;
    Serial.print("bufferSize: ");
    Serial.println(bufferSize);

    // Allocating buffer
    buffer = new double[bufferSize];
    Serial.println("halfway in readaudio");
    // LEMme try it this way cause teensy likes int16_t audio
    // buffer = new double[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
    Serial.println("ReadAudio - constructorEnd");
}

ReadAudio::~ReadAudio()
{
    Serial.println("ReadAudio - destructor");
    deleteBuffer();
}

void ReadAudio::readFromFile(int timestamp)
{
    String filename = SOURCE_DIR_BIN + "/" + timestamp + ".dat";

<<<<<<< HEAD
    //reconstructs the filename when given the proper timestamp
=======
    // reconstructs the filename when given the proper timestamp

    // FIXME: deze is broken, na een tijdje schrijft hij alleen nog lege timestamps weg
>>>>>>> e7b6eb73342542108d1199f9c815ae5bc641fda7
    fin = SD.open(filename.c_str(), FILE_READ);

    if (!fin) {
        Serial.println("ReadAudio::readFromFile. Error opening file!");
    } else {

        // writes the binary file to the array 'buffer'
        fin.read(reinterpret_cast<char*>(buffer), bufferSize * sizeof(double));
        Serial.println("ReadAudio::readFromFile, fileread succes 👍2");
        fin.close();

        // clearing everything for next use
        readHead = 0;
        deleteBuffer();
    }
}

// you can call this after calling readFromFile to read from array 'buffer'
double ReadAudio::read()
{
    Serial.println("readAudio::Read()");
    // Again, added int16t for the audio of teensy
    int16_t output = buffer[readHead];
    readHead++;

    return output;
}

void ReadAudio::deleteBuffer()
{
    delete[] buffer;
    buffer = nullptr;
}
