# ParticleSystem

ParticleSystem is an efficient particle system written in openFrameworks using object-oriented programming (OOP) paradigm. The code architecture allows for easy development of new features and behaviours.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- openFrameworks

### Installing

1. Clone the repository to openFrameworks/apps/myApps

```
git clone https://github.com/Robert-Kurczak/ParticleSystem.git openFrameworks/apps/myApps/ParticleSystem
```

2. use command ```make Release``` to build project
3. use command ```make runRelease``` to run project

## Usage

Include project
```C++
#include "ParticleSystem/ParticleSystem.hpp"
```

To use the particle system, you can create one of the example particle system object (like SnowParticleSystem) in ofApp,
```C++
SnowParticleSystem snow(
	ofVec3f(-500, -500, -500),
	ofVec3f(500, 500, 500),
	0
);
```

then use updateAndDraw method in ofApp::Draw
```C++
void ofApp::draw(){
	snow.updateAndDraw();
}
```

You can also create your own Particle Systems using base class, providing sets of generators and updaters.
```C++
ParticleSystem myFire(
	//Generators
	std::vector<std::shared_ptr<ParticleAttrGenerator>>{
		std::make_shared<CylinderPositionGenerator>(ofVec3f(0, 0, 0), 20, 5),
		std::make_shared<VelocityGenerator>(ofVec3f(-2, -40, -2), ofVec3f(2, 0, 2)),
		std::make_shared<RadiusGenerator>(0.5, 1),
		std::make_shared<ColorGenerator>(ofColor(255, 0, 0), ofColor(255, 221, 0)),
		std::make_shared<LifetimeGenerator>(0.1, 3)
	},

	//Updaters
	std::vector<std::shared_ptr<Updater>>{
		std::make_shared<LifetimeUpdater>(),
		std::make_shared<GravityUpdater>(-20)
	},

	//Emission rate
	1000,
	//Start particles amount
	0,
	//Max particles amount
	100000
);

//---

void ofApp::draw(){
	myFire.updateAndDraw();
}
```

For managing whole rendered space, you can use Scene class.
```C++
#include "Scene/Scene.hpp"
```

In ofApp, create one of the example scenes
```C++
ChristmasScene scene(ofVec3f(1920, 720, 1280));
```

load it in ofApp setup method
```C++
void ofApp::setup(){
	scene.load();
}
```

then draw it in ofApp draw method
```C++
void ofApp::draw(){
	scene.draw();
}
```

As with the Particle System class, you can create your own scenes
```C++
ofVec3f dimensions = {1920, 720, 1280};
Scene myScene(
	dimensions,
	//Scene objects
	std::vector<std::shared_ptr<SceneObject>>{
		std::make_shared<Spruce>(ofVec3f(-dimensions.x / 3.f, 0, -dimensions.z / 10.f)),
		std::make_shared<Spruce>(ofVec3f(-dimensions.x / 4.f, 0, dimensions.z / 4.f)),
		std::make_shared<Spruce>(ofVec3f(-dimensions.x / 7.f, 0, -dimensions.z / 3.f))
	},
	//Particle systems
	std::vector<std::shared_ptr<ParticleSystem>>{
		std::make_shared<SnowParticleSystem>(
			ofVec3f(-dimensions.x / 2, -dimensions.y, -dimensions.z / 2),
			ofVec3f(dimensions.x / 2, -dimensions.y, dimensions.z / 2),
			0
		)
	},
	//Light sources
	std::vector<ofLight>{}
);
```
## Contributing

Feel free to fork the repository and submit pull requests for any new features or bug fixes.

## License

This project is licensed under the MIT License.

## Acknowledgments

* [OpenFrameworks](https://openframeworks.cc/)