#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void audioOut(ofSoundBuffer& buffer);
		
    maxiOsc osc, panner, freqMod;
    maxiMix mix;
    double outputs[2];
    double frequency, currentSample;
    unsigned bufferSize, sampleRate;
};
