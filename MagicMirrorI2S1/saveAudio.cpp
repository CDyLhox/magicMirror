//
// Created by cashu on 10/09/2025.
//
#include "saveAudio.h"
#include <Arduino.h>
#include <SD.h>
#include <string>


SaveAudio::SaveAudio(){
  Serial.println("SaveAudio - constructor");

  buffer.setStorage(storage_array); 
}

SaveAudio::~SaveAudio(){
  Serial.println("SaveAudio - destructor");
}

//this is called to write the buffer away after it's full
void SaveAudio::writeToFile(int timestamp){
    Serial.print("SaveAudio::writeToFile() ");
    Serial.println(timestamp);
  String filename = SOURCE_DIR_BIN + "/" + timestamp + ".dat";

  if (writeToFileBool == true){

    fout = SD.open(filename.c_str(), FILE_WRITE);

    if (!fout) {
        Serial.println("Error opening file!");
      }
    else {
      writeToFileBool = false;

      bufferSize = buffer.size();

      //writes the buffer away to a binary file
      fout.write(reinterpret_cast<char*>(&buffer[0]), bufferSize * sizeof(double));
      fout.close();

      pushToArray(unsigned long(timestamp), int(bufferSize));
      //clear buffer after use to make ready for next use
      buffer.clear();

    }
  }
}

//writes the sample to buffer
void SaveAudio::write(double sample){
  buffer.push_back(sample);

  //if this happens, you dont want the intended writeToFile call to work --> writeToFileBool to check
  if(buffer.size() == buffer.max_size()){
    writeToFile(timestamp);
  }
}

int SaveAudio::getBufferSize() {
  return bufferSize;
}


