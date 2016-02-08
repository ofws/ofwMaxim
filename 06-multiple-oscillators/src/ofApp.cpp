#include "ofApp.h"
void ofApp::setup(){
    sampleRate = 44100;
    bufferSize = 512;
    
    ofSoundStreamSetup(2, 0,this, sampleRate, bufferSize,2);
    
    for (int i = 0; i<3; i++) {
        keys.emplace_back(new Key((i+1)*220));
//        keys.push_back(unique_ptr<Key>());
    }
}
void ofApp::keyPressed(int key){
    if (key == 'a') {
        keys[0]->on();
    }
    else if (key == 's'){
        keys[1]->on();
    }
    else if (key == 'd'){
        keys[2]->on();
    }
}
void ofApp::keyReleased(int key){
    if (key == 'a') {
        keys[0]->off();
    }
    else if (key == 's'){
        keys[1]->off();
    }
    else if (key == 'd'){
        keys[2]->off();
    }
}
void ofApp::audioOut(ofSoundBuffer &buffer){
    for (unsigned i = 0; i< bufferSize; i++) {
        currentFrame = 0;
        for (int j = 0; j<keys.size(); j++) {
            currentFrame += keys[j]->play() / keys.size();
        }
        mix.stereo(currentFrame, outputs, 0.5);
        buffer[i*buffer.getNumChannels()] = outputs[0];
        buffer[i*buffer.getNumChannels()+1] = outputs[1];
    }
}