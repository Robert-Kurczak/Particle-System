class Scene{
protected:
	ofEasyCam mainCamera;
	ofVec3f dimensions;
	
	std::vector<std::shared_ptr<SceneObject>> sceneObjects;
	std::vector<std::shared_ptr<ParticleSystem>> particleSystems;
	std::vector<ofLight> lightSources;

public:
	Scene(ofVec3f dimensions): dimensions(dimensions){}

	Scene
	(
		ofVec3f dimensions,
		std::vector<std::shared_ptr<SceneObject>> sceneObjects,
		std::vector<std::shared_ptr<ParticleSystem>> particleSystems,
		std::vector<ofLight> lightSources
	):
		dimensions(dimensions),
		sceneObjects(sceneObjects),
		particleSystems(particleSystems)
	{}

	void draw(){
		ofClear(ofColor::black);

		ofEnableDepthTest();
		mainCamera.begin();

		for(size_t i = 0; i < sceneObjects.size(); i++){
			sceneObjects[i] -> draw();
		}

		for(size_t i = 0; i < particleSystems.size(); i++){
			particleSystems[i] -> updateAndDraw();
		}

		mainCamera.end();
	}
};

class ChristmasScene: public Scene{
private:
	void createSceneObjects(){
		sceneObjects = {
			//Snowman
			std::make_shared<Snowman>(ofVec3f(dimensions.x / 4.5, 0, dimensions.z / 8.f)),
			//---Trees---
			std::make_shared<Spruce>(ofVec3f(-dimensions.x / 3.f, 0, -dimensions.z / 10.f)),
			std::make_shared<Spruce>(ofVec3f(-dimensions.x / 4.f, 0, dimensions.z / 4.f)),
			std::make_shared<Spruce>(ofVec3f(-dimensions.x / 7.f, 0, -dimensions.z / 3.f)),
			std::make_shared<Spruce>(ofVec3f(-dimensions.x / 9.f, 0, dimensions.z / 20.f)), //Tree with gifts under it
			std::make_shared<Spruce>(ofVec3f(-dimensions.x / 9.f, 0, dimensions.z / 2.5)),
			std::make_shared<Spruce>(ofVec3f(dimensions.x / 9.f, 0, -dimensions.z / 6.f)),
			std::make_shared<Spruce>(ofVec3f(dimensions.x / 8.f, 0, dimensions.z / 3.f)),
			std::make_shared<Spruce>(ofVec3f(dimensions.x / 4.f, 0, -dimensions.z / 3.5)),
			std::make_shared<Spruce>(ofVec3f(dimensions.x / 3.f, 0, dimensions.z / 3.f)),
			std::make_shared<Spruce>(ofVec3f(dimensions.x / 2.5, 0, dimensions.z / 9.f)),
			//------
			//---Gifts---
			std::make_shared<Gift>(ofVec3f(-dimensions.x / 15.f, 0, dimensions.z / 19.f), -25),
			std::make_shared<Gift>(ofVec3f(-dimensions.x / 9.f, 0, 0), 15, 1.2, ofColor(212, 175, 55))
		};
	}

	void createParticleSystems(){
		particleSystems = {
			std::make_shared<SnowParticleSystem>(
				ofVec3f(-dimensions.x / 2, -dimensions.y, -dimensions.z / 2),
				ofVec3f(dimensions.x / 2, -dimensions.y, dimensions.z / 2),
				0
			),

			std::make_shared<FireParticleSystem>(ofVec3f(0, 0, 0), 40, 10)
		};
	}

	void createLightSources(){
		//---Fireplace---
		ofLight fireplaceLight;
		fireplaceLight.setPointLight();
		fireplaceLight.setPosition(ofVec3f(0, -dimensions.y / 10, 0));
		fireplaceLight.setDiffuseColor(ofColor(226, 88, 34));
		fireplaceLight.setSpecularColor(ofColor::white);

		fireplaceLight.enable();
		//------

		lightSources.push_back(fireplaceLight);
		// lightSources[0].disable();
	}

public:
	ChristmasScene(ofVec3f dimensions): Scene(dimensions){}

	void load(){
		createSceneObjects();
		createParticleSystems();
		createLightSources();
		
		mainCamera.panDeg(180);
		mainCamera.rollDeg(180);

		particleSystems[0] -> addSphereColliders(
			std::dynamic_pointer_cast<Snowman>(sceneObjects[0]) -> spheres
		);
	}
};