#include "ofMain.h"
#include "Components/Force.h"
#include "Components/Particle.h"
#include "Components/Emitter.h"
#include <vector>

class ParticleSystem{
	private:
		std::vector<Particle> particlesVector = {};
		std::vector<Emitter> emittersVector = {};

	public:
		ParticleSystem(){}

		void addEmiter(Emitter emitter){
			emittersVector.push_back(emitter);
		}

		void updateParticles(){
			for(size_t i = 0; i < emittersVector.size(); i++){
				emittersVector[i].update(particlesVector, ofGetLastFrameTime());
			}

			auto it = particlesVector.begin();
			while(it != particlesVector.end()){
				if(it -> lifeTime <= 0){
					it = particlesVector.erase(it);
				}
				else{
					it -> update(ofGetLastFrameTime());
					it++;
				}
			}
		}

		void drawParticles(){
			for(size_t i = 0; i < particlesVector.size(); i++){
				particlesVector[i].draw();
			}
		}
};