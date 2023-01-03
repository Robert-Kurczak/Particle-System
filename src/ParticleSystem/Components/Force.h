#include <algorithm>

class Force{
	public:
		virtual ofVec3f getAcceleration() = 0;
};

class Gravity: public Force{
	public:
		ofVec3f getAcceleration() override{
			return ofVec3f(0, -20, 0);
		}
};

// class Viscosity: public Force{
// 	public:
// 		float normalViscosity;
// 		float maxViscosity;
// 		float viscositySlope;
// 		float highVpositionY;

// 		Viscosity(float normalViscosity, float maxViscosity, float viscositySlope, float highVpositionY)
// 		:normalViscosity(normalViscosity), maxViscosity(maxViscosity), viscositySlope(viscositySlope), highVpositionY(highVpositionY)
// 		{}

// 		float viscosityFromPosition(ofVec3f position){
// 			float quadricResult = -viscositySlope * (position.y - highVpositionY) * (position.y - highVpositionY) + maxViscosity;
		
// 			return std::max(normalViscosity, quadricResult);
// 	}
// };