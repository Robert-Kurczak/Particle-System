class Force{
	public:
		virtual ofVec3f getAcceleration() = 0;
};

class Gravity: public Force{
	public:
		ofVec3f getAcceleration() override{
			return ofVec3f(0, -9.81, 0);
		}
};