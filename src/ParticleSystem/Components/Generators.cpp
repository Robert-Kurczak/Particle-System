#include "Headers/Generator.hpp"

//---Base class---
ParticleAttrGenerator::ParticleAttrGenerator():
mt(std::mt19937(std::random_device{}()))
{}

float ParticleAttrGenerator::randomFloat(float start, float end){
	std::uniform_real_distribution<float> dist(start, end);
	return dist(mt);
}
//------

//---------------------------Position generators---------------------------
//---Box Position Generator---
BoxPositionGenerator::BoxPositionGenerator(ofVec3f positionStart, ofVec3f positionEnd):
positionStart(positionStart), positionEnd(positionEnd)
{}

void BoxPositionGenerator::generate(Particle& particle){
	particle.position = ofVec3f(
		randomFloat(positionStart.x, positionEnd.x),
		randomFloat(positionStart.y, positionEnd.y),
		randomFloat(positionStart.z, positionEnd.z)
	);
}
//------

//---Cylinder Position Generator---
CylinderPositionGenerator::CylinderPositionGenerator(ofVec3f centerPosition, float radius, float height):
centerPosition(centerPosition), radius(radius), height(height)
{}

void CylinderPositionGenerator::generate(Particle& particle){
	float randomTheta = randomFloat(0, 2 * PI);
	float randomRadius = randomFloat(0, radius);
	float randomHeight = randomFloat(0, height);

	particle.position = ofVec3f(
		centerPosition.x + randomRadius * cos(randomTheta),
		centerPosition.y + randomHeight,
		centerPosition.z + randomRadius * sin(randomTheta)
	);
}
//------
//------------------------------------------------------

//---Radius Generator---
RadiusGenerator::RadiusGenerator(float startRadius, float endRadius):
startRadius(startRadius), endRadius(endRadius){}

void RadiusGenerator::generate(Particle& particle){
	particle.radius = randomFloat(startRadius, endRadius);
}
//------

//---Velocity Generator---
VelocityGenerator::VelocityGenerator(ofVec3f velocityStart, ofVec3f velocityEnd):
velocityStart(velocityStart), velocityEnd(velocityEnd)
{}

void VelocityGenerator::generate(Particle& particle){
	particle.velocity = ofVec3f(
		randomFloat(velocityStart.x, velocityEnd.x),
		randomFloat(velocityStart.y, velocityEnd.y),
		randomFloat(velocityStart.z, velocityEnd.z)
	);
}
//------

//---Mass Generator---
MassGenerator::MassGenerator(float massStart, float massEnd):
massStart(massStart), massEnd(massEnd)
{}

void MassGenerator::generate(Particle& particle){
	particle.mass = randomFloat(massStart, massEnd);
}
//------

//---Lifetime Generator---
LifetimeGenerator::LifetimeGenerator(float lifeTimeStart, float lifeTimeEnd):
lifeTimeStart(lifeTimeStart), lifeTimeEnd(lifeTimeEnd)
{}

void LifetimeGenerator::generate(Particle& particle){
	particle.lifeTime = randomFloat(lifeTimeStart, lifeTimeEnd);
}
//------

//---------------------------Color generators---------------------------
ColorGenerator::ColorGenerator(ofColor colorStart, ofColor colorEnd):
colorStart(colorStart), colorEnd(colorEnd)
{}

void ColorGenerator::generate(Particle& particle){
	particle.color = ofColor(
		randomFloat(colorStart.r, colorEnd.r),
		randomFloat(colorStart.g, colorEnd.g),
		randomFloat(colorStart.b, colorEnd.b)
	);
}
//------

//---Static Color Generator---
StaticColorGenerator::StaticColorGenerator(ofColor color):
color(color)
{}

void StaticColorGenerator::generate(Particle& particle){
	particle.color = color;
}
//------
//------------------------------------------------------