#include "Entry.h"
#include <functional>

#include "Log.h"
#include "Window.h"

extern void hazel::Run();

int main(int argc, char** args) {

	hazel::Log::init();
	hazel:: Run();
	shared<hazel::Window> engineWindow{ new hazel::Window() };
	weak<hazel::Window> weakWindow{ engineWindow };

	engineWindow->init();
	engineWindow->RenderWindow();
	return 0;
}