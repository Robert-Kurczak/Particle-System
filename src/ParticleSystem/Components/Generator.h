#include <random>
#include <cmath>

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

class RadiusGenerator: public ParticleAttrGenerator{
	public:
		float startRadius;
		float endRadius;

		RadiusGenerator(float startRadius, float endRadius): startRadius(startRadius), endRadius(endRadius){}

		void generate(Particle& particle){
			particle.radius = randomFloat(startRadius, endRadius);
		}
};

//---Position generators---
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

class CylinderPositionGenerator: public ParticleAttrGenerator{
	private:
		ofVec3f centerPosition;
		float radius;
		float height;

	public:
		CylinderPositionGenerator(ofVec3f centerPosition, float radius, float height):
		centerPosition(centerPosition), radius(radius), height(height)
		{}

		void generate(Particle& particle) override{
			float randomTheta = randomFloat(0, 2 * PI);
			float randomRadius = randomFloat(0, radius);
			float randomHeight = randomFloat(0, height);

			particle.position = ofVec3f(
				centerPosition.x + randomRadius * cos(randomTheta),
				centerPosition.y + randomHeight,
				centerPosition.z + randomRadius * sin(randomTheta)
			);
		}
};
//---

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

//---Color generators---
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

class StaticColorGenerator: public ParticleAttrGenerator{
	private:
		ofColor color;
	
	public:
		StaticColorGenerator(ofColor color): color(color){}
	
		void generate(Particle& particle) override{
			particle.color = color;
		}
};
//------