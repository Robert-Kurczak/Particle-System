class Updater{
	public:
		virtual void update(float deltaTime, Particle& particle) = 0;
};

class GravityUpdater: public Updater{
	private:
		float acceleration;

	public:
		GravityUpdater(float acceleration = -9.81): acceleration(acceleration){}

		void update(float deltaTime, Particle& particle) override{
			particle.velocity += ofVec3f(0, acceleration, 0) * deltaTime;
			particle.position += particle.velocity * deltaTime;
		}
};

class LifetimeUpdater: public Updater{
	public:
		void update(float deltaTime, Particle& particle) override{
			particle.lifeTime -= deltaTime;

			if(particle.lifeTime <= 0){
				particle.alive = false;
			}
		}
};

class FloorCollisionUpdater: public Updater{
	public:
		float floorPosition = 0;

		FloorCollisionUpdater(){}
		FloorCollisionUpdater(float floorPosition): floorPosition(floorPosition){}

		void update(float deltaTime, Particle& particle) override{
			if(particle.position.y + particle.radius < floorPosition){
				particle.position.y = floorPosition - particle.radius;
			}
		}
};