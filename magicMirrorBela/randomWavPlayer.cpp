#include "randomWavPlayer.h"
#include <dirent.h>
#include <iostream>
#include <random>

randomWavPlayer::randomWavPlayer(const std::string& folderPath)
    : folder(folderPath) {}

// scans the folder for .wav files
void randomWavPlayer::scanFolder() {
    wavFiles.clear();
    DIR* dir = opendir(folder.c_str());
    if(!dir) {
        rt_printf("Could not open folder: %s\n", folder.c_str());
        return;
    }

    struct dirent* entry;
    while((entry = readdir(dir)) != nullptr) {
        std::string name = entry->d_name;
        if(name == "." || name == "..")
            continue;

        // only grab files that end with .wav or .WAV
        if(name.size() >= 4) {
            std::string ext = name.substr(name.size() - 4);
            if(ext == ".wav" || ext == ".WAV") {
                std::string fullPath = folder + "/" + name;
                wavFiles.push_back(fullPath);
                rt_printf("Found wav: %s\n", fullPath.c_str());
            }
        }
    }
    closedir(dir);

    if(wavFiles.empty())
        rt_printf("No .wav files found in %s\n", folder.c_str());
    else
        rt_printf("Loaded %zu wav files from %s\n", wavFiles.size(), folder.c_str());
}

// init - scans folder once
void randomWavPlayer::begin() {
    scanFolder();
}

// picks a random file from the list
std::string randomWavPlayer::pickRandomFile() {
    if(wavFiles.empty()) return "";
    // random select a file
    int index = rand() % wavFiles.size();
    return wavFiles[index];
}

// loads and starts playing a random file
void randomWavPlayer::playRandom() {
    if(wavFiles.empty()) {
        rt_printf("No wav files to play\n");
        return;
    }

    std::string file = pickRandomFile();
    rt_printf("Playing %s\n", file.c_str());

    SF_INFO sfInfo;
    SNDFILE* sndFile = sf_open(file.c_str(), SFM_READ, &sfInfo);
    if(!sndFile) {
        rt_printf("Error opening %s\n", file.c_str());
        return;
    }

    // load data into buffer
    buffer.resize(sfInfo.frames * sfInfo.channels);
    sf_read_float(sndFile, buffer.data(), buffer.size());
    sf_close(sndFile);

    sampleRate = sfInfo.samplerate;
    channels = sfInfo.channels;
    currentIndex = 0;
    isPlayingFlag = true;

    rt_printf("Loaded %zu samples at %d Hz (%d channels)\n", buffer.size(), sampleRate, channels);
}

// quick check if it's still playing
bool randomWavPlayer::isPlaying() const {
    return isPlayingFlag;
}

// feed out one sample per call
float randomWavPlayer::process() {
    if(!isPlayingFlag || buffer.empty()) return 0.0f;

    float sample = buffer[currentIndex++];

    // once buffer is done, stop playback
    if(currentIndex >= buffer.size()) {
        isPlayingFlag = false;
        currentIndex = 0;
    }
    return sample;
}