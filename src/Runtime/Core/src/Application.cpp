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
                LoadLua(m_LuaPath);
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

        void Application::LoadLua(const std::filesystem::path& luapath)
        {
            m_Lua.open_libraries(sol::lib::base);
            m_Lua.script_file((m_LuaPath/"main.lua").string());
            m_Lua.script("main()");
        }
    }
}