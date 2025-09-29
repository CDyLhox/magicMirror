//
// Created by cashu on 10/09/2025.
//
#include "saveAudio.h"
#include <ctime>
#include <string>


SaveAudio::SaveAudio(){
  std::cout << "buffer - constructor" << std::endl;
}

SaveAudio::~SaveAudio(){
  std::cout << "buffer - destructor" << std::endl;
}

//TODO - how can readAudio find the file when it doesnt know the name?
// --> maybe give timestamp with it on a higher level?
void SaveAudio::writeToFile(int timestamp){

  std::string file = sourcePath + "/" + std::to_string(timestamp) +  ".dat    ";
  fout.open(file, std::ios::out | std::ios::binary);

  if (!fout) {
    std::cout << "Error opening file!" << std::endl;
  }
  else {
    bufferSize = buffer.size();
    fout.write(reinterpret_cast<char*>(&buffer[0]), buffer.size() * sizeof(double));
    fout.close();

  // for (int j = 0; j < bufferSize; j++) {
  //     std::cout << buffer[j] << std::endl;
  // }

    buffer.clear();
  }

}

void SaveAudio::write(double sample){
  // std::cout << "writing" << std::endl;
  buffer.push_back(sample);
}

unsigned int SaveAudio::getBufferSize() {
  return bufferSize;
}


