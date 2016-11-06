#pragma once

#include <GLFW/glfw3.h>
#include "..\io\InputManager.h"

namespace engine { 
	namespace IO {class InputManager;}
	namespace graphics {

		class Window {
			GLFWwindow* window;
			IO::InputManager* inputManager = nullptr;

		public:
			Window(const char *title, const unsigned int &width, const unsigned int &height);

			~Window();

			void render();

			void tick();

			bool shouldClose();

			inline GLFWwindow* getWindow() const { return window; }
			inline IO::InputManager* getInputManager() const { return inputManager; }
		};

	}
}