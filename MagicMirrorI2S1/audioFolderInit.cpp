#include "audioFolderInit.h"
#include <Arduino.h>
#include <SD.h>

audioFolderInit::audioFolderInit(int chipSelect)
{
    Serial.println("audioplayer::audioplayer - constructor");
    Serial.print("Initializing SD card...");

    cs = chipSelect;
    if (!SD.begin(cs)) {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");

    // Make sure all folders exist
    createFolder();
}

audioFolderInit::~audioFolderInit()
{
    Serial.println("audioplayer destructor");
    freeAudioBinaryFolder();
}

void audioFolderInit::createFolder()
{
    Serial.println("audioPlayer::createFolder()");

    // Samples folder
    if (SD.exists("magicMirror/samples")) {
        Serial.println("magicMirror/samples folder already exists");
    } else {
        if (SD.mkdir("magicMirror/samples")) {
            Serial.println("Created magicMirror/samples directory");
        } else {
            Serial.println("Failed to create magicMirror/samples directory");
        }
    }
    // audio binaries folder
    if (SD.exists("magicMirror/audioBinaries")) {
        Serial.println("binaries folder exists");
    } else {
        if (SD.mkdir("magicMirror/audioBinaries")) {
            Serial.println("created magicMirror/audioBinaries");
        } else {
            Serial.println("Failed to create magicmirror/audioBinaries directory");
        }
    }
}

void audioFolderInit::freeAudioBinaryFolder()
{
    SD.rmdir("magicMirror/audioBinaries");
    Serial.println("removing magicMirror/audioBinaries");
}
