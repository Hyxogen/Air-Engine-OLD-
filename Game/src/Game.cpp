#include <iostream>

#include <FreeImage.h>
#include <GL/glew.h>
#include "geometry\Mesh.h"
#include "graphics\Window.h"
#include "graphics\SimpleRenderer.h"
#include "graphics\shaders\Shader.h"
#include "math\Math.h"

char* vertexShader = "#version 430 core\n" \
"layout (location = 0) in vec3 vertexPosition;\n" \
"layout (location = 1) in vec2 vertexUV; \n" \
"out vec2 uv; \n" \
"uniform mat4 projection;" \
"uniform mat4 transform;" \
"void main() {\n" \
"gl_Position = vec4(vertexPosition, 1.0);\n" \
" uv = vertexUV; }";
char* fragmentShader = "#version 430 core \n " \
" in vec2 uv; \n" \
" out vec4 outputColor; \n "\
" uniform sampler2D textureSampler;\n" \
" void main() {outputColor = texture(textureSampler, uv);}";

int main() {
	using namespace engine;
	using namespace graphics;
	using namespace geometry;
	using namespace rendering;
	using namespace math;

	Window window("Engine!", 650, 350);

	glewInit();

	std::vector<GLfloat> vertices = {
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};

	std::vector<GLfloat> uvs = {
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f
	};

	std::vector<GLuint> indices = {
			0, 1, 2, 2, 3, 0
	};

	Shader* shader = new Shader(vertexShader, fragmentShader);
	Texture* texture = new Texture("res/grass.jpg");
	Mesh* mesh = new Mesh(vertices, uvs, indices, texture);
	SimpleRenderer* renderer = new SimpleRenderer();

	shader->bind();

	while (!window.shouldClose()) {
		renderer->prepareRender();
		renderer->renderMesh(mesh, shader);
		window.render();

	}
	shader->unBind();
	delete shader;
	delete texture;
	delete mesh;
	delete renderer;
	return 0;
}