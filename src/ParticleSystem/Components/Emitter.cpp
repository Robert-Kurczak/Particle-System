#include "Headers/Emitter.hpp"

Particle Emitter::getNewParticle(){
	Particle particle;

		for(size_t i = 0; i < generatorsVector.size(); i++){
			generatorsVector[i] -> generate(particle);
		}

		return particle;
}

Emitter::Emitter
(
	std::vector<Particle>& particlesVector,
	std::vector<std::shared_ptr<ParticleAttrGenerator>>& generatorsVector,
	float emissionRate,
	float startParticlesAmount,
	float maxParticlesAmount
):
	timer(0),
	particlesVector(particlesVector),
	generatorsVector(generatorsVector),
	emissionRate(emissionRate),
	startParticlesAmount(startParticlesAmount),
	maxParticlesAmount(maxParticlesAmount)
{
	for(int i = 0; i < startParticlesAmount; i++){
		particlesVector.push_back(getNewParticle());
	}
}

void Emitter::update(double deltaTime){
	timer += deltaTime;

	int particlesToEmit = timer * emissionRate;

	//Time for creating particle
	if(particlesToEmit >= 1){
		timer = 0;

		for(int i = 0; i < particlesToEmit; i++){
			if(particlesVector.size() < maxParticlesAmount){
				particlesVector.push_back(getNewParticle());
			}
		}
	}
}