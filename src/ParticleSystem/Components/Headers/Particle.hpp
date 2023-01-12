#pragma once

#include "ofMain.h"

class Particle{
	public:
		ofVec3f position;
		ofVec3f velocity;
		float radius;
		float lifeTime;
		float mass;
		ofColor color;

		bool alive;

		Particle();

		void draw();
};