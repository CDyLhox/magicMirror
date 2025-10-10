//
// Created by cashu on 10/09/2025.
//


#pragma once
#include <string>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <ctime>


extern time_t timestamp;

extern std::string SOURCE_DIR;

//Push to array
extern int fileIndex;
extern const int fileDataSize;
extern int fileData[][2]; 

void pushToArray(unsigned long timestamp, int fileSize);


//print analog data
extern float peakValuePotRead;
extern float peakVal;
extern float gainPotRead;

extern const int chipSelect;

void printAnalogData();

