//
// Created by cashu on 23/09/2025.
//

#include "chooseFile.h"

ChooseFile::ChooseFile(){
  Serial.println("ChooseFile - constructor");
}

ChooseFile::~ChooseFile(){
  Serial.println("ChooseFile - destructor");
}

int ChooseFile::chooseFile(){
  // filenames
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

//FIXME - DIT IS ALTIJD DEZELFDE FILE (wordt niet uit array verwijderd)
int ChooseFile::returnOldestFile(){
    return fileData[0][0];
}