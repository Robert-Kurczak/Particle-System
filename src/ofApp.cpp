#include "ofApp.h"
#include "ParticleSystem/ParticleSystem.h"

ParticleSystem particleSystem;
Emitter emitter01(
	2, 10,										//radius1
	1, 10,										//mass
	ofVec3f(0, 0, 0), ofVec3f(100, 100, 100),	//position
	ofVec3f(50, 50, 50), ofVec3f(-50, -50, -50),//velocity
	3, 10,										//lifetime
	ofColor(255, 255, 255),						//color
	10											//emissionRate
);

ofEasyCam mainCamera;
//--------------------------------------------------------------
void ofApp::setup(){
	emitter01.forces.push_back(new Gravity);
	particleSystem.addEmiter(emitter01);
}

//--------------------------------------------------------------
void ofApp::update(){
	particleSystem.updateParticles();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(ofColor::black);
	mainCamera.begin();
	particleSystem.drawParticles();
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
