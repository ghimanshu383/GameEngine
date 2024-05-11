#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"

namespace hazel {
	bool Window::init(WindowParameters& parameters) {
		if (!glfwInit()) {
			Log_error("The Initialization of the window failed");
			return false;
		}
		window = glfwCreateWindow(parameters.width, parameters.height, parameters.title, NULL, NULL);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, keyCallback);


		if (glewInit() != GLEW_OK) {
			Log_error("The Initialization of the glew failed");
			return false;
		}

	}

	void Window::RenderWindow() {

		while (!glfwWindowShouldClose(window)) {
			glClearColor(.1f, .2f, .3f, 1.f);
			glClear(GL_COLOR_BUFFER_BIT);
			OnUpdate();
			glfwSwapBuffers(window);
			glfwPollEvents();

		}
	}
	void Window::keyCallback(GLFWwindow* window, int key, int code, int action, int mode) {
		Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

		if (key == GLFW_KEY_ESCAPE) {
			glfwSetWindowShouldClose(theWindow->getCurrentWindow(), true);
			return;
		}

		if (key >= 0 && key < 1024) {
			if (action == GLFW_PRESS) {
				theWindow->getKeys()[key] = true;
			}
			if (action == GLFW_RELEASE) {
				theWindow->getKeys()[key] = false;
			}
		}
	}
	void Window::OnUpdate() {
		del.BroadCast();
	}
}