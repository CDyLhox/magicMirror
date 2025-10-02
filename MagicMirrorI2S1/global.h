//
// Created by cashu on 10/09/2025.
//

#pragma once
#include <Streaming.h>
#include <Vector.h>
#include <String>
#include <SD.h>
#include <SPI.h>
elapsedMillis millistimer;

String SOURCE_DIR_BIN = "magicMirror/audioBinaries";


//TODO - FIXME
int timestamp = 10;




int filenames[1000];

  int fileIndex = 0;

  void pushToArray(int timestamp){
      filenames[0] = timestamp;
      fileIndex++;
  }