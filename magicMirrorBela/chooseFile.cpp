//
// Created by cashu on 23/09/2025.
//

#include "chooseFile.h"

ChooseFile::ChooseFile(){
    std::cout << "ChooseFile - Constructor" << std::endl;
}

ChooseFile::~ChooseFile(){
    std::cout << "ChooseFile - Destructor" << std::endl;
}


//CHOOSEFILE IS THE ONLY FUNCTION YOU NEED TO CALL
int ChooseFile::chooseFile(int prevFile){
  random = rand() % 3;
  
  if(random == 0){
  	compareFileLength();
  }
  else if(random == 1){
  	returnNextFile(prevFile);
  }
  else returnOldestFile();
}

//This code can be written more efficient but for the sake of readability, I have decided not to
//(the 2 for loops can be fused into 1)
int ChooseFile::compareFileLength(){
  //TODO - explain why to use fileIndex here
  int initSize = fileData[fileIndex][1];

  int difference[fileIndex];

  //make an array with the difference between initSize and the length of the files in the array
  for(int i = 0; i < fileIndex; i++){
    difference[i] = abs(initSize - fileData[i][1]);
  }

  int minVal = difference[0];
  int minValIndex = 0;
  //find smallest value
    for(int i = 0; i < fileIndex; i++){
      if(difference[i] < minVal) {
        minVal = difference[i];
        minValIndex = i;
      }
    }  

  return fileData[minValIndex][0];
}


int ChooseFile::findFileIndex(int file){
     for(int i = 0; i < fileIndex; i++){
        if(fileData[i][0] == file) return i;
     }
}

int ChooseFile::returnNextFile(int prevFile){
    int indexNextFile = findFileIndex(prevFile) + 1;
    return fileData[indexNextFile][0];
}

int ChooseFile::returnOldestFile(){
    return fileData[i][0];
    //to prevent the code from playing the same file over and over again
    i++;
}
