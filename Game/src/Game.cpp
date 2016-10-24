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
"gl_Position =  projection * transform * vec4(vertexPosition, 1.0);\n" \
" uv = vertexUV; }";
char* fragmentShader = "#version 430 core \n " \
" in vec2 uv; \n" \
" out vec4 outputColor; \n "\
" uniform sampler2D textureSampler;\n" \
" void main() {outputColor = vec4(uv, 1.0, 1.0);}";

int main() {
	using namespace engine;
	using namespace graphics;
	using namespace geometry;
	using namespace rendering;
	using namespace math;

	Window window("Engine!", 650, 350);
	
	glewInit();

	Vector4f vector(1.0f, 2.0f, 3.0f, 4.0f);

	std::cout << vector.vectors[1] << std::endl;
	
	std::vector<GLfloat> vertices = {
		-0.5f, 0.5f, 0.0f, 
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f, 
		0.5f, 0.5f, 0.0f
	};

	std::vector<GLfloat> uvs = {
		0.0f, 1.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f
	};

	std::vector<GLuint> indices = {
			0, 1, 2, 2, 3, 0
	};

	std::cout << vertices.size() << std::endl;
	Texture texture("C:\\Users\\Daan\\Downloads\\Grass_Texture.bmp");
	Mesh mesh(vertices, uvs, indices, &texture);
	Matrix4f projection = Matrix4f::orthographic(-2.0f, 2.0f, -1.0f, 1.0f, -1.0f, 1000.0f);
	//Matrix4f projection = Matrix4f::perspective(650.0f / 350.0f, 90, 0.0f, 100.0f);
	SimpleRenderer renderer;

	Shader shader(vertexShader, fragmentShader);

	shader.bind();

	Matrix4f identity(1.0f);
	
	shader.loadUniformMat4f("projection", projection);
	while (!window.shouldClose()) {
		renderer.prepareRender();
		shader.loadUniformMat4f("transform", identity);
		renderer.renderMesh(mesh);
		window.render();

	}
	shader.unBind();
	return 0;
}