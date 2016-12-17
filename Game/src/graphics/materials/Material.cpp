#include "Material.h"

namespace engine { namespace graphics {

	unsigned int Material::count = 0;

	Material::Material(Shader* shader) : id(count++){
		this->shader = shader;
		std::cout << "IS THIS EVEN BEING CALLED?" << std::endl;

	}
	
	void Material::prepareShader(geometry::Mesh* mesh) {

	}

	void Material::enable() {
		this->shader->bind();
	}

	void Material::disable() {
		this->shader->unBind();
	}

}}