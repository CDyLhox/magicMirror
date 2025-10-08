//
// Created by cashu on 10/09/2025.
//

#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#include <SD.h>
#include <SPI.h>
#include <Streaming.h>
#include <String>
#include <Vector.h>


// TODO - FIXME
extern elapsedMillis timestamp;
extern int fileIndex;
extern int fileDataSize;
extern int fileData[][2]; 
extern String SOURCE_DIR_BIN;

void pushToArray(unsigned long timestamp, int fileSize);

#endif
