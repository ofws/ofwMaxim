#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void mouseDragged(int x, int y, int button);
    void audioOut(ofSoundBuffer &buffer);
    
    unsigned bufferSize, sampleRate, startTime, endTime, currentTime;
    double frequency, currentSample;
    double outputs[2];
    
    maxiOsc osc, mod;
    maxiEnv env;
    maxiMix mix;
    
    maxiFFT fft;
    maxiFFTOctaveAnalyzer oct;
};
