#include "ofApp.h"
void ofApp::setup(){
    sample.load(ofToDataPath("boxing_bell.wav"));
    sampleRate = 44100;
    bufferSize = 512;
    ofSoundStreamSetup(2,0,this,sampleRate,bufferSize,4);
}
void ofApp::keyPressed(int key){
    sample.setPosition(0);
}
void ofApp::audioOut(ofSoundBuffer &buffer){
    for (unsigned i = 0; i<bufferSize; i++) {
        currentSample = sample.playOnce(1.0);
        mix.stereo(currentSample, outputs, 0.5);
        buffer[i*buffer.getNumChannels()] = outputs[0];
        buffer[i*buffer.getNumChannels()] = outputs[1];
    }
}