#include "randomWavPlayer.h"

randomWavPlayer::randomWavPlayer(const std::vector<std::string>& files)
    : wavFiles(files) {}

void randomWavPlayer::begin() {
    if(wavFiles.empty()) {
        std::cout << "No wav files provided!" << std::endl;
    } else {
        std::cout << wavFiles.size() << " wav files ready." << std::endl;
    }
}

std::string randomWavPlayer::pickRandomFile() {
    if(wavFiles.empty()) return "";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, wavFiles.size() - 1);
    return wavFiles[dist(gen)];
}

void randomWavPlayer::playRandom() {
    if(wavFiles.empty()) {
        // std::cout << "nothing to play" << std::endl;
        return;
    }

    std::string file = pickRandomFile();
    // std::cout << "playing " << file << std::endl;

    SF_INFO sfInfo;
    SNDFILE* sndFile = sf_open(file.c_str(), SFM_READ, &sfInfo);
    if(!sndFile) {
        std::cerr << "Error opening " << file << std::endl;
        return;
    }

    buffer.resize(sfInfo.frames * sfInfo.channels);
    sf_read_float(sndFile, buffer.data(), buffer.size());
    sf_close(sndFile);

    sampleRate = sfInfo.samplerate;
    channels = sfInfo.channels;
    currentIndex = 0;
    isPlayingFlag = true;
}

bool randomWavPlayer::isPlaying() const {
    return isPlayingFlag;
}

float randomWavPlayer::process() {
    if(!isPlayingFlag || buffer.empty()) return 0.0f;

    float sample = buffer[currentIndex];
    currentIndex++;
    if(currentIndex >= buffer.size()) {
        isPlayingFlag = false;
        currentIndex = 0;
    }
    return sample;
}