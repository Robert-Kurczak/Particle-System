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
	std::vector<std::shared_ptr<ParticleAttrGenerator>> generators;
	std::vector<std::shared_ptr<Updater>> updaters;

	std::unique_ptr<Emitter> emitter;

	void removeParticle(Particle& particle){
			std::swap(particle, particlesVector[particlesVector.size() - 1]);
			particlesVector.pop_back();
		}

	//Protected default constructor for derived classes
	ParticleSystem(){}

public:
	ParticleSystem
	(
		std::vector<std::shared_ptr<ParticleAttrGenerator>> generators,
		std::vector<std::shared_ptr<Updater>> updaters,

		float emissionRate,
		float startParticlesAmount,
		float maxParticlesAmount
	):
		generators(generators),
		updaters(updaters)
	{
		emitter = std::make_unique<Emitter>(
			particlesVector,
			generators,
			emissionRate,
			startParticlesAmount,
			maxParticlesAmount
		);
	}

	void addGenerators(std::shared_ptr<ParticleAttrGenerator> generator){
		generators.push_back(generator);
	}

	void addUpdater(std::shared_ptr<Updater> updater){
		updaters.push_back(updater);
	}

	void updateAndDraw(){
		float deltaTime = ofGetLastFrameTime();

		emitter -> update(deltaTime);

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
	SnowParticleSystem(ofVec3f startEmittPosition, ofVec3f endEmittPosition, float floorPosition){
		generators = {
			std::make_shared<BoxPositionGenerator>(startEmittPosition, endEmittPosition),
			std::make_shared<VelocityGenerator>(ofVec3f(-5, -5, -5), ofVec3f(5, 5, 5)),
			std::make_shared<LifetimeGenerator>(10, 30)
		};

		updaters = {
			std::make_shared<LifetimeUpdater>(),
			std::make_shared<GravityUpdater>(),
			std::make_shared<FloorCollisionUpdater>(floorPosition)
		};

		emitter = std::make_unique<Emitter>(particlesVector, generators, 500, 500, 50000);
	}
};

class FireParticleSystem: public ParticleSystem{
public:
	FireParticleSystem(ofVec3f centerPosition, float radius, float height){
		generators = {
			std::make_shared<CylinderPositionGenerator>(centerPosition, radius, height),
			std::make_shared<VelocityGenerator>(ofVec3f(-2, -40, -2), ofVec3f(2, 0, 2)),
			std::make_shared<RadiusGenerator>(0.5, 1),
			std::make_shared<ColorGenerator>(ofColor(255, 0, 0), ofColor(255, 221, 0)),
			std::make_shared<LifetimeGenerator>(0.1, 3)
		};

		updaters = {
			std::make_shared<LifetimeUpdater>(),
			std::make_shared<GravityUpdater>(-20)
		};

		emitter = std::make_unique<Emitter>(particlesVector, generators, 1000, 0, 100000);
	}
};