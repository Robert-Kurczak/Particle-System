class Emitter{
	private:
		//---Parameters---
		std::vector<Particle*>& particlesVector;
		std::vector<ParticleAttrGenerator*> generatorsVector = {
			new BoxPositionGenerator(ofVec3f(-40, -40, -40), ofVec3f(40, 40, 40))
		};

		float emissionRate;
		float startParticlesAmount;
		float maxParticlesAmount;
		//------

		float timer = 0;

		Particle* getNewParticle(){
			Particle* particle_p = new SphereParticle();

			for(size_t i = 0; i < generatorsVector.size(); i++){
				generatorsVector[i] -> generate(*particle_p);
			}

			return particle_p;
		}

	public:
		Emitter
		(
			std::vector<Particle*>& particlesVector,
			float emissionRate,
			float startParticlesAmount,
			float maxParticlesAmount
		):
			particlesVector(particlesVector),
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

			//Time for creating particle
			if(timer * emissionRate >= 1){
				timer = 0;

				if(particlesVector.size() < maxParticlesAmount){
					particlesVector.push_back(getNewParticle());
				}
			}
		}
};