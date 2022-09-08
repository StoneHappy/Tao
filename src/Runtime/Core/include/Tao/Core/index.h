#pragma once
#include "Tao/FrontEnd/index.h"
#include "Tao/Function/Script/index.h"
#include "cpp-utilities/dll.h"
#include <cmdline.h>
#include <filesystem>
#include <Tao/Function/LogSystem//index.h>
#include <memory>
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
            std::filesystem::path m_ExePath;
        private:
            /**
             * @brief prase Cmdline argues
             * 
             * @param argc 
             * @param argv 
             */
            void praseCmdline(int argc, char** argv);

            /**
             * @brief load main lua script from lua path
             * 
             * @param luapath main lua path
             */
            void loadLua();

            // TODO: init project!
            void initProject();
        };
        class RuntimeGlobalContext
        {
        public:
            /**
             * @brief Global Runtim Constext must start very first
             * @attention Must start very first!!!!
             * @param lua_path config lua path
             */
            void startSystems();
            /**
             * @brief destory global systems
             * @attention Must shutdown at last, otherwise it will be thread unsafe!
             */
            void shutdownSystems();

        public:
            std::shared_ptr<Tao::Function::LogSystem>           m_logger_system;
            std::shared_ptr<Tao::Function::ScriptSystem>        m_script_system;
        };

        extern RuntimeGlobalContext g_runtime_global_context;
    }
}

#define LOG_HELPER(LOG_LEVEL, ...) \
    Tao::Core::g_runtime_global_context.m_logger_system->log(LOG_LEVEL, "[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__);