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
			this->width = width;
			this->height = height;
			glfwSetErrorCallback(error_callback);

			window = glfwCreateWindow(width, height, title, NULL, NULL);

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

			glfwMakeContextCurrent(window);
			
			glewInit();
			
			glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

			glfwSwapInterval(1);
			glfwShowWindow(window);
			glfwSetWindowUserPointer(window, this);

			this->inputManager = new IO::InputManager(window);
			glEnable(GL_DEPTH_TEST);

			while (!shouldClose()) {
				executeCallbacks(render_callbacks);

				tick();
				executeCallbacks(update_callbacks);

				render();
			}

			executeCallbacks(close_callbacks);
			delete this;
		}

		Window::~Window() {
			delete inputManager;
			glfwTerminate();
			glfwDestroyWindow(window);
			glDisable(GL_DEPTH_TEST);
		}

		void Window::executeCallbacks(std::vector<WindowCallbackfun> callbacks) {
			for (int i = 0; i < callbacks.size(); i++) {
				callbacks[i]();
			}
		}

		void Window::addRenderCallback(void* func) {
			render_callbacks.push_back(func);
		}

		void Window::addUpdateCallback(WindowCallbackfun func) {
			update_callbacks.push_back(func);
		}
		
		void Window::addRenderCallback(WindowCallbackfun func) {
			close_callbacks.push_back(func);
		}

		void Window::tick() {
			inputManager->tick();
			glfwPollEvents();
		}

		void Window::render() {
			glfwSwapBuffers(window);
		}


		bool Window::shouldClose() {
			return glfwWindowShouldClose(window);
		}
	}
}