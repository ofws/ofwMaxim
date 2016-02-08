#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"


struct Step {
    float x, y, size;
    bool on;
    void render(bool _this){
        if(on){
            ofSetColor(255,0,0);
        }
        else if(_this){
            ofSetColor(255,255,0);
        }
        else {
            ofSetColor(255);
        }
        ofDrawRectangle(x, y, size, size);
    }
    void pressed(){
        on = !on;
    }
};

struct Sequencer{
    unsigned stepAmount;
    float x,y,w,h;
    vector<Step> steps;
    maxiSample sample;
    
    Sequencer(float _x, float _y, float _w, string _sampleName, unsigned _stepAmount, int _gap){
        stepAmount = _stepAmount;
        sample.load(ofToDataPath(_sampleName));
        x = _x;
        y = _y;
        w = _w;
        h = _w/stepAmount;
        
        for (int i = 0; i< stepAmount; i++){
            Step temp;
            temp.size = h;
            temp.x = x + i*(temp.size + _gap);
            temp.y = y;
            temp.on = false;
            steps.push_back(temp);
        }
    }
    void rewind(){
        sample.setPosition(0);
    }
    void render(unsigned _current){
        for (int i = 0; i< stepAmount; i++){
            if(i == _current){
                steps[i].render(true);
            }
            else{
                steps[i].render(false);
            }
        }
    }
};

typedef vector<unique_ptr<Sequencer>> seqCollection;

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void audioOut(ofSoundBuffer &buffer);
    
    
    unsigned bufferSize, sampleRate, startTime, endTime, currentTime, current, stepAmount, gap;
    float stepSize, sequencerX, sequencerY, sequencerWidth;
    double currentSample;
    double outputs[2];
    
    maxiMix mix;
    seqCollection seqs;
    
};
