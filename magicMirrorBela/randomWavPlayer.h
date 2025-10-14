#pragma once
#include <string>
#include <vector>
#include <Bela.h>
#include <sndfile.h>

class randomWavPlayer {
public:
    explicit randomWavPlayer(const std::string& folderPath);
    void begin();
    void playRandom();
    bool isPlaying() const;
    float process();

private:
    void scanFolder();
    std::string pickRandomFile();

    std::string folder;
    std::vector<std::string> wavFiles;
    std::vector<float> buffer;
    bool isPlayingFlag = false;
    int sampleRate = 0;
    int channels = 0;
    size_t currentIndex = 0;
};
