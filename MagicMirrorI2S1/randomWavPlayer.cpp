#include "randomWavPlayer.h"
#include <Audio.h>
#include <SD.h>

randomWavPlayer::randomWavPlayer(AudioPlaySdWav &audioPlayer, const char *folder)
    : audioPlayer(audioPlayer), folderPath(folder) {}

void randomWavPlayer::begin() {
    // first scan to load up wav files
    rescan();
}

void randomWavPlayer::rescan() {
    wavFiles.clear();

    File dir = SD.open(folderPath);
    if (!dir) {
        Serial.printf("couldn't open folder: %s\n", folderPath);
        return;
    }

    // walk through folder, grab any .wav files
    File entry;
    while ((entry = dir.openNextFile())) {
        if (!entry.isDirectory()) {
            String name = entry.name();
            if (name.endsWith(".wav") || name.endsWith(".WAV")) {
                String fullPath = String(folderPath);
                if (!fullPath.endsWith("/")) fullPath += "/";
                fullPath += name;

                wavFiles.push_back(fullPath);
                Serial.printf("found %s\n", fullPath.c_str());
            }
        }
        entry.close();
    }

    dir.close();

    if (wavFiles.empty()) {
        Serial.println("no .wav files found");
    } else {
        Serial.printf("%d wav files loaded from %s\n", wavFiles.size(), folderPath);
    }
}

String randomWavPlayer::pickRandomFile() {
    if (wavFiles.empty()) return "";
    int index = random(wavFiles.size());
    return wavFiles[index];
}

void randomWavPlayer::playRandom() {
    if (wavFiles.empty()) {
        Serial.println("nothing to play");
        return;
    }

    String file = pickRandomFile();
    Serial.printf("playing %s\n", file.c_str());

    audioPlayer.play(file.c_str());
    delay(10);  // short pause to let playback start
}

bool randomWavPlayer::isPlaying() {
    return audioPlayer.isPlaying();
}