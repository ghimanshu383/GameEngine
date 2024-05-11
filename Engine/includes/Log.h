#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Core.h"

namespace hazel {
	class Log {
	private:
		static shared<spdlog::logger> logger_engine;
		static shared<spdlog::logger> logger_app;
	public:
		static void init();
		static shared<spdlog::logger> engineLogger() { return logger_engine; };
		static shared<spdlog::logger> appLogger() { return logger_app; };
	};
}