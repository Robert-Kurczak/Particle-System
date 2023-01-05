#include "ofMain.h"
#include <vector>
#include "Components/Particle.h"
#include "Components/Generator.h"
#include "Components/Emitter.h"
#include "Components/ParticleUpdater.h"

class ParticleSystem{
	private:
		std::vector<Particle*> particlesVector;
		
		Emitter emitter = Emitter(particlesVector, 20, 100, 5000);

		std::vector<ParticleUpdater*> updaters = {
			new LifetimeUpdater,
			new GravityUpdater
		};

	public:
		void updateAndDraw(){
			float deltaTime = ofGetLastFrameTime();

			emitter.update(deltaTime);

			for(size_t particleIndex = 0; particleIndex < particlesVector.size(); particleIndex++){
				// if(!particlesVector[particleIndex] -> alive) continue;

				for(size_t updaterIndex = 0; updaterIndex < updaters.size(); updaterIndex++){
					updaters[updaterIndex] -> update(deltaTime, *particlesVector[particleIndex]);
				}

				particlesVector[particleIndex] -> draw();
			}
		}
};