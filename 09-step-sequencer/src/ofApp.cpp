#include "ofApp.h"
void ofApp::setup(){
    ofBackground(0);
    
    sampleRate = 44100;
    bufferSize = 512;
    ofSoundStreamSetup(2,0,this,sampleRate,bufferSize,4);
    
    startTime = ofGetElapsedTimeMillis();
    endTime = 200;
    
    stepAmount = 32;
    sequencerX = sequencerY = 0;
    sequencerWidth = ofGetWidth();
    stepSize = ofGetWidth()/stepAmount;
    gap = 5;
    
    for (unsigned i = 0; i<5; i++) {
        stringstream s;
        s << i+1 << ".wav";
        seqs.push_back(unique_ptr<Sequencer>(new Sequencer(sequencerX + gap, sequencerY + i*(stepSize + gap) + gap, sequencerWidth, s.str(), stepAmount, gap)));
    }
    current = 0;
    ofSetWindowShape(stepAmount*(stepSize+gap) +gap, seqs.size()*(stepSize+gap) +gap);
}
void ofApp::update(){
    currentTime = ofGetElapsedTimeMillis() - startTime;
    if (currentTime >= endTime) {
        current = ++current % stepAmount;
        for (seqCollection::iterator it = seqs.begin(); it!= seqs.end(); it++) {
            (*it)->rewind();
        }
        startTime = ofGetElapsedTimeMillis();
    }
}
void ofApp::draw(){
    for (seqCollection::iterator it = seqs.begin(); it!= seqs.end(); it++) {
        (*it)->render(current);
    }
}
void ofApp::mousePressed(int x, int y, int button){
    unsigned yPos = floor((float) y / (stepSize + gap));
    unsigned xPos = floor((float) x / ofGetWidth()*stepAmount);
    seqs[yPos]->steps[xPos].pressed();
}
void ofApp::audioOut(ofSoundBuffer &buffer){
    for (unsigned i =0; i<bufferSize; i++){
        currentSample = 0;
        for (seqCollection::iterator it = seqs.begin(); it!= seqs.end(); it++) {
            if ((*it)->steps[current].on) {
                currentSample += (*it)->sample.playOnce() / seqs.size();
            }
        }
        mix.stereo(currentSample, outputs, 0.5);
        buffer[i*buffer.getNumChannels()] = outputs[0];
        buffer[i*buffer.getNumChannels()+1] = outputs[1];
    }
}