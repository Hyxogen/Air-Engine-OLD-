#include <iostream>
#include "Window.h"
#include "..\util\Timer.h"

namespace engine {
	namespace graphics {

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


			glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

			glfwSwapInterval(0);
			glfwShowWindow(window);
			glfwSetWindowUserPointer(window, this);

			this->inputManager = new IO::InputManager(window);
			glEnable(GL_DEPTH_TEST);
		}

		Window::~Window() {
			delete inputManager;
			glfwTerminate();
			glfwDestroyWindow(window);
			glDisable(GL_DEPTH_TEST);
		}

		void Window::start() {
			using namespace utility;
			int frames = 0;

			Timer* timer = new Timer();
			Timer* deltaTimer = new Timer();
			long time = 0;

			float delta = 0.0f;

			while (!shouldClose()) {
				deltaTimer->reset();

				glfwWaitEventsTimeout(1.0f / fps_cap);
				
				if (delta >= 1.0f / fps_cap) {
					tick();
					frames++;
					delta -= 1.0f / fps_cap;
					executeCallbacks(render_callbacks);
					render();
				}

				if (timer->elapsed() - time >= 1.0f) {
					time += 1.0f;

					printf("FPS %i\n", frames);
					frames = 0;
				}

				delta += deltaTimer->elapsed();

			}

			executeCallbacks(close_callbacks);
			delete timer;
			delete deltaTimer;
			delete this;
		}

		void Window::executeCallbacks(std::vector<WindowCallbackfun> callbacks) {
			for (int i = 0; i < callbacks.size(); i++) {
				callbacks[i]();
			}
		}

		void Window::addRenderCallback(WindowCallbackfun func) {
			render_callbacks.push_back(func);
		}

		void Window::addUpdateCallback(WindowCallbackfun func) {
			update_callbacks.push_back(func);
		}

		void Window::addCloseCallback(WindowCallbackfun func) {
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