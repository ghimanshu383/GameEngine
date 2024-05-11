#include "Log.h"

namespace hazel {

	shared<spdlog::logger> Log::logger_engine;
	shared<spdlog::logger> Log::logger_app;
	void Log::init() {

		spdlog::set_pattern("%^[%T]  %n: %v%$");
		logger_engine = spdlog::stdout_color_mt("ENGINE");
		logger_engine->set_level(spdlog::level::trace);

		logger_app = spdlog::stdout_color_mt("APP");
		logger_app->set_level(spdlog::level::trace);
	}
}