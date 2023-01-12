#pragma once

#include "ofMain.h"

class SceneObject{
	public:
		virtual void draw() = 0;
};

class GroundPlane: public SceneObject{
	public:
		ofPlanePrimitive plane;
		ofColor color;

		GroundPlane(ofVec3f position, ofVec2f dimensions, ofColor color = ofColor(10, 95, 56)): color(color){
			plane.setPosition(position);
			plane.set(dimensions.x, dimensions.y);
			plane.rotateDeg(90, 1, 0, 0);
		}

		void draw() override{
			ofSetColor(color);
			plane.draw();
		}
};

class Snowman: public SceneObject{
	public:
		std::vector<ofSpherePrimitive> spheres;
		ofColor color;

		Snowman(ofVec3f position, float scale = 1, int resolution = 32, ofColor color = ofColor(245, 245, 245)): color(color){
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

		void draw() override{
			for(size_t i = 0; i < spheres.size(); i++){
				ofSetColor(color);
				spheres[i].draw();
			}
		}
};

class Spruce: public SceneObject{
private:
	ofCylinderPrimitive base;
	ofColor baseColor;

	std::vector<ofConePrimitive> cones;
	ofColor conesColor;

public:
	Spruce
	(
		ofVec3f position,
		float scale = 1,
		int resolution = 32,
		ofColor baseColor = ofColor(111, 106, 82),
		ofColor conesColor = ofColor(105, 193, 126)
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

	void draw() override{
		ofSetColor(baseColor);
		base.draw();

		for(size_t i = 0; i < cones.size(); i++){
			ofSetColor(conesColor);
			cones[i].draw();
		}
	}
};

//TODO add ribbons
class Gift: public SceneObject{
	private:
		ofColor boxColor;

	public:
		ofBoxPrimitive box;

		Gift
		(
			ofVec3f position,
			float yRotation = 0,
			float scale = 1,
			ofColor boxColor = ofColor(248, 135, 119)
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

		void draw() override{
			ofSetColor(boxColor);
			box.draw();
		}
};