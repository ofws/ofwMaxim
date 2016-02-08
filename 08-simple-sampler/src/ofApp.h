#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void keyPressed(int key);
    void audioOut(ofSoundBuffer &buffer);

    unsigned bufferSize, sampleRate;
    double currentSample;
    double outputs[2];
    
    maxiSample sample;
    maxiMix mix;
    
};
