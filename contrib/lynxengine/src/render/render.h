#ifndef render_h
#define render_h

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include <../src/resource/asset/sprite.h>
#include <../src/resource/asset/shader.h>
#include <../src/resource/asset/mesh.h>

#include <../src/ces/component/camera.h>

class Render {
private:
	// Member Variables

	Shared<Camera> camera;

	Shared<Mesh> meshCache = nullptr;
	Shared<Shader> shaderCache = nullptr;

public:
	// Member Functions

	void set_camera(Shared<Camera> camera = nullptr);

	bool sprite(glm::vec4 transform, Shared<Sprite> sprite, Shared<Shader> shader = nullptr);
	
	void mesh(glm::mat4 transform, Shared<Mesh> mesh, Shared<Shader> shader, Shared<Sprite> sprite = nullptr);
};

extern Render render;

#endif
