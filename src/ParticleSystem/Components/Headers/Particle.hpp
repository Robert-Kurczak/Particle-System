#pragma once

#include "ofMain.h"

class Particle{
	public:
		ofVec3f position = {0, 0, 0};
		ofVec3f velocity = {0, 0, 0};
		float radius = 1;
		float lifeTime = 10;
		float mass = 1;
		ofColor color = {255, 255, 255};

		bool alive = true;

		void draw(){
			ofSetColor(color);
			ofDrawSphere(position, radius);
		}
};