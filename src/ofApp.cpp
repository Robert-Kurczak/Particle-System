#include "ofApp.h"
#include "ParticleSystem/ParticleSystem.h"

ofEasyCam mainCamera;

SnowParticleSystem snowParticles(ofVec3f(0, 0, 0), ofVec3f(1000, -5, 500), -500);
FireParticleSystem fireParticles(ofVec3f(500, -500, 250), 20, 0);

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(ofColor::black);
	mainCamera.begin();
	snowParticles.updateAndDraw();
	fireParticles.updateAndDraw();
	mainCamera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
