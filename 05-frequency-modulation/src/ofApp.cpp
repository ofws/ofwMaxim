#include "ofApp.h"

void ofApp::setup(){
    sampleRate = 44100;
    bufferSize = 512;
    frequency = 440;
    modulationFrequency = 0;
    modulationIndex = 100;
    
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
    
    env.setAttack(2000);
    env.setDecay(1);
    env.setSustain(1);
    env.setRelease(3000);
    
    gui.setup();
    gui.add(freq.setup("frequency", 440, 50, 800));
    gui.add(instruction.setup("press any key", "shoot freq mod",250,30));
    gui.add(modFreq.setup("mod frequency", 10, 0, 20));
    gui.add(modIndex.setup("mod index", 100, 0, 200));
    
}
void ofApp::update(){}
void ofApp::draw(){
    gui.draw();
}
void ofApp::keyPressed(int key){
    env.trigger = 1;
}
void ofApp::keyReleased(int key){
    env.trigger = 0;
}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}


void ofApp::audioOut(ofSoundBuffer &buffer){
    for (unsigned i = 0; i<bufferSize; i++){
        currentSample = osc.sinewave(freq + env.adsr(mod.sinewave(modFreq), env.trigger) * modIndex);
        
        mix.stereo(currentSample, outputs, 0.5);
        buffer[i*buffer.getNumChannels()] = outputs[0];
        buffer[i*buffer.getNumChannels()+1] = outputs[1];
    }
}