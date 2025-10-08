//
// Created by cashu on 10/09/2025.
//


#pragma once
#include <Streaming.h>
#include <String>
#include <Vector.h>
#include <string>
#include <ctime>

time_t timestamp;
extern int fileIndex;
extern int fileDataSize;
extern int fileData[][2]; 
extern std::string SOURCE_DIR_BIN;

extern float peakValuePotRead;
extern float peakVal;
extern float gainPotRead;

extern const int chipSelect;

void pushToArray(unsigned long timestamp, int fileSize);

void printAnalogData();

