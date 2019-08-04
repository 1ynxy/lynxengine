#ifndef controller_h
#define controller_h

#include <glm/glm.hpp>

#include <../src/ces/component/transform.h>

class Controller : public Component {
public:
	// Member Variables

	float speed = 0.0f;
	float rot_speed = 0.0f;

	Shared<Transform> transform = nullptr;

	// Constructors & Destructors

	Controller(float speed, float rot_speed);
	Controller(Shared<Entity> entity, const Controller& controller);

	~Controller();

	// Member Functions

	void init() override;
	void update() override;
};

#endif
