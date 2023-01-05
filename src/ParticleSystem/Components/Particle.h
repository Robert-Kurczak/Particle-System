class Particle{
	public:
		ofVec3f position;
		ofVec3f velocity;
		float lifeTime;
		float mass;
		ofColor color;

		bool alive = true;

		virtual void draw() = 0;
};

class SphereParticle: public Particle{
	public:
		float radius = 1;

		SphereParticle(){}
		SphereParticle(float radius): radius(radius){}

		void draw() override{
			ofSetColor(color);
			ofDrawSphere(position, radius);
		}
};

class BoxParticle: public Particle{
	public:
		ofVec3f size;

		BoxParticle(ofVec3f size): size(size){}

		void draw() override{
			ofSetColor(color);
			ofDrawBox(position, size.x, size.y, size.z);
		}
};