//
// Created by cashu on 10/09/2025.
//

#pragma once
#include <Streaming.h>
#include <Vector.h>
#include <String>

#include <SPI.h>

String SOURCE_DIR = "magicMirror/audioBinaries";


int filenames[1000];

int index = 0;

void pushToArray(int timestamp){
    file[0] = timestamp;
    index++;
}