#pragma once
#include "cpp-utilities/dll.h"
#include "cpp-utilities/singleton.hpp"
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <cmdline.h>
#include <filesystem>
#include <spdlog/spdlog.h>
namespace Tao
{
    namespace Core {
        /**
         * @brief Tao Core Application config Tao app by cmdline.
         * 
         */
        class CPP_UTIL_API Application
        {
        public:
            /**
             * @brief Tao core application
             * @details 
                1. -s or --scriptpath Specify the Lua script file directory, and Tao will automatically parse the main.lua file in the directory. <br> 
                2. -? or --help Show all argurements.
             */
            Application(int argc, char** argv);
            ~Application();
        private:
            cmdline::parser cmdline_parser;
            std::filesystem::path m_LuaPath;
            sol::state m_Lua;
        private:
            /**
             * @brief prase Cmdline argues
             * 
             * @param argc 
             * @param argv 
             */
            void PraseCmdline(int argc, char** argv);

            /**
             * @brief load main lua script from lua path
             * 
             * @param luapath main lua path
             */
            void LoadLua(const std::filesystem::path& luapath);
        };

        class LogSystem final
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

        class RuntimeGlobalContext
        {
        public:
            /**
             * @brief Global Runtim Constext must start very first
             * @attention Must start very first!!!!
             * @param lua_path config lua path
             */
            void startSystems(const std::filesystem::path& lua_path);
            /**
             * @brief destory global systems
             * @attention Must shutdown at last, otherwise it will be thread unsafe!
             */
            void shutdownSystems();

        public:
            std::shared_ptr<LogSystem>      m_logger_system;
        };

        extern RuntimeGlobalContext g_runtime_global_context;
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
