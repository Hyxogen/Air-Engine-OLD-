#include <iostream>

#define DEPRECATED_USAGE

#ifdef _WINDOWS_
#    undef _WINDOWS_
#endif
#include <Windows.h>
#include <FreeImage.h>  
#include <GL/glew.h>
#include "TestBehaviour.h"
#include "graphics\materials\SimpleMaterial.h"
#include "geometry\Mesh.h"
#include "graphics\Window.h"
#include "graphics\SimpleRenderer.h"
#include "graphics\shaders\Shader.h"
#include "math\Math.h"
#include "io\FileUtils.h"
#include "util\OBJLoader.h"
#include "util\Timer.h"
#include "entity\Entity.h"
#include "entity\EntityBehaviour.h"

void render();

void tick();

engine::rendering::SimpleRenderer* renderer = new engine::rendering::SimpleRenderer();
engine::math::Matrix4f projection = engine::math::Matrix4f::perspective(650.0f / 350.0f, 90.0f, 0.1f, 1000.0f);

#ifdef OBSOLETE_LOOP
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
	Texture* texture = new Texture(	"res/stallTexture.png");
	Mesh* mesh = loadOBJModel("res/stall.obj");
	SimpleMaterial* material = new SimpleMaterial(shader, texture);
	SimpleRenderer* renderer = new SimpleRenderer();
	Matrix4f projection = Matrix4f::perspective((float)window->getWidth() / (float)window->getHeight(), 90.0f, 0.1f, 1000.0f);


	float y = 0;

	Matrix4f translation = Matrix4f::translation(Vector3f(0.0f, 0.0f, -5.0f));

	//Matrix4f transform = Matrix4f::transformation(Matrix4f::identity(), Matrix4f::identity(), Matrix4f::translation(Vector3f(0.0f, 0.0f, -2.0f)));

	Matrix4f rotation = Matrix4f::identity();

	Timer* timer = new Timer();
	Timer* time = new Timer();
	float t = 0;
	while (!window->shouldClose()) {
		timer->reset();
		material->enable();
		y += 1.0f;
		renderer->prepareRender();
		material->getShader()->loadUniformMat4f("projection", projection);
		rotation = Matrix4f::rotation(Vector3f(0.0f, 1.0f, 0.0f), y);

		rotation = rotation * Matrix4f::rotation(Vector3f(1.0f, 0.0f, 0.0f), y);
//		rotation = rotation * Matrix4f::rotation(Vector3f(0.0f, 0.0f, 1.0f), y);


		material->getShader()->loadUniformMat4f("transform", Matrix4f::transformation(rotation, Matrix4f::identity(), translation));
		renderer->renderMesh(mesh, material);

		window->tick();
		if (window->getInputManager()->keyPressed(GLFW_KEY_ESCAPE)) break;
		window->render();
		material->disable();
		if (time->elapsed() - t > 1.0f) {
			t += 1.0f;
			printf("Hello \n");
		}
	}
	delete timer;
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
#endif

int main() {
	using namespace engine;
	using namespace graphics;
	using namespace geometry;
	using namespace rendering;
	using namespace math;
	using namespace IO;
	using namespace utility;
	using namespace entity;

	Window* window = new Window("Engine!", 650, 350);
	glewInit();

	Shader* shader = new Shader(readFile("res/shaders/SimpleVertexShader.glsl"), readFile("res/shaders/SimpleFragmentShader.glsl"));
	Texture* texture = new Texture("res/stallTexture.png");
	Mesh* mesh = loadOBJModel("res/stall.obj");
	SimpleMaterial* material = new SimpleMaterial(shader, texture);

	engine::entity::Entity* entity = new engine::entity::Entity();
	entity->mesh = mesh;
	entity->material = material;
	//TODO ADD MATERIAL AND MESH TO ENTITY ^
	entity->addBehaviour(TestBehaviour());



	std::cout << "Size of Matrix4f " << sizeof(Matrix4f) << std::endl;

	window->addRenderCallback(render);
	window->addUpdateCallback(tick);

	window->start();

	delete renderer;
	delete shader;
	delete texture;
	delete mesh;
	delete material;
	//glewInit();
}

void render() {
	using namespace engine;
	using namespace rendering;
	using namespace entity;

	Entity* entity = Entity::getEntities()[0];
	entity->material->enable();
	renderer->prepareRender();

	entity->material->getShader()->loadUniformMat4f("projection", projection);
	entity->material->getShader()->loadUniformMat4f("transform", math::Matrix4f::translation(math::Vector3f(0.0f, 0.0f, -10.0f)));

	renderer->renderMesh(entity->mesh, entity->material);
	entity->material->disable();
}

void tick() {
	engine::entity::Entity::tickEntities();
}

void close() {

}