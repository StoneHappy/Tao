#pragma once
#include "cpp-utilities/dll.h"
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <cmdline.h>
#include <filesystem>
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
    }
}