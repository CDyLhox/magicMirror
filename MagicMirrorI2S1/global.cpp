#include "global.h"


elapsedMillis millistimer;
unsigned long timestamp = 0;
int fileIndex = 0;
char filenames[100]; 

String SOURCE_DIR_BIN = "magicMirror/audioBinaries";

void pushToArray(int value) {
    filenames[0] = timestamp;
    fileIndex++;

}

