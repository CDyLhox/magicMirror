#pragma once

#include <Bela.h>
#include <libraries/sndfile/sndfile.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <random>

class randomWavPlayer {
public:
    explicit randomWavPlayer(const std::vector<std::string>& files);
    void begin();
    void playRandom();
    bool isPlaying() const;
    float process();

private:
    std::string pickRandomFile();

    std::vector<std::string> wavFiles;
    std::vector<float> buffer;
    int sampleRate = 0;
    int channels = 0;
    size_t currentIndex = 0;
    bool isPlayingFlag = false;
};