#pragma once

#include <functional>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core.h"
#include "Delegate.h"
#include "Object.h"
#include "Events/KeyboardEvnets.h"

namespace hazel {

	struct WindowParameters {
		unsigned int width;
		unsigned int height;
		const char* title;

	public:
		WindowParameters(unsigned int width, unsigned int height, const char* title) : width{ width }, height{ height }, title{ title } {};
	};

	class Window : public Object{
	private:
		bool keys[1024];
		GLFWwindow* window;
		Delegate<> del;
		KeyboardEvents keyEvents{};

	public:
		bool init(WindowParameters& parameters = WindowParameters(1280, 720, "Main Window"));
		void RenderWindow();
		void OnUpdate();

		static void keyCallback(GLFWwindow* window, int key, int code, int action, int mode);
		GLFWwindow* getCurrentWindow()const { return window; };
		const bool* getKeys() const { return keys; };
		bool* getKeys() { return keys; };
		Delegate<> getDelegate() const { return del; };
-
	};
}