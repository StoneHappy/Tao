#pragma once
#include "cpp-utilities/dll.h"
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

        private:
            void PraseCmdline(int argc, char** argv);
        };
    }
}