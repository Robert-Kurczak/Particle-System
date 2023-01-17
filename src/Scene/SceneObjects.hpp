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

		GroundPlane(ofVec3f position, ofVec2f dimensions, ofColor color = ofColor(10, 95, 56));

		void draw() override;
};

class Snowman: public SceneObject{
	public:
		std::vector<ofSpherePrimitive> spheres;
		ofColor color;

		Snowman
		(
			ofVec3f position,
			float scale = 1,
			int resolution = 32,
			ofColor color = ofColor(245, 245, 245)
		);

		void draw() override;
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
	);

	void draw() override;
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
		);

		void draw() override;
};