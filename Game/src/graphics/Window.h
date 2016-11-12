#pragma once

#include <GLFW/glfw3.h>
#include "..\io\InputManager.h"

namespace engine { 
	namespace IO {class InputManager;}
	namespace graphics {

		class Window {
			unsigned int width, height;
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
			inline unsigned int getWidth() const { return width; }
			inline unsigned int getHeight() const { return height; }
		};

	}
}