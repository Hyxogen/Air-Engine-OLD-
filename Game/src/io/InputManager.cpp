#include "InputManager.h"

namespace engine { namespace IO {

	void key_callback(GLFWwindow* windowptr, int key, int scancode, int action, int mods);
	void mouse_callback(GLFWwindow* windowptr, int button, int action, int mods);

	InputManager::InputManager(GLFWwindow* window) {
		this->window = window;

		glfwSetKeyCallback(window, key_callback);
		glfwSetMouseButtonCallback(window, mouse_callback);
	}
	
	void key_callback(GLFWwindow* windowptr, int key, int scancode, int action, int mods) {
		if (key > MAX_KEYS) return;
		using namespace graphics;
		Window* window = (Window *)glfwGetWindowUserPointer(windowptr);
		InputManager* input = window->getInputManager();

		switch (action) {
		case GLFW_PRESS:
			if (input->keyDown(key)) break;
			input->keysDown[key] = true;
			input->keysPressed[key] = true;
			break;
		case GLFW_RELEASE:
			input->keysDown[key] = false;
			input->keysPressed[key] = false;
			break;
		}
	}

	void mouse_callback(GLFWwindow* windowptr, int button, int action, int mods) {
		std::cout << "Mouse Event" << std::endl;
		if (button > MAX_BUTTONS) return;
		using namespace graphics;
		Window* window = (Window *)glfwGetWindowUserPointer(windowptr);
		InputManager* input = window->getInputManager();

		switch (action) {
		case GLFW_PRESS:
			if (input->buttonDown(button)) break;
			input->buttonsDown[button] = true;
			input->buttonsPressed[button] = true;
			break;
		case GLFW_RELEASE:
			input->buttonsDown[button] = false;
			input->buttonsPressed[button] = false;
			break;
		}
	}

	void InputManager::tick() {
		memset(this->keysPressed, 0, MAX_KEYS);
		memset(this->buttonsPressed, 0, MAX_BUTTONS);
	}

	bool InputManager::keyDown(unsigned int key) {
		return keysDown[key];
	}

	bool InputManager::keyPressed(unsigned int key) {
		return keysPressed[key];
	}

	bool InputManager::buttonDown(unsigned int button) {
		return buttonsDown[button];
	}

	bool InputManager::buttonPressed(unsigned int button) {
		return buttonsPressed[button];
	}
}}