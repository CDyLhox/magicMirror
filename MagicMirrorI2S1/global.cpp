#include "global.h"

elapsedMillis timestamp;
int fileIndex = 0;
char filenames[100]; 

String SOURCE_DIR_BIN = "magicMirror/audioBinaries";

void pushToArray(int value) {
    filenames[0] = timestamp;
    fileIndex++;

}

