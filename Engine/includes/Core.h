#include <stdio.h>
#include <memory>
#include <vector>
#include <Log.h>

template<typename T> 
using List = std::vector<T>;

template<typename T>
using shared = std::shared_ptr<T>;

template<typename T>
using unique = std::unique_ptr<T>;

template<typename T>
using weak = std::weak_ptr<T>;


#define Log(M, ...) printf(M " \n", ##__VA_ARGS__)

#define Log_info_core(M, ...)   hazel::Log::engineLogger()->info(M " \n", ##__VA_ARGS__);
#define Log_warn_core(M, ...)   hazel::Log::engineLogger()->warn(M " \n", ##__VA_ARGS__);
#define Log_error_core(M, ...)  hazel::Log::engineLogger()->error(M " \n", ##__VA_ARGS__);
#define Log_fatal_core(M, ...)  hazel::Log::engineLogger()->fatal(M " \n", ##__VA_ARGS__);

#define Log_info(M, ...)   hazel::Log::appLogger()->info(M " \n", ##__VA_ARGS__);
#define Log_warn(M, ...)   hazel::Log::appLogger()->warn(M " \n", ##__VA_ARGS__);
#define Log_error(M, ...)  hazel::Log::appLogger()->error(M " \n", ##__VA_ARGS__);
#define Log_fatal(M, ...)  hazel::Log::appLogger()->fatal(M " \n", ##__VA_ARGS__);
