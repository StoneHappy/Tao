#pragma once
#include "cpp-utilities/dll.h"
#include <cmdline.h>
#include <filesystem>
namespace Tao
{
    namespace Core {
        class CPP_UTIL_API Application
        {
        public:
            Application(int argc, char** argv);
        private:
            cmdline::parser cmdline_parser;
            std::filesystem::path m_LuaPath;

        private:
            void PraseCmdline(int argc, char** argv);
        };
    }
}