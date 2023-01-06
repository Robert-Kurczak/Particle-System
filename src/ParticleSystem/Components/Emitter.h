//Emitter connects all generators, forms a particle using them
//and emits it with proper frequency
class Emitter{
	private:
		//---Parameters---
		std::vector<Particle>& particlesVector;

		std::vector<std::shared_ptr<ParticleAttrGenerator>>& generatorsVector;

		float emissionRate;
		float startParticlesAmount;
		float maxParticlesAmount;
		//------

		float timer = 0;

		Particle getNewParticle(){			
			Particle particle;

			for(size_t i = 0; i < generatorsVector.size(); i++){
				generatorsVector[i] -> generate(particle);
			}

			return particle;
		}

	public:
		Emitter
		(
			std::vector<Particle>& particlesVector,
			std::vector<std::shared_ptr<ParticleAttrGenerator>>& generatorsVector,
			float emissionRate,
			float startParticlesAmount,
			float maxParticlesAmount
		):
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

		void update(double deltaTime){
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
};