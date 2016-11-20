#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include "..\io\InputManager.h"


namespace engine {
	namespace IO { class InputManager; }
	namespace graphics {

		typedef void(*WindowCallbackfun)();

		class Window {
			unsigned int width, height;
			float fps_cap = 60.0f, deltaTime = 0;
			std::vector<WindowCallbackfun> render_callbacks, update_callbacks, close_callbacks;
			GLFWwindow* window;
			IO::InputManager* inputManager = nullptr;

			void executeCallbacks(std::vector<WindowCallbackfun> callbacks);

		public:
			Window(const char *title, const unsigned int &width, const unsigned int &height);

			~Window();

			void addRenderCallback(WindowCallbackfun func);

			void addUpdateCallback(WindowCallbackfun func);

			void addCloseCallback(WindowCallbackfun func);

			void render();

			void tick();

			void start();

			bool shouldClose();

			inline GLFWwindow* getWindow() const { return window; }
			inline IO::InputManager* getInputManager() const { return inputManager; }
			inline unsigned int getWidth() const { return width; }
			inline unsigned int getHeight() const { return height; }
			inline void setFPSCap(unsigned int cap) { fps_cap = cap; }
			inline float getDeltaTime() const { return deltaTime; }

		};

	}
}