#include "SandBox.h"
#include <Hazel.h>

namespace sb {
	void SandboxApplication::RunApplication() {
		const char* test = "test";
		Log_warn("The Engine started {0}", test);
	}
}
void hazel::Run() {
	unique<sb::SandboxApplication> sbApplication{ new sb::SandboxApplication() };
	sbApplication->RunApplication();
}



