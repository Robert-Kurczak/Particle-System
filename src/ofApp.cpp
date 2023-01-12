#include "ofApp.h"

ChristmasScene scene(ofVec3f(1920, 720, 1280));

ofVec3f dimensions(1920, 720, 1280);

// SnowParticleSystem snow(
// 	ofVec3f(-dimensions.x / 2, -dimensions.y, -dimensions.z / 2),
// 	ofVec3f(dimensions.x / 2, -dimensions.y, dimensions.z / 2),
// 	0
// );

//--------------------------------------------------------------
void ofApp::setup(){
	scene.load();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	scene.draw();
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
