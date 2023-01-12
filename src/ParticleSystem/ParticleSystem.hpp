#include "ofMain.h"
#include <vector>

#include "Components/Headers/Particle.hpp"
#include "Components/Headers/Generator.hpp"
#include "Components/Headers/Updater.hpp"
#include "Components/Headers/Emitter.hpp"

//---Base class---
class ParticleSystem{
protected:
	std::vector<Particle> particlesVector;
	std::vector<std::shared_ptr<ParticleAttrGenerator>> generators;
	std::vector<std::shared_ptr<Updater>> updaters;

	std::unique_ptr<Emitter> emitter;

	void removeParticle(Particle& particle);

	//Protected default constructor for derived classes
	ParticleSystem();

public:
	ParticleSystem
	(
		std::vector<std::shared_ptr<ParticleAttrGenerator>> generators,
		std::vector<std::shared_ptr<Updater>> updaters,

		float emissionRate,
		float startParticlesAmount,
		float maxParticlesAmount
	);

	void addGenerators(std::shared_ptr<ParticleAttrGenerator> generator);

	void addUpdater(std::shared_ptr<Updater> updater);

	void updateAndDraw();

	void addSphereColliders(std::vector<ofSpherePrimitive>& spheres);
};
//------

class SnowParticleSystem: public ParticleSystem{
public:
	SnowParticleSystem(ofVec3f startEmittPosition, ofVec3f endEmittPosition, float floorPosition);
};

class FireParticleSystem: public ParticleSystem{
public:
	FireParticleSystem(ofVec3f centerPosition, float radius, float height);
};