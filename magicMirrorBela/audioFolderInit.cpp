#include "audioFolderInit.h"

audioFolderInit::audioFolderInit(int chipSelect)
{
    std::cout<<"audioplayer::audioplayer - constructor"<<std::endl;
    std::cout<<"Initializing SD card..." << std::endl;

    cs = chipSelect;
       // std::cout<<"INITIALISATION FAILED IN AUDIOFOLDER CONSTRUCTIO" <<std::endl;
        //return;

    // Make sure all folders exist
    createFolder();
}


audioFolderInit::~audioFolderInit()
{
    std::cout << "folderinit Destructor "<< std::endl;
    freeAudioBinaryFolder();
}

void audioFolderInit::createFolder()
{
    std::cout << "audioPlayer::createFolder() top" <<std::endl;

    


    // Samples folder
    if (dirExists("/projects/magicMirror/files/samples")) {
        std::cout << "magicMirror/samples folder already exists" << std::endl;
    } else {
        if (createDir("/projects/magicMirror/files/samples")) {
            std::cout << "created magicMirror/files/samples directory" << std::endl;
        } else {
            std::cout << "Failed to create magicmirror/files/samples directory" << std::endl;
        }
    }
    // audio binaries folder
    if (dirExists("/projects/magicMirror/files/audioBinaries")) {
        std::cout<<"binaries folder exists" << std::endl;
    } else {
        if (createDir("/projects/magicMirror/files/audioBinaries")) {
            std::cout << "created magicmirror/audiobinaries" << std::endl;
        } else {
            std::cout << "Failed to crreate magicmirror/audioBinaries Directory" << std::endl;
        }
    }
}

void audioFolderInit::freeAudioBinaryFolder()
{
    removeDir("/projects/magicMirror/files/audioBinaries");
    std::cout<<"removing /projects/magicMirror/files/audioBinaries" << std::endl;
}
