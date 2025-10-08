#ifndef _AUDIOFOLDERINIT_H_
#define _AUDIOFOLDERINIT_H_

#include <iostream>
#include <SD.h>

#include "global.h"

class audioFolderInit{
private:
  void createFolder();
  void freeAudioBinaryFolder();
public:
  int amountOfFiles;
  int cs;
  audioFolderInit(int chipSelect);
  ~audioFolderInit();
};

#endif
