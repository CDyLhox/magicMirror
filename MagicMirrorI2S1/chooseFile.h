#include <iostream>
#include "global.h"
#include "random"

class ChooseFile {
public:
  ChooseFile();
  ~ChooseFile();

  int chooseFile();

  int findFileIndex(int file);

  int compareFileLength();
  int returnOldestFile();
  //int prevFile the best option?
  int returnNextFile(int prevFile);


private:
  //TODO - zou dit duidelijker zijn, of gewoon 0 en 1
  // //used for array indexes
  // int filename = 0;
  // int fileSize = 1;

};