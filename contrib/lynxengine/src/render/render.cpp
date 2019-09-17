#include "render.h"

#include <../src/core/core.h>

Render render;

// Member Functions

void Render::set_camera(Shared<Camera> camera) {
	//if (this->camera == camera) return;

	// Bind Framebuffers & Calculate Viewport Size

	glm::vec2 size;

	if (camera && camera->target) {
		glBindFramebuffer(GL_FRAMEBUFFER, camera->target->buffer);

		size = camera->target->colour->get_size();
	}
	else {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		size = core.display.get_size();
	}

	glViewport(0, 0, (int) size.x, (int) size.y);

	

	this->camera = camera;
}

bool Render::sprite(glm::vec4 transform, Shared<Sprite> sprite, Shared<Shader> shader) {
	glm::vec2 screenSize = core.display.get_size();

	// Generate Matrix

	

	return true;
}

void Render::mesh(glm::mat4 transform, Shared<Mesh> mesh, Shared<Shader> shader, Shared<Sprite> sprite) {
	// Generate Projection & View Matrices

	glm::mat4 projection = (camera) ? camera->projection() : glm::mat4(1.0f);

	glm::mat4 view = (camera && camera->transform) ? glm::inverse(camera->transform->matrix()) : glm::mat4(1.0f);

	// Draw

	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	if (!mesh || !mesh->ready()) return;

	if (mesh != meshCache) {
		glBindVertexArray(mesh->vao);

		meshCache = mesh;
	}

	if (!shader || !shader->ready()) return;

	if (shader != shaderCache) {
		glUseProgram(shader->program);

		shaderCache = shader;
	}
	
	if (sprite && sprite->ready()) {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sprite->pos);
		
		shader->set("diffuseSampler", sprite->pos);
	}

	shader->set("modelMat", transform);
	shader->set("viewMat", view);
	shader->set("projMat", projection);

	glDrawArrays(GL_TRIANGLES, 0, mesh->size);

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
}
