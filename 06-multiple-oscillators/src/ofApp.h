#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

struct Key{
    maxiOsc osc;
    maxiEnv env;
    double frequency;
    
    Key(double _f){
        frequency = _f;
        env.setAttack(2000);
        env.setDecay(1);
        env.setSustain(1);
        env.setRelease(3000);
    }
    inline double play(){
        return env.adsr(osc.square(frequency),env.trigger);
    }
    inline void on(){
        env.trigger = 1;
    }
    inline void off(){
        env.trigger = 0;
    }
};

class ofApp : public ofBaseApp{

public:
    void setup();

    void keyPressed(int key);
    void keyReleased(int key);
    void audioOut(ofSoundBuffer &buffer);
    
    unsigned bufferSize, sampleRate;
    double currentFrame;
    double outputs[2];
    
    maxiMix mix;
    vector<unique_ptr<Key>> keys;
    
    
};
