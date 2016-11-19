#version 430 core
in vec2 uv;

out vec4 outputColor;

uniform sampler2D textureSampler;

void main() {
	//outputColor = vec4(uv.y, 1.0f, 1.0f, 1.0f);
	outputColor = texture(textureSampler, uv);
}