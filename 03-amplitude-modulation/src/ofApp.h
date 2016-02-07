#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void mouseMoved(int x, int y );
    void audioOut(ofSoundBuffer &buffer);
    
    double outputs[2];
    unsigned bufferSize, sampleRate;
    double frequency, modSpeed, currentSample;
    maxiOsc osc, modulator;
    maxiMix mix;
};
