//
// Created by cashu on 10/09/2025.
//

#include "saveAudio.h"
#include <string>
#include <iostream>

SaveAudio::SaveAudio(){
	std::cout << "SaveAudio - constructor" << std::endl;
}

SaveAudio::~SaveAudio(){
	std::cout << "SaveAudio - destructor" << std::endl;
}

//this is called to write the buffer away after it's full
void SaveAudio::writeToFile(int timestamp){
    std::cout << "SaveAudio::writeToFile() " << std::endl;
    std::cout << timestamp << std::endl;
    
	std::string filename = SOURCE_DIR_BIN + "/" + std::to_string(timestamp) + ".dat";

  if (writeToFileBool == true){

    fout.open(filename, std::ios::out | std::ios::binary);

    if (!fout) {
        std::cout << "Error opening file!" << std::endl;
      }
    else {

      bufferSize = buffer.size();

      //writes the buffer away to a binary file
      fout.write(reinterpret_cast<char*>(&buffer[0]), bufferSize * sizeof(double));
      fout.close();

      pushToArray(int(timestamp), int(bufferSize));
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


