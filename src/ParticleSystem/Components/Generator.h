#include <random>

//Generates particle attribute with proper
//algorithm
class ParticleAttrGenerator{
	public:
		std::mt19937 mt = std::mt19937(std::random_device{}());
		float randomFloat(float start, float end){
			std::uniform_real_distribution<float> dist(start, end);
			return dist(mt);
		}

		virtual void generate(Particle& particle) = 0;
};

class BoxPositionGenerator: public ParticleAttrGenerator{
	private:
		ofVec3f positionStart;
		ofVec3f positionEnd;

	public:
		BoxPositionGenerator(ofVec3f positionStart, ofVec3f positionEnd):
		positionStart(positionStart), positionEnd(positionEnd)
		{}

		void generate(Particle& particle) override{
			particle.position = ofVec3f(
				randomFloat(positionStart.x, positionEnd.x),
				randomFloat(positionStart.y, positionEnd.y),
				randomFloat(positionStart.z, positionEnd.z)
			);
		}
};

class VelocityGenerator: public ParticleAttrGenerator{
	private:
		ofVec3f velocityStart;
		ofVec3f velocityEnd;

	public:
		VelocityGenerator(ofVec3f velocityStart, ofVec3f velocityEnd):
		velocityStart(velocityStart), velocityEnd(velocityEnd)
		{}

		void generate(Particle& particle) override{
			particle.velocity = ofVec3f(
				randomFloat(velocityStart.x, velocityEnd.x),
				randomFloat(velocityStart.y, velocityEnd.y),
				randomFloat(velocityStart.z, velocityEnd.z)
			);
		}
};

class MassGenerator: public ParticleAttrGenerator{
	private:
		float massStart;
		float massEnd;

	public:
		MassGenerator(float massStart, float massEnd): massStart(massStart), massEnd(massEnd){}

		void generate(Particle& particle) override{
			particle.mass = randomFloat(massStart, massEnd);
		}
};

class LifetimeGenerator: public ParticleAttrGenerator{
	private:
		float lifeTimeStart;
		float lifeTimeEnd;

	public:
		LifetimeGenerator(float lifeTimeStart, float lifeTimeEnd): lifeTimeStart(lifeTimeStart), lifeTimeEnd(lifeTimeEnd){}

		void generate(Particle& particle) override{
			particle.lifeTime = randomFloat(lifeTimeStart, lifeTimeEnd);
		}
};

class ColorGenerator: public ParticleAttrGenerator{
	private:
		ofColor colorStart;
		ofColor colorEnd;

	public:
		ColorGenerator(ofColor colorStart, ofColor colorEnd): colorStart(colorStart), colorEnd(colorEnd){}

		void generate(Particle& particle) override{
			particle.color = ofColor(
				randomFloat(colorStart.r, colorEnd.r),
				randomFloat(colorStart.g, colorEnd.g),
				randomFloat(colorStart.b, colorEnd.b)
			);
		}
};