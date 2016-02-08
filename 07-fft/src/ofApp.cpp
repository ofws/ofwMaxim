#include "ofApp.h"
void ofApp::setup(){
    sampleRate = 44100;
    bufferSize = 512;
    
    env.setAttack(2000);
    env.setDecay(1);
    env.setSustain(1);
    env.setRelease(3000);
    
    fft.setup(1024, 512, 256);
    oct.setup(44100, 1024, 10);
    
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
    
    startTime = ofGetElapsedTimeMillis();
    endTime = 1000;
}
void ofApp::update(){
    currentTime = ofGetElapsedTimeMillis() - startTime;
    if (currentTime >= endTime) {
        startTime = ofGetElapsedTimeMillis();
        env.trigger = 1;
    }
    else {
        env.trigger = 0;
    }
}
void ofApp::draw(){
    ofBackgroundGradient(ofColor(60), ofColor::black);
    
    for (int i = 0; i<oct.nAverages; i++) {
        ofColor col;
        col.setHsb((int)ofMap(i, 0, oct.nAverages, 0, 255), 255, 255);
        ofSetColor(col);
        
        float size = 1 + oct.averages[i]/10;
        int x = (int) (ofGetWidth()/2) * i/oct.nAverages + ofGetWidth()/4;
        
        ofDrawCircle(x, ofGetHeight()/2, size);
    }
}
void ofApp::mouseDragged(int x, int y, int button){
    frequency = ofMap(x, ofGetWidth(), 0, 3000, true);
}
void ofApp::audioOut(ofSoundBuffer &buffer){
    for (unsigned i = 0 ; i< bufferSize; i++) {
        currentSample = (env.adsr(osc.sinewave(frequency + mod.sinewave(1)*440),env.trigger))/2;
        if (fft.process(currentSample)) {
            oct.calculate(fft.magnitudes);
        }
        mix.stereo(currentSample, outputs, 0.5);
        buffer[i*buffer.getNumChannels()] = outputs[0];
        buffer[i*buffer.getNumChannels()+1] = outputs[1];
    }
}