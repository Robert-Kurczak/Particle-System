#pragma once

#include <random>
#include <cmath>

#include "ofMain.h"
#include "Particle.hpp"

//---Base class---
class ParticleAttrGenerator{
	public:
		ParticleAttrGenerator();

		std::mt19937 mt;

		float randomFloat(float start, float end);

		virtual void generate(Particle& particle) = 0;
};
//------

//---------Position generators---------
class BoxPositionGenerator: public ParticleAttrGenerator{
	private:
		ofVec3f positionStart;
		ofVec3f positionEnd;

	public:
		BoxPositionGenerator(ofVec3f positionStart, ofVec3f positionEnd);

		void generate(Particle& particle) override;
};

class CylinderPositionGenerator: public ParticleAttrGenerator{
	private:
		ofVec3f centerPosition;
		float radius;
		float height;

	public:
		CylinderPositionGenerator(ofVec3f centerPosition, float radius, float height);

		void generate(Particle& particle) override;
};
//------------------

class RadiusGenerator: public ParticleAttrGenerator{
	public:
		float startRadius;
		float endRadius;

		RadiusGenerator(float startRadius, float endRadius);
		
		void generate(Particle& particle) override;
};

class VelocityGenerator: public ParticleAttrGenerator{
	private:
		ofVec3f velocityStart;
		ofVec3f velocityEnd;

	public:
		VelocityGenerator(ofVec3f velocityStart, ofVec3f velocityEnd);

		void generate(Particle& particle) override;
};

class MassGenerator: public ParticleAttrGenerator{
	private:
		float massStart;
		float massEnd;

	public:
		MassGenerator(float massStart, float massEnd);

		void generate(Particle& particle) override;
};

class LifetimeGenerator: public ParticleAttrGenerator{
	private:
		float lifeTimeStart;
		float lifeTimeEnd;

	public:
		LifetimeGenerator(float lifeTimeStart, float lifeTimeEnd);

		void generate(Particle& particle) override;
};

//---Color generators---
class ColorGenerator: public ParticleAttrGenerator{
	private:
		ofColor colorStart;
		ofColor colorEnd;

	public:
		ColorGenerator(ofColor colorStart, ofColor colorEnd);

		void generate(Particle& particle) override;
};

class StaticColorGenerator: public ParticleAttrGenerator{
	private:
		ofColor color;
	
	public:
		StaticColorGenerator(ofColor color);
	
		void generate(Particle& particle) override;
};
//------