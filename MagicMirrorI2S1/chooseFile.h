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

};