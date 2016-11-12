#include <iostream>

#include <FreeImage.h>
#include <GL/glew.h>
#include "graphics\materials\SimpleMaterial.h"
#include "geometry\Mesh.h"
#include "graphics\Window.h"
#include "graphics\SimpleRenderer.h"
#include "graphics\shaders\Shader.h"
#include "math\Math.h"
#include "io\FileUtils.h"
#include "util\OBJLoader.h"

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
	using namespace IO;
	using namespace utility;

	Window* window = new Window("Engine!", 650, 350);
	glewInit();

	//readFile("res/TestModel.obj");

	int i = 0;


	//readFileLines("res/TestModel.obj");


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

	char* vertexShader = readFile("res/shaders/SimpleVertexShader.glsl");
	char* fragmentShader = readFile("res/shaders/SimpleFragmentShader.glsl");

	Shader* shader = new Shader(vertexShader, fragmentShader);
	Texture* texture = new Texture(	"res/textures/grass.jpg");
	Mesh* mesh = loadOBJModel("res/TestModel.obj");
	SimpleRenderer* renderer = new SimpleRenderer();
	SimpleMaterial* material = new SimpleMaterial(shader, texture);
	Matrix4f projection = Matrix4f::perspective((float)window->getWidth() / (float)window->getHeight(), 90.0f, 0.1f, 1000.0f);

	float y = 0;

	Matrix4f translation = Matrix4f::translation(Vector3f(0.0f, 0.0f, -5.0f));

	//Matrix4f transform = Matrix4f::transformation(Matrix4f::identity(), Matrix4f::identity(), Matrix4f::translation(Vector3f(0.0f, 0.0f, -2.0f)));

	shader->bind();

	while (!window->shouldClose()) {
		y += 12.5f;
		renderer->prepareRender();
		shader->loadUniformMat4f("projection", projection);
		Matrix4f rotation = Matrix4f::rotation(Vector3f(0.0f, 1.0f, 0.0f), y);

		shader->loadUniformMat4f("transform", Matrix4f::transformation(rotation, Matrix4f::identity(), translation));
		renderer->renderMesh(mesh, material);

		window->tick();
		if (window->getInputManager()->keyPressed(GLFW_KEY_ESCAPE)) break;
		window->render();
	}
	shader->unBind();
	delete shader;
	delete texture;
	delete mesh;
	delete renderer;
	delete material;
	delete window;
	delete vertexShader;
	delete fragmentShader;
	return 0;
}