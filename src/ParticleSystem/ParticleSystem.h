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
		std::vector<std::shared_ptr<ParticleAttrGenerator>> generatorsVector;
		Emitter emitter;
		std::vector<std::shared_ptr<Updater>> updaters;

		void removeParticle(Particle& particle){
			std::swap(particle, particlesVector[particlesVector.size() - 1]);
			particlesVector.pop_back();
		}

	public:
		ParticleSystem
		(
			std::vector<std::shared_ptr<ParticleAttrGenerator>> generatorsVector,
			Emitter emitter,
			std::vector<std::shared_ptr<Updater>> updaters
		):
			generatorsVector(generatorsVector),
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
				Emitter(particlesVector, generatorsVector, 200, 100, 5000),
				//Updaters
				std::vector<std::shared_ptr<Updater>>{
					std::make_shared<LifetimeUpdater>(),
					std::make_shared<GravityUpdater>(),
					std::make_shared<FloorCollisionUpdater>(floorPosition)
				}
			)
		{}
};