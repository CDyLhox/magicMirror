#ifndef RANDOM_WAV_PLAYER_H
#define RANDOM_WAV_PLAYER_H

#include <Arduino.h>
#include <vector>

class AudioPlaySdWav;

class randomWavPlayer {
public:
    randomWavPlayer(AudioPlaySdWav &audioPlayer, const char *folder = "/");
    void begin();
    void rescan();
    void playRandom();
    bool isPlaying();

private:
    AudioPlaySdWav &audioPlayer;
    const char *folderPath;
    std::vector<String> wavFiles;

    String pickRandomFile();
};

#endif