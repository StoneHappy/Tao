#pragma once
#include "cpp-utilities/dll.h"
#include "cpp-utilities/singleton.hpp"
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <cmdline.h>
#include <filesystem>
#include <spdlog/spdlog.h>
#include <Tao/Function/LosSystem//index.h>
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
            std::shared_ptr<Tao::Function::LogSystem>      m_logger_system;
        };

        extern RuntimeGlobalContext g_runtime_global_context;
    }
}

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
