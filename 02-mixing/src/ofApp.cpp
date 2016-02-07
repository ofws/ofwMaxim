#include "ofApp.h"

void ofApp::setup(){
    sampleRate = 44100;
    bufferSize = 512;
    ofSoundStreamSetup(2,0,this,sampleRate,bufferSize,4);
    frequency = 220;
}

void ofApp::audioOut(ofSoundBuffer& buffer){
    for (unsigned i = 0; i<bufferSize; i++) {
        currentSample = (osc.sinewave(frequency+freqMod.sinewave(2)))*.5;
        mix.stereo(currentSample, outputs, (panner.sinewave(1)+1)/2);
        buffer[i*buffer.getNumChannels()] = outputs[0];
        buffer[i*buffer.getNumChannels()+1] = outputs[1];

    }
}
