#include "camera.h"

#include <../src/core/core.h>

#include <../src/ces/entity.h>

// Constructors & Destructors

Camera::Camera(float fov, float min, float max, ProjectionType proj, float scale) : fov(fov), min(min), max(max), proj(proj), scale(scale) {
	
}

Camera::Camera(Shared<Entity> entity, const Camera& camera) : fov(camera.fov), min(camera.min), max(camera.max), proj(camera.proj), scale(camera.scale) {
	this->entity = entity;

	init();
}

Camera::~Camera() {
	term();
}

// Member Functions

void Camera::init() {
	if (entity) transform = entity->get<Transform>();

	//target = new RenderTexture("camera_target", glm::vec2(1, 1));
}

void Camera::term() {
	if (target) target->destroy();
}

void Camera::resize(glm::vec2 size) {
	if (target) target->resize(size);
}

glm::mat4 Camera::projection() const {
	glm::vec2 size = target ? target->colour->get_size() : core.display.get_size();

	if (proj == PROJ_ORTHO) return glm::ortho(-scale, scale, -scale, scale, min, max);
	if (proj == PROJ_PERSP) return glm::perspective(fov, size.x / size.y, min, max);

	return glm::mat4(1.0f);
}
