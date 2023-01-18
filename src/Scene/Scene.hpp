#pragma once

#include "ofMain.h"
#include <vector>
#include <memory>

#include "SceneObjects.hpp"
#include "../ParticleSystem/ParticleSystem.hpp"

class Scene{
protected:
	ofEasyCam mainCamera;
	ofVec3f dimensions;
	
	std::vector<std::shared_ptr<SceneObject>> sceneObjects;
	std::vector<std::shared_ptr<ParticleSystem>> particleSystems;
	std::vector<ofLight> lightSources;

public:
	Scene(ofVec3f dimensions);

	Scene
	(
		ofVec3f dimensions,
		std::vector<std::shared_ptr<SceneObject>> sceneObjects,
		std::vector<std::shared_ptr<ParticleSystem>> particleSystems,
		std::vector<ofLight> lightSources
	);

	void load();
	void draw();
};

class ChristmasScene: public Scene{
private:
	void createSceneObjects();

	void createParticleSystems();

	void createLightSources();

public:
	ChristmasScene(ofVec3f dimensions): Scene(dimensions){}

	void load();
};