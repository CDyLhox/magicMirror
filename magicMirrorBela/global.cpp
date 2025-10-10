#include "global.h"

time_t timestamp;

const int chipSelect = 10;
float peakValuePotRead;
float peakVal;

std::string SOURCE_DIR = "/root/Bela/projects/magicMirrorBela/files/";



//------------------------PUSH TO ARRAY---------------------------------- (SHOULDVE USED A CIRC BUFFER LOL)

int fileIndex = 0;

// Array with [filename/timestamp, fileSize]
const int fileDataSize = 100;
int fileData[fileDataSize][2];

void pushToArray(unsigned long timestamp, int fileSize)
{
    if (fileIndex < fileDataSize) {
        std::cout << "globals pushtoarray" << std::endl;
        fileData[fileIndex][0] = timestamp;
        fileData[fileIndex][1] = fileSize;
        fileIndex++;
    } else {
        std::cout << "globals::pushtoarray overflow error" << std::endl;
    };
}



//--------------------------------------PRINT ANALOG DATA----------------------------------------------------
void printAnalogData()
{
    std::cout
        << "peakValuePotRead / 2000:     " << "peakValuePotRead / 2000" << "\n"
        << "gainPotRead/2000:            " << "gainPotRead / 2000" << "\n"
        << "peakValue:                   " << "peakVal"
        << std::endl;
}
