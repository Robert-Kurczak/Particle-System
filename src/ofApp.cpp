#include "ofApp.h"

#include "ParticleSystem/ParticleSystem.h"
#include "SceneObjects/SceneObjects.h"

#define resolutionX 1280
#define resolutionY 720

ofEasyCam mainCamera;

SnowParticleSystem snowParticles(
	ofVec3f(-resolutionX, -resolutionY, -resolutionY),
	ofVec3f(resolutionX, -resolutionY, resolutionY),
	0
);

FireParticleSystem fireParticles(ofVec3f(0, 0, 0), 40, 10);

Snowman snowman(ofVec3f(resolutionX / 2, 0, resolutionY / 3));

//--------------------------------------------------------------
void ofApp::setup(){
	mainCamera.panDeg(180);
	mainCamera.rollDeg(180);
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
	snowman.draw();

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
