#include "Entry.h"
#include <functional>

#include "Log.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

extern void hazel::Run();

int main(int argc, char** args) {

	hazel::Log::init();
	hazel:: Run();
	if (!glfwInit()) {
		Log_error("The INitizliation of the window failed");
		return 0;
	}
	GLFWwindow* window = glfwCreateWindow(1200, 800, "Main Window", NULL, NULL);
	glfwWindowHint(GL_MAJOR_VERSION, 3);
	glfwWindowHint(GL_MINOR_VERSION, 3);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		Log_error("The Initiazitation of the glew failed");
		glfwTerminate();
		return 0;
	}

	while (!glfwWindowShouldClose(window)) {

		glClearColor(.1f, 0.2f, 0.3f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	return 0;
}
