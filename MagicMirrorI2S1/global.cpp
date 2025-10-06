#include "global.h"

elapsedMillis timestamp;
int fileIndex = 0;

// Array with [filename/timestamp, fileSize]
int fileData[100][2];
// THIS SHOULD MATCH THE NUMBER THATS IN THE FIRST BRACKETS OF fileData
int fileDataSize = 100;

String SOURCE_DIR_BIN = "magicMirror/audioBinaries";

// FIXME: the int timestamp is 2 bytes bigger than a char can get. so the teensy starts rebootmaxxing
void pushToArray(unsigned long timestamp, int fileSize)
{
    if (fileIndex < 100) {
        Serial.println("globals pushtoarray");
        fileData[fileIndex][0] = timestamp;
        fileData[fileIndex][1] = fileSize;
        fileIndex++;
    } else {
        Serial.println("global::pushToArray overflow error");
    };
}
