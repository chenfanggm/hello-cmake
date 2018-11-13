#pragma once

#include <memory>
#include "Core.h"
#include <spdlog/spdlog.h>

namespace viper {
    class Log {
        public:
            static void Init();
            inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { 
                return s_CoreLogger;
            }
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { 
                return s_ClientLogger;
            }
        private:
            static std::shared_ptr<spdlog::logger> s_CoreLogger;
            static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define VIPER_CORE_FATAL(...) ::viper::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define VIPER_CORE_ERROR(...) ::viper::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VIPER_CORE_WARN(...) ::viper::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VIPER_CORE_INFO(...) ::viper::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VIPER_CORE_TRACE(...) ::viper::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define VIPER_FATAL(...) ::viper::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define VIPER_ERROR(...) ::viper::Log::GetClientLogger()->error(__VA_ARGS__)
#define VIPER_WARN(...) ::viper::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VIPER_INFO(...) ::viper::Log::GetClientLogger()->info(__VA_ARGS__)
#define VIPER_TRACE(...) ::viper::Log::GetClientLogger()->trace(__VA_ARGS__)
