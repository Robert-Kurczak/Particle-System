#include "SceneObjects.hpp"

//---Ground Plane---
GroundPlane::GroundPlane(
	ofVec3f position,
	ofVec2f dimensions,
	ofColor color 
): 
	color(color){
	plane.setPosition(position);
	plane.set(dimensions.x, dimensions.y);
	plane.rotateDeg(90, 1, 0, 0);
}

void GroundPlane::draw(){
	ofSetColor(color);
	plane.draw();
}
//------

//---Snowman---
Snowman::Snowman(
	ofVec3f position,
	float scale,
	int resolution,
	ofColor color
): 
	color(color)
{
	//---Snowman base---
	ofSpherePrimitive base;
	float baseRadius = 40 * scale;

	base.setPosition(ofVec3f(
		position.x,
		position.y - baseRadius,
		position.z
	));
	
	base.setRadius(baseRadius);
	base.setResolution(resolution);
	//------

	//---Snowman middle---
	ofSpherePrimitive middle;
	float middleRadius = baseRadius * 0.75;

	middle.setPosition(ofVec3f(
		position.x,
		position.y - 2 * baseRadius - middleRadius * 0.5,
		position.z
	));
	middle.setRadius(middleRadius);
	middle.setResolution(resolution);
	//------

	//---Snowman head---
	ofSpherePrimitive head;
	float headRadius = middleRadius * 0.75;

	head.setPosition(ofVec3f(
		position.x,
		position.y - 2 * baseRadius - middleRadius * 0.5 - middleRadius - headRadius * 0.5,
		position.z
	));
	head.setRadius(headRadius);
	head.setResolution(resolution);
	//------

	spheres = {base, middle, head};
}

void Snowman::draw(){
	for(size_t i = 0; i < spheres.size(); i++){
		ofSetColor(color);
		spheres[i].draw();
	}
}
//------

//---Spruce---
Spruce::Spruce
(
	ofVec3f position,
	float scale,
	int resolution,
	ofColor baseColor,
	ofColor conesColor
):
	baseColor(baseColor),
	conesColor(conesColor)
{
	//---Spruce base---
	float baseRadius = 30 * scale;
	float baseHeight = 110 * scale;

	base.setPosition(ofVec3f(
		position.x,
		position.y - baseHeight / 2.f,
		position.z
	));
	base.setRadius(baseRadius);
	base.setHeight(baseHeight);
	//------

	//---Spruce cone0---
	ofConePrimitive cone0;
	float cone0Radius = 100 * scale;
	float cone0Height = cone0Radius * 2;

	cone0.setPosition(ofVec3f(
		position.x,
		position.y - cone0Height / 2.f - baseHeight,
		position.z
	));
	
	cone0.setRadius(cone0Radius);
	cone0.setHeight(cone0Height);
	cone0.setResolution(resolution, resolution, resolution);
	//------

	//---Spruce cone1---
	ofConePrimitive cone1;
	float cone1Radius = cone0Radius * 0.75;
	float cone1Height = cone0Height;

	cone1.setPosition(ofVec3f(
		position.x,
		position.y - baseHeight - cone0Height,
		position.z
	));
	
	cone1.setRadius(cone1Radius);
	cone1.setHeight(cone1Height);
	cone1.setResolution(resolution, resolution, resolution);
	//------

	//---Spruce cone2---
	ofConePrimitive cone2;
	float cone2Radius = cone1Radius * 0.75;
	float cone2Height = cone1Radius;

	cone2.setPosition(ofVec3f(
		position.x,
		position.y - baseHeight - cone0Height - cone2Height / 2.f,
		position.z
	));
	
	cone2.setRadius(cone2Radius);
	cone2.setHeight(cone2Height);
	cone2.setResolution(resolution, resolution, resolution);
	//------

	cones = {cone0, cone1, cone2};
}

void Spruce::draw(){
	ofSetColor(baseColor);
	base.draw();

	for(size_t i = 0; i < cones.size(); i++){
		ofSetColor(conesColor);
		cones[i].draw();
	}
}
//------

//---Gift---
Gift::Gift
(
	ofVec3f position,
	float yRotation,
	float scale,
	ofColor boxColor
):
	boxColor(boxColor)
{			
	float boxWidth = 100 * scale;
	float boxDepth = 50 * scale;
	float boxHeight = 50 * scale;

	box.setPosition(ofVec3f(
		position.x,
		position.y - boxHeight / 2.f,
		position.z
	));

	box.setWidth(boxWidth);
	box.setDepth(boxDepth);
	box.setHeight(boxHeight);
	box.panDeg(yRotation);
}

void Gift::draw(){
	ofSetColor(boxColor);
	box.draw();
}
//------