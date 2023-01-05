class ParticleUpdater{
	public:
		virtual void update(float deltaTime, Particle& particle) = 0;
};

class GravityUpdater: public ParticleUpdater{
	public:
		void update(float deltaTime, Particle& particle) override{
			particle.velocity += ofVec3f(0, -9.81, 0) * deltaTime;
			particle.position += particle.velocity * deltaTime;
		}
};

class LifetimeUpdater: public ParticleUpdater{
	public:
		void update(float deltaTime, Particle& particle) override{
			particle.lifeTime -= deltaTime;

			if(particle.lifeTime <= 0){
				particle.alive = false;
			}
		}
};