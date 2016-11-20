#pragma once

#include <GLFW/glfw3.h>
#include <GL\glew.h>
#include <vector>
#include "..\io\InputManager.h"

typedef void(*WindowCallbackfun)();

namespace engine { 
	namespace IO {class InputManager;}
	namespace graphics {

		class Window {
			unsigned int width, height;
			std::vector<WindowCallbackfun> render_callbacks, update_callbacks, close_callbacks;
			GLFWwindow* window;	
			IO::InputManager* inputManager = nullptr;

			void executeCallbacks(std::vector<void(*)()> callbacks);

		public:
			Window(const char *title, const unsigned int &width, const unsigned int &height);

			~Window();

			void addRenderCallback(void* func);

			void addUpdateCallback(WindowCallbackfun);

			void addCloseCallback(WindowCallbackfun);

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