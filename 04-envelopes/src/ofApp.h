#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
		
    void audioOut(ofSoundBuffer &buffer);
    unsigned bufferSize, sampleRate;
    double frequency, currentSample, currentVolume;
    double outputs[2];
    
    maxiOsc osc;
    maxiEnv env;
    maxiMix mix;
};
