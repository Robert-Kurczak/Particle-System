#include "Headers/Particle.hpp"

Particle::Particle():
	position(ofVec3f(0, 0, 0)),
	velocity(ofVec3f(0, 0, 0)),
	radius(1),
	lifeTime(10),
	mass(1),
	color(ofColor(255, 255, 255)),
	alive(true)
{}

void Particle::draw(){
	ofSetColor(color);
	ofDrawSphere(position, radius);
}