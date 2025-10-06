#include "global.h"

elapsedMillis timestamp;
int fileIndex = 0;

//Array with [filename/timestamp, fileSize]
int fileData[100][2];
//THIS SHOULD MATCH THE NUMBER THATS IN THE FIRST BRACKETS OF fileData
int fileDataSize = 100; 

String SOURCE_DIR_BIN = "magicMirror/audioBinaries";

void pushToArray(int timestamp, int fileSize) {
    fileData[fileIndex][0] = timestamp;
    fileData[fileIndex][1] = fileSize;
    fileIndex++;
}