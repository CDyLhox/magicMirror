#include "global.h"

time_t timestamp;
int fileIndex = 0;

const int chipSelect = 10;
float peakValuePotRead;
float peakVal;
// Array with [filename/timestamp, fileSize]
int fileData[100][2];
// THIS SHOULD MATCH THE NUMBER THATS IN THE FIRST BRACKETS OF fileData
int fileDataSize = 100;

std::string SOURCE_DIR_BIN = "magicMirror/audioBinaries";

void pushToArray(unsigned long timestamp, int fileSize)
{
    if (fileIndex < 100) {
        std::cout << "globals pushtoarray" << std::endl;
        fileData[fileIndex][0] = timestamp;
        fileData[fileIndex][1] = fileSize;
        fileIndex++;
    } else {
        std::cout << "globals::pushtoarray overflow error" << std::endl;
    };
}

void printAnalogData()
{
    std::cout
        << "peakValuePotRead / 2000:     " << peakValuePotRead / 2000 << "\n"
        << "gainPotRead/2000:            " << gainPotRead / 2000 << "\n"
        << "peakValue:                   " << peakVal
        << std::endl;
}
