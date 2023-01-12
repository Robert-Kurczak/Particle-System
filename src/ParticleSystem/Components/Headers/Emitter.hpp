#pragma once

#include <vector>
#include <memory>

#include "Particle.hpp"
#include "Generator.hpp"

//Emitter connects all generators, forms a particle using them
//and emits it with proper frequency
class Emitter{
private:
	float timer;

	//---Private parameters---
	std::vector<Particle>& particlesVector;
	std::vector<std::shared_ptr<ParticleAttrGenerator>>& generatorsVector;
	//------

	Particle getNewParticle();

public:
	//---Public parameters---
	float emissionRate;
	float startParticlesAmount;
	float maxParticlesAmount;
	//------
	
	Emitter
	(
		std::vector<Particle>& particlesVector,
		std::vector<std::shared_ptr<ParticleAttrGenerator>>& generatorsVector,
		float emissionRate,
		float startParticlesAmount,
		float maxParticlesAmount
	);

	void update(double deltaTime);
};