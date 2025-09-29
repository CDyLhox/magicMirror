//
// Created by cashu on 13/09/2025.
//
#include "readAudio.h"
#include <string>


ReadAudio::ReadAudio(unsigned int bufferSize){
    std::cout << "buffer - constructor" << std::endl;

    this->bufferSize = bufferSize;

    //Allocating buffer
    buffer = new double[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

ReadAudio::~ReadAudio(){
    std::cout << "buffer - destructor" << std::endl;
    deleteBuffer();
}

void ReadAudio::readFromFile(int timestamp){

    std::string file = sourcePath + "/" + std::to_string(timestamp) +  ".dat    ";

    fin.open(file, std::ios::in | std::ios::binary);

    if (!fin) {
        std::cout << "Error opening file!" << std::endl;
    }
    else {
        fin.read(reinterpret_cast<char*>(buffer), bufferSize * sizeof(double));
        fin.close();

        readHead = 0;
        deleteBuffer();
    }
}

double ReadAudio::read(){
    double output = buffer[readHead];
    readHead++;

    return output;
}

void ReadAudio::deleteBuffer(){
    delete [] buffer;
    buffer = nullptr;
}
