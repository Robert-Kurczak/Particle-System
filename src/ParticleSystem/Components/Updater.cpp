#include "Headers/Updater.hpp"

//---Gravity Updater---
GravityUpdater::GravityUpdater(float acceleration):
acceleration(acceleration)
{}

void GravityUpdater::update(float deltaTime, Particle& particle){
	particle.velocity.y += acceleration * deltaTime;
	particle.position.y += particle.velocity.y * deltaTime;
}
//------

//---Lifetime Updater---
void LifetimeUpdater::update(float deltaTime, Particle& particle){
	particle.lifeTime -= deltaTime;

	if(particle.lifeTime <= 0){
		particle.alive = false;
	}
}
//------

//---Floor Collision Updater---
FloorCollisionUpdater::FloorCollisionUpdater(float floorPosition):
floorPosition(floorPosition)
{}


void FloorCollisionUpdater::update(float deltaTime, Particle& particle){
	if(particle.position.y + particle.radius > floorPosition){
		particle.position.y = floorPosition - particle.radius;
		particle.velocity = ofVec3f(0, 0, 0);
	}
}
//------

//---Sphere Collision Updater---
SphereCollisionUpdater::SphereCollisionUpdater(std::vector<ofSpherePrimitive>& spheres):
spheres(spheres)
{}

void SphereCollisionUpdater::update(float deltaTime, Particle& particle){
	for(size_t i = 0; i < spheres.size(); i++){
		float distance = ofVec3f(spheres[i].getPosition()).distance(particle.position);
		float sphereRadius = spheres[i].getRadius();

		if(distance < sphereRadius + particle.radius){
			float overlap = (sphereRadius + particle.radius) - distance;

			particle.position -= overlap * particle.velocity.getNormalized();
			particle.velocity = ofVec3f(0, 0, 0);
		}
	}
}
//------