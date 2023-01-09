class Updater{
	public:
		virtual void update(float deltaTime, Particle& particle) = 0;
};

class GravityUpdater: public Updater{
	private:
		float acceleration;

	public:
		GravityUpdater(float acceleration = 9.81): acceleration(acceleration){}

		void update(float deltaTime, Particle& particle) override{
			particle.velocity.y += acceleration * deltaTime;
			particle.position.y += particle.velocity.y * deltaTime;
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
			if(particle.position.y + particle.radius > floorPosition){
				particle.position.y = floorPosition - particle.radius;
				particle.velocity = ofVec3f(0, 0, 0);
			}
		}
};

class SphereCollisionUpdater: public Updater{
	private:
		std::vector<ofSpherePrimitive>& spheres; 
	public:
		SphereCollisionUpdater(std::vector<ofSpherePrimitive>& spheres): spheres(spheres){}

		void update(float deltaTime, Particle& particle) override{
			for(size_t i = 0; i < spheres.size(); i++){
				float distance = ofVec3f(spheres[i].getPosition()).distance(particle.position);
				float sphereRadius = spheres[i].getRadius();

				if(distance < sphereRadius + particle.radius){
					float overlap = (sphereRadius + particle.radius) - distance;

					particle.position -= overlap * particle.velocity.getNormalized();
					particle.velocity = ofVec3f(0, 0, 0);
				}
			}
		};
};