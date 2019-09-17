#include "transform.h"

#include <../src/core/core.h>

#include <../src/ces/entity.h>

// Constructors & Destructors

Transform::Transform(const glm::vec3& position, const glm::vec3& rotation) : position(position), rotation(rotation) {

}

Transform::Transform(Shared<Entity> entity, const Transform& transform) : position(transform.position), rotation(transform.rotation) {
	this->entity = entity;
	
	init();
}

Transform::~Transform() {
	term();
}

// Member Functions

glm::mat4 Transform::matrix() {
	glm::mat4 translate = glm::translate(glm::mat4(1.0f), position);

	glm::mat4 rotX = glm::rotate(rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotY = glm::rotate(rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotZ = glm::rotate(rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 rotate = rotZ * rotY * rotX;

	// TRANSLATE * SCALE * ROTATE

	return translate * rotate;
}

void Transform::posite(const glm::vec3& position) {
	this->position += position;
}

void Transform::rotate(float rotation, const glm::vec3& axis) {
	this->rotation += glm::rotate(this->rotation, rotation, axis);

	// TODO FIX | REPLACE WITH QUATERNIONS

	//debug.info(std::to_string(rotation) + " * " + std::to_string(this->rotation.x) + ":" + std::to_string(this->rotation.y) + ":" + std::to_string(this->rotation.z));
	//debug.info(std::to_string(rotation) + " * " + std::to_string(axis.x) + ":" + std::to_string(axis.y) + ":" + std::to_string(axis.z));
}

glm::vec3 Transform::up() const {
	glm::vec3 up = glm::vec3(0, 1, 0);
	
	up = glm::rotateX(up, rotation.x);
	up = glm::rotateY(up, rotation.y);
	up = glm::rotateZ(up, rotation.z);
	
	return up;
}

glm::vec3 Transform::down() const {
	return -up();
}

glm::vec3 Transform::left() const {
	glm::vec3 left = glm::vec3(-1, 0, 0);
	
	left = glm::rotateX(left, rotation.x);
	left = glm::rotateY(left, rotation.y);
	left = glm::rotateZ(left, rotation.z);
	
	return left;
}

glm::vec3 Transform::right() const {
	return -left();
}

glm::vec3 Transform::forward() const {
	glm::vec3 forward = glm::vec3(0, 0, -1);
	
	forward = glm::rotateX(forward, rotation.x);
	forward = glm::rotateY(forward, rotation.y);
	forward = glm::rotateZ(forward, rotation.z);
	
	return forward;
}

glm::vec3 Transform::backward() const {
	return -forward();
}
