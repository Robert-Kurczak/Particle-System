#include <random>

class Emitter{
	private:
		float timer = 0;

		std::mt19937 mt = std::mt19937(std::random_device{}());
		float randomFloat(float start, float end){
			std::uniform_real_distribution<float> dist(start, end);
			return dist(mt);
		}

		Particle generateParticle(){
			float radius = randomFloat(radiusStart, radiusEnd);
			float mass = randomFloat(massStart, massEnd);
			ofVec3f position(
				randomFloat(positionStart.x, positionEnd.x),
				randomFloat(positionStart.y, positionEnd.y),
				randomFloat(positionStart.z, positionEnd.z)
			);
			ofVec3f velocity(
				randomFloat(velocityStart.x, velocityEnd.x),
				randomFloat(velocityStart.y, velocityEnd.y),
				randomFloat(velocityStart.z, velocityEnd.z)
			);
			ofVec3f acceleration(0, 0, 0);

			float lifeTime = randomFloat(lifeTimeStart, lifeTimeEnd);

			return Particle(
				radius,
				mass,
				position,
				velocity,
				lifeTime,
				color,
				forces
			);
		}

	public:
		const float radiusStart;
		const float radiusEnd;

		const float massStart;
		const float massEnd;

		const ofVec3f positionStart;
		const ofVec3f positionEnd;

		const ofVec3f velocityStart;
		const ofVec3f velocityEnd;

		const float lifeTimeStart;
		const float lifeTimeEnd;

		const ofColor color;
		const float emissionRate;

		std::vector<Force*> forces = {};

		Emitter(
			float radiusStart, float radiusEnd,
			float massStart, float massEnd,
			ofVec3f positionStart, ofVec3f positionEnd,
			ofVec3f velocityStart, ofVec3f velocityEnd,
			float lifeTimeStart, float lifeTimeEnd,
			ofColor color,
			float emissionRate
		):
		radiusStart(radiusStart), radiusEnd(radiusEnd),
		massStart(massStart), massEnd(massEnd),
		positionStart(positionStart), positionEnd(positionEnd),
		lifeTimeStart(lifeTimeStart), lifeTimeEnd(lifeTimeEnd),
		color(color),
		emissionRate(emissionRate)
		{}

		void update(std::vector<Particle>& particlesVector, double deltaTime){
			timer += deltaTime;

			//Time for creating particle
			if(timer * emissionRate >= 1){
				timer = 0;

				particlesVector.push_back(generateParticle());
			}
		}
};