#include "ofApp.h"
void ofApp::setup(){
    ofBackground(0);
    
    sampleRate = 44100;
    bufferSize = 512;
    frequency = 440;
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
}
void ofApp::update(){}
void ofApp::draw(){}
void ofApp::audioOut(ofSoundBuffer& buffer){
    for (unsigned i = 0 ; i<bufferSize; i++) {
        currentSample = osc.square(frequency);
        buffer[i * buffer.getNumChannels()] = currentSample;
        buffer[i * buffer.getNumChannels()+1] = currentSample;
    }
}

void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){
    frequency = (double)ofMap(x, 0, ofGetWidth(), 50, 800);
}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
