#include "ofApp.h"
void ofApp::setup(){
    sampleRate = 44100;
    bufferSize = 512;
    frequency = 440;
    
    ofSoundStreamSetup(2,0,this,sampleRate,bufferSize,4);
    
    env.setAttack(2000);
    env.setDecay(1);
    env.setSustain(1);
    env.setRelease(3000);
}

void ofApp::keyPressed(int key){
    env.trigger = 1;
}
void ofApp::keyReleased(int key){
    env.trigger = 0;
}
void ofApp::mouseMoved(int x, int y ){
    env.setAttack(ofMap(x, 0, ofGetWidth(), 500, 4000, true));
}

void ofApp::audioOut(ofSoundBuffer &buffer){
    for (unsigned i =0; i<bufferSize; i++){
        currentSample = env.adsr(osc.sinewave(frequency), env.trigger);
        mix.stereo(currentSample, outputs, 0.5);
        buffer[i*buffer.getNumChannels()] = outputs[0];
        buffer[i*buffer.getNumChannels()+1] = outputs[1];
    }
}
