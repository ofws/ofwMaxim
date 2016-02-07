#include "ofApp.h"
void ofApp::setup(){
    sampleRate = 44100;
    bufferSize = 512;
    frequency = 440;
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
}

void ofApp::mouseMoved(int x, int y ){
    frequency = (double)ofMap(x, 0, ofGetWidth(), 50, 800);
}

void ofApp::audioOut(ofSoundBuffer& buffer){
    for (unsigned i = 0 ; i<bufferSize; i++) {
        currentSample = (osc.square(frequency))/2;
        buffer[i * buffer.getNumChannels()] = currentSample;
        buffer[i * buffer.getNumChannels()+1] = currentSample;
    }
}