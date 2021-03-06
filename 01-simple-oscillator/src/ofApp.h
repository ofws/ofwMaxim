#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void mouseMoved(int x, int y );
    void audioOut(ofSoundBuffer& buffer);
    
    maxiOsc osc;
    double frequency, currentSample;
    unsigned bufferSize, sampleRate;
		
};
