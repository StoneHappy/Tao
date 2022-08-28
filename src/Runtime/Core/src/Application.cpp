#include "Tao/Core/index.h"
#include <iostream>
#include <string>
#include <filesystem>
namespace Tao
{
    namespace Core {
        Application::Application(int argc, char** argv)
        {
            PraseCmdline(argc, argv);
            if (!std::filesystem::is_empty(m_LuaPath)) {
                std::cout << m_LuaPath << std::endl;
            }
        }


        void Application::PraseCmdline(int argc, char** argv)
        {
            cmdline_parser.add<std::string>("scriptpath", 's', R"(
                Tao can run with lua script.
                Lua script is natively support to c/c++, runs as efficiently as c/c++.
            )", false, "./TaoLua/");
            cmdline_parser.parse_check(argc, argv);
            m_LuaPath = cmdline_parser.get<std::string>("scriptpath");
        }
    }
}