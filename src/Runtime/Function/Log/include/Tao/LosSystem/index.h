#pragma once
#include "cpp-utilities/dll.h"
#include <spdlog/spdlog.h>
namespace Tao
{
    namespace Core {
        class CPP_UTIL_API LogSystem final
        {
        public:
            /**
             * @brief log level
            
             */
            enum class LogLevel : uint8_t
            {
                debug,
                info,
                warn,
                error,
                fatal
            };

        public:
            LogSystem();
            ~LogSystem();

            /**
             * @brief log message by level
             * ```cpp
             * LogSystem log;
             * log.log(LogLevel::debug, "message!");
             * ```
             * @tparam TARGS 
             * @param level LogLevel::someleve
             * @param args log message
             */
            template<typename... TARGS>
            void log(LogLevel level, TARGS&&... args)
            {
                switch (level)
                {
                case LogLevel::debug:
                    m_logger->debug(std::forward<TARGS>(args)...);
                    break;
                case LogLevel::info:
                    m_logger->info(std::forward<TARGS>(args)...);
                    break;
                case LogLevel::warn:
                    m_logger->warn(std::forward<TARGS>(args)...);
                    break;
                case LogLevel::error:
                    m_logger->error(std::forward<TARGS>(args)...);
                    break;
                case LogLevel::fatal:
                    m_logger->critical(std::forward<TARGS>(args)...);
                    fatalCallback(std::forward<TARGS>(args)...);
                    break;
                default:
                    break;
                }
            }

            template<typename... TARGS>
            void fatalCallback(TARGS&&... args)
            {
                const std::string format_str = fmt::format(std::forward<TARGS>(args)...);
                throw std::runtime_error(format_str);
            }

        private:
            std::shared_ptr<spdlog::logger> m_logger;
        };

    }
}

#define LOG_HELPER(LOG_LEVEL, ...) \
    Tao::Core::g_runtime_global_context.m_logger_system->log(LOG_LEVEL, "[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__);

#define LOG_DEBUG(...) LOG_HELPER(Tao::Core::LogSystem::LogLevel::debug, __VA_ARGS__);

#define LOG_INFO(...) LOG_HELPER(Tao::Core::LogSystem::LogLevel::info, __VA_ARGS__);

#define LOG_WARN(...) LOG_HELPER(Tao::Core::LogSystem::LogLevel::warn, __VA_ARGS__);

#define LOG_ERROR(...) LOG_HELPER(Tao::Core::LogSystem::LogLevel::error, __VA_ARGS__);

#define LOG_FATAL(...) LOG_HELPER(Tao::Core::LogSystem::LogLevel::fatal, __VA_ARGS__);


#ifndef NDEBUG
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define DEBUGBREAK() __debugbreak()
//#else
//#define DEBUGBREAK()
#endif
#else
#define DEBUGBREAK()
#endif // !NDEBUG

#define ASSERT(checked, ...) { if(!(checked)) { LOG_ERROR(__VA_ARGS__); DEBUGBREAK(); } }
