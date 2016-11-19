#pragma once

#include "..\graphics\Window.h"
#include <iostream>
#include "..\math\Vector2f.h"

#define MAX_KEYS 348
#define MAX_BUTTONS 3

namespace engine { namespace IO {

	class InputManager {
		GLFWwindow* window = nullptr;

	public:
		bool keysDown[MAX_KEYS],
			 keysPressed[MAX_KEYS],
			 buttonsDown[MAX_KEYS],
			 buttonsPressed[MAX_BUTTONS];

		math::Vector2f mousePosition;

	public:
		InputManager(GLFWwindow* window);

		inline GLFWwindow* getWindow() { return window; }

		inline math::Vector2f getMousePosition() { return mousePosition; }

		bool keyDown(unsigned int key);

		bool keyPressed(unsigned int key);


		bool buttonDown(unsigned int button);

		bool buttonPressed(unsigned int button);

		void tick();
	};
}}