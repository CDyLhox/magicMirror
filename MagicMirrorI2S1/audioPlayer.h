#ifndef _AUDIOPLAYER_H_
#define _AUDIOPLAYER_H_

#include <iostream>
#include <SD.h>

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
