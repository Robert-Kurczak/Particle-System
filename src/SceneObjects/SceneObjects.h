class SceneObject{    
	public:
		virtual void draw() = 0;
};

class Snowman: public SceneObject{
	private:
		std::vector<ofSpherePrimitive> spheres;
		ofColor color;
		
	public:
		Snowman(ofVec3f position, float scale = 1, int resolution = 32, ofColor color = ofColor(245, 245, 245)): color(color){
			//---Snowman base---
			ofSpherePrimitive base;
			float baseRadius = 60 * scale;

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

		void draw(){
			for(size_t i = 0; i < spheres.size(); i++){
				ofSetColor(color);
				spheres[i].draw();
			}
		}
};