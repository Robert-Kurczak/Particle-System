#include "ofMain.h"
#include <vector>
#include <memory>
#include "Components/Particle.h"
#include "Components/Generator.h"
#include "Components/Emitter.h"
#include "Components/Updater.h"

class ParticleSystem{
	protected:
		std::vector<Particle> particlesVector;

		//generators are only used by emitters, but having them here,
		//creates easy access, and easy configuration (in one place),
		//of whole particle system
		std::vector<std::shared_ptr<ParticleAttrGenerator>> generators;
		Emitter emitter;
		std::vector<std::shared_ptr<Updater>> updaters;

		void removeParticle(Particle& particle){
			std::swap(particle, particlesVector[particlesVector.size() - 1]);
			particlesVector.pop_back();
		}

	public:
		ParticleSystem
		(
			std::vector<std::shared_ptr<ParticleAttrGenerator>> generators,
			Emitter emitter,
			std::vector<std::shared_ptr<Updater>> updaters
		):
			generators(generators),
			emitter(emitter),
			updaters(updaters)
		{}

		void updateAndDraw(){
			float deltaTime = ofGetLastFrameTime();

			emitter.update(deltaTime);

			for(size_t particleIndex = 0; particleIndex < particlesVector.size(); particleIndex++){
				Particle& particle = particlesVector[particleIndex];

				for(size_t updaterIndex = 0; updaterIndex < updaters.size(); updaterIndex++){
					updaters[updaterIndex]->update(deltaTime, particle);
				}

				if(!particle.alive){
					removeParticle(particle);
				}
				else{
					particle.draw();
				}
			}
		}

		void addSphereColliders(std::vector<ofSpherePrimitive>& spheres){
			updaters.push_back(
				std::make_shared<SphereCollisionUpdater>(spheres)
			);
		}
};

class SnowParticleSystem: public ParticleSystem{
	public:
		SnowParticleSystem
		(
			ofVec3f startEmittPosition,
			ofVec3f endEmittPosition,
			float floorPosition
		):
			ParticleSystem(
				//Generators
				std::vector<std::shared_ptr<ParticleAttrGenerator>>{
					std::make_shared<BoxPositionGenerator>(startEmittPosition, endEmittPosition),
					std::make_shared<VelocityGenerator>(ofVec3f(-5, -5, -5), ofVec3f(5, 5, 5)),
					std::make_shared<LifetimeGenerator>(10, 30)
				},
				//Emitter
				Emitter(particlesVector, generators, 500, 500, 50000),
				//Updaters
				std::vector<std::shared_ptr<Updater>>{
					std::make_shared<LifetimeUpdater>(),
					std::make_shared<GravityUpdater>(),
					std::make_shared<FloorCollisionUpdater>(floorPosition)
				}
			)
		{}
};

class FireParticleSystem: public ParticleSystem{
	public:
		FireParticleSystem
		(
			ofVec3f centerPosition,
			float radius,
			float height
		):
			ParticleSystem(
				//Generators
				std::vector<std::shared_ptr<ParticleAttrGenerator>>{
					std::make_shared<CylinderPositionGenerator>(centerPosition, radius, height),
					std::make_shared<VelocityGenerator>(ofVec3f(-2, -40, -2), ofVec3f(2, 0, 2)),
					std::make_shared<RadiusGenerator>(0.5, 1),
					std::make_shared<ColorGenerator>(ofColor(255, 0, 0), ofColor(255, 221, 0)),
					std::make_shared<LifetimeGenerator>(0.1, 3)
				},
				//Emitter
				Emitter(particlesVector, generators, 1000, 0, 100000),
				//Updaters
				std::vector<std::shared_ptr<Updater>>{
					std::make_shared<LifetimeUpdater>(),
					std::make_shared<GravityUpdater>(-20)
				}
			)
		{}
};