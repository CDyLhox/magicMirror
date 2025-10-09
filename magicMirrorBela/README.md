Haai cas, de issue die we nu ervaren is dat de combinatie van audioReader->readFromFile(49060 + Serial.println(audioReader->read())); op lijn 142van de magicMirrorI2S1.ino

Ik den k dat het komt door het feit dat je doubles gebruikte voor de buffer, ik heb die veranderd naar int16_t block ints voor de teensy want die wilt dat graag


CAS AANTEKLENINGEN:
  //if this happens, you dont want the intended writeToFile call to work --> writeToFileBool to check
  if(buffer.size() == buffer.max_size()){
    writeToFile(timestamp);
  } --> dit houden maar omschrijven want dit is niet meer hoe vector werkt (saveFile.cpp)

Willen we in_16t nog gebruiken?
NEE!!!!!

## Voor cas:
ik heb in globals.h net je timer veranderd, krijg nu geen error meer maar snap ook niet wat ik heb gedaan dus die moet je even checken


