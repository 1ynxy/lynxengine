#include <lynxengine.h>

void init();
void update();

// Program

Shared<Entity> objent;

Shared<Camera> cam;

int main(int argc, char* argv[]) {
	// Initialise Core

	core.load_conf("config");

	core.set_callbacks(&init, &update, nullptr, nullptr, nullptr, nullptr);

	// Initialise Timer & Debugger

	debug.set_verbosity(core.conf.get_int("verbosity"));

	timer.set_limit(core.conf.get_int("fps-limit"));

	// Start Game
	
	core.init();
}

void init() {
	// Open Window

	core.display.open(glm::vec2(600, 300), glm::vec2(500, 500), "window", Colour(40, 40, 40));

	//core.display.open(glm::vec2(500, 500), glm::vec2(500, 500), "window 2 : electric boogaloo", Colour(90, 0, 30));

	// Set Up Camera & Default Object

	Shared<Entity> cament = scene.instantiate("camera", glm::vec3(), glm::vec3(0, 0, 0));
	cament->add(Camera(45.0f, 0.01f, 100.0f, PROJ_PERSP));
	cament->add(Controller(4.0f, 1.0f));

	compositor.add_camera(cament->get<Camera>());

	objent = scene.instantiate("object", glm::vec3(0, 0, -5), glm::vec3());
	objent->add(MeshRenderer("shader/default", "mesh/island", "sprite/island"));
	//objent->add(Controller(4.0f, 10.0f));
}

void update() {
	//debug.info("delta : " + std::to_string(timer.delta) + " - " + std::to_string(timer.fps));

	// Rotate Object

	Shared<Transform> transform = objent->get<Transform>();

	//if (transform) transform->rotate(timer.delta * 50, transform->up());
}
