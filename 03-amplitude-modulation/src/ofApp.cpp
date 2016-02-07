#include "ofApp.h"
void ofApp::setup(){
    sampleRate = 44100;
    bufferSize = 512;
    ofSoundStreamSetup(2,0,this,sampleRate,bufferSize,4);
    frequency = 440;
    modSpeed = 2;
}

void ofApp::mouseMoved(int x, int y ){
    modSpeed = (double)ofMap(x, 0, ofGetWidth(), 0, 50);
}

void ofApp::audioOut(ofSoundBuffer &buffer){
    for (unsigned i = 0; i < bufferSize; i++){
        currentSample = osc.saw(frequency) * modulator.sinewave(modSpeed);
//        currentSample = osc.saw(frequency) * modulator.square(modSpeed);
        mix.stereo(currentSample, outputs, 0.5);
        
        buffer[i*buffer.getNumChannels()] = outputs[0];
        buffer[i*buffer.getNumChannels() + 1] = outputs[1];
    }
}