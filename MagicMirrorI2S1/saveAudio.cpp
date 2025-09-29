//
// Created by cashu on 10/09/2025.
//
#include "saveAudio.h"
#include <string>


SaveAudio::SaveAudio(int maxBufferLength){
  std::cout << "buffer - constructor" << std::endl;

  float storage_array[int maxBufferLength];
  buffer.setStorage(storage_array); 
}

SaveAudio::~SaveAudio(){
  std::cout << "buffer - destructor" << std::endl;
}

//this is called to write the buffer away after it's full
void SaveAudio::writeToFile(int timestamp){
  String filename = audio;

  fout = SD.open(filename, FILE_WRITE);

  if (!fout) {
    std::cout << "Error opening file!" << std::endl;
  }
  //check if writeToFile has been called before
  else if (writeToFileBool == true){
  
    writeToFileBool = false;

    bufferSize = buffer.size();

    //writes the buffer away to a binary file
    fout.write(reinterpret_cast<char*>(&buffer[0]), buffer.size() * sizeof(double));
    fout.close();

    //clear buffer after use to make ready for next use
    buffer.clear();
  }
  else{
    //already written to file
    fout.close();
  }

}

//writes the sample to buffer
void SaveAudio::write(double sample){
  buffer.push_back(sample);

  //if this happens, you dont want the intended writeToFile call to work --> writeToFileBool to check
  if(vector.size() == vector.max_size){
    writeToFile()
  }
}

unsigned int SaveAudio::getBufferSize() {
  return bufferSize;
}


