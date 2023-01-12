#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class Updater{
	public:
		virtual void update(float deltaTime, Particle& particle) = 0;
};

class GravityUpdater: public Updater{
	private:
		float acceleration;

	public:
		GravityUpdater(float acceleration = 9.81);

		void update(float deltaTime, Particle& particle) override;
};

class LifetimeUpdater: public Updater{
	public:
		void update(float deltaTime, Particle& particle) override;
};

class FloorCollisionUpdater: public Updater{
	public:
		float floorPosition;

		FloorCollisionUpdater(float floorPosition = 0);

		void update(float deltaTime, Particle& particle) override;
};

class SphereCollisionUpdater: public Updater{
	private:
		std::vector<ofSpherePrimitive>& spheres; 
	public:
		SphereCollisionUpdater(std::vector<ofSpherePrimitive>& spheres);

		void update(float deltaTime, Particle& particle) override;
};