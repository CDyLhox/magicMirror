#ifndef _AUDIOFOLDERINIT_H_
#define _AUDIOFOLDERINIT_H_

#include <iostream>

#include "global.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

class audioFolderInit {
private:
    void createFolder();
    void freeAudioBinaryFolder();

public:
    int amountOfFiles;
    int cs;

    inline bool dirExists(std::string path)
    {
        struct stat info;
        return stat(path.c_str(), &info) == 0 && (info.st_mode & S_ISDIR);
    }
    inline bool createDir(std::string path)
    {
        return mkdir(path.c_str(), 0755) == 0;
    }
    inline bool removeDir( std::string path)
    {
        return rmdir(path.c_str()) == 0;
    }

    audioFolderInit(int chipSelect);
    ~audioFolderInit();
};

#endif
