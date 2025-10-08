
/*
 ____  _____ _        _
| __ )| ____| |      / \
|  _ \|  _| | |     / _ \
| |_) | |___| |___ / ___ \
|____/|_____|_____/_/   \_\
http://bela.io
*/
/**
\example Fundamentals/minimal/render.cpp

The bare bones: the structure of a render.cpp file
--------------------------------------------------

A render.cpp file has three functions: `setup()`, `render()` and `cleanup()`.

`setup()` is an initialisation function which runs before audio rendering begins.
It is called once when the project starts. Use it to prepare any memory or
resources that will be needed in `render()`.

`render()` is a function that is regularly called, over and over continuously, at
the highest priority by the audio engine. It is used to process audio and
sensor data. This function is called regularly by the system every time there
is a new block of audio and/or sensor data to process.

`cleanup()` is a function that is called when the program stops, to finish up any
processes that might still be running.

Here we will briefly explain each function and the structure of the render.cpp

Before any of the functions
---------------------------
At the top of the file, include any libraries you might need.

Additionally, declare any global variables. In these tutorial sketches, all
global variables are preceded by a `g` so we always know which variables are
global - `gSampleData`, for example. It's not mandatory but is a really good way
of keeping track of what's global and what's not.

Sometimes it's necessary to access a variable from another file, such as
main.cpp. In this case, precede this variable with the keyword `extern`.

Function arguments
------------------
`setup()`, `render()` and `cleanup()` each take the same arguments. These are:

`BelaContext *context`
`void *userData`

These arguments are pointers to data structures. The main one that's used is
`context`, which is a pointer to a data structure containing lots of information
you need.

Take a look at what's in the data structure in the API reference tab.

You can access any of these bits of information about current audio and sensor
settings and pointers to data buffers that are contained in the data structure
like this: `context->name_of_item`.

For example, `context->audioInChannels` returns the number of audio input channels.
`context->audioSampleRate` returns the audio sample rate.
`context->audioIn[n]` would give you the current input sample (assuming that
your input is mono - if it's not you will have to account for multiple channels).

Note that `audioIn`, `audioOut`, `analogIn`, `analogOut` are all arrays (buffers).
*/

#include <sndfile.h>      // for reading audio files
#include <vector>         // dynamic arrays for samples
#include <string>         // standard strings
#include <iostream>       // logging / debugging
#include <cmath>          // math for trim + normalize
#include <random>         // random file selection
#include <Bela.h>


#include "audioFolderInit.h"
#include "global.h"
#include "saveAudio.h" 
#include "readAudio.h"

//Audioplayer initialisation
audioFolderInit* folderInit;

//AudioSaverReaderinitilisaion
SaveAudio* audioSaver;
ReadAudio* audioReader; 

int gainPotPin = 21;
int ledPin = 23;
int peakValuePot = 20;
// setup() is called once before the audio rendering starts.
// Use it to perform any initialisation and allocation which is dependent
// on the period size or sample rate.
//
// Return true on success; returning false halts the program.
bool setup(BelaContext *context, void *userData)
{
    folderInit = new audioFolderInit(chipSelect);
    audioSaver = new SaveAudio();
    audioReader = new ReadAudio(44100/2);

   // pinMode(ledPin, OUTPUT);
  //digitalWrite(ledPin, HIGH);

	return true;
}


void render(BelaContext *context, void *userData)
{
    for(unsigned int n = 0; n < context->audioFrames; n++) {

        float out_l = 0;
        float out_r = 0;

        // Read audio inputs
        out_l = audioRead(context,n,0);
        out_r = audioRead(context,n,1);

        //TODO: add fx here 

        audioSaver->write(out_l);

        // Write the sample into the output buffer -- done!
        audioWrite(context, n, 0, out_l);
        audioWrite(context, n, 1, out_r);
    }
}

// cleanup() is called once at the end, after the audio has stopped.
// Release any resources that were allocated in setup().

void cleanup(BelaContext *context, void *userData)
{
    delete folderInit;
    delete audioSaver;
    delete audioReader;
}
