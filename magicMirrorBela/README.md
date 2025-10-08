Haai cas, de issue die we nu ervaren is dat de combinatie van audioReader->readFromFile(49060 + Serial.println(audioReader->read())); op lijn 142van de magicMirrorI2S1.ino

Ik den k dat het komt door het feit dat je doubles gebruikte voor de buffer, ik heb die veranderd naar int16_t block ints voor de teensy want die wilt dat graag

void ReadAudio::readFromFile(int timestamp){
  String filename = SOURCE_DIR_BIN + "/" + timestamp + ".dat";

    //reconstructs the filename when given the proper timestamp

    //FIXME: deze is broken, na een tijdje schrijft hij alleen nog lege timestamps weg
    fin = SD.open(filename.c_str(), FILE_READ);

    if (!fin) {
            Serial.println("ReadAudio::readFromFile. Error opening file!");
    }
    else {

        Serial.println("ReadAudio::readFromFile, fileread succes 👍");
        //writes the binary file to the array 'buffer'
        fin.read(reinterpret_cast<char*>(buffer), bufferSize * sizeof(double));
        fin.close();

        //clearing everything for next use
        readHead = 0;
        deleteBuffer();
    }
}

//you can call this after calling readFromFile to read from array 'buffer'
double ReadAudio::read(){
    Serial.println("readAudio::Read()");
    //Again, added int16t for the audio of teensy
    int16_t output = buffer[readHead];
    readHead++;

    return output;
}

void ReadAudio::deleteBuffer(){
    delete [] buffer;
    buffer = nullptr;
}


/hansa plast watervaste witte tape soortvan bij de kruidvat

audio library als doubles of als floates? 
