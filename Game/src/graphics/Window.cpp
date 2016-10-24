#include <iostream>
#include "Window.h"

namespace engine { namespace graphics {


		void error_callback(int error, const char* description)
		{
			fprintf(stderr, "Error: %s\n", description);
		}

		Window::Window(const char *title, const unsigned int &width, const unsigned int &height) {
			if (!glfwInit()) {
				glfwTerminate();
				return;
			}
			glfwSetErrorCallback(error_callback);

			window = glfwCreateWindow(width, height, title, NULL, NULL);

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

			glfwMakeContextCurrent(window);
			glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

			glfwSwapInterval(1);
			glfwShowWindow(window);
		}

		Window::~Window() {
			glfwTerminate();
			glfwDestroyWindow(window);
		}

		void Window::render() {
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		bool Window::shouldClose() {
			return glfwWindowShouldClose(window);
		}
	}
}