class Particle{
	public:
		float radius;
		float mass;
		ofVec3f position;
		ofVec3f velocity;
		float lifeTime;
		ofColor color;
		std::vector<Force*> forces;

		Particle(
			float radius,
			float mass,
			ofVec3f position,
			ofVec3f velocity,
			float lifeTime,
			ofColor color,
			std::vector<Force*>& forces
		):
		radius{radius},
		mass{mass},
		position{position},
		velocity{velocity},
		lifeTime{lifeTime},
		color{color},
		forces{forces}
		{}

		void update(double deltaTime){
			lifeTime -= deltaTime;

			if(lifeTime <= 0) return;

			ofVec3f acceleration(0, 0, 0);

			for(size_t i = 0; i < forces.size(); i++){
				acceleration += forces[i] -> getAcceleration();
			}

			velocity += acceleration * deltaTime;
			position += velocity * deltaTime;
		}

		void draw(){
			ofSetColor(color);
			ofDrawSphere(position, radius);
		}
};