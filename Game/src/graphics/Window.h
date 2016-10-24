#pragma once

#include <GLFW/glfw3.h>

namespace engine { namespace graphics {

		class Window {
			GLFWwindow* window;

		public:
			Window(const char *title, const unsigned int &width, const unsigned int &height);

			~Window();

			void render();

			bool shouldClose();

			inline GLFWwindow* getWindow() const { return window; }
		};

	}
}