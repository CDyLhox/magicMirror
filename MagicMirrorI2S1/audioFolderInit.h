#ifndef _AUDIOFOLDERINIT_H_
#define _AUDIOFOLDERINIT_H_

#include <iostream>
#include <SD.h>

#include "global.h"

class audioPlayer {
private:
  void createFolder();
  void freeAudioBinaryFolder();
public:
  int amountOfFiles;
  int cs;
  audioPlayer(int chipSelect);
  ~audioPlayer();
};

#endif
