#include "Tao/Core/index.h"
#include <iostream>
#include <string>
#include <filesystem>

namespace Tao
{
    namespace Core {
        
        Application::Application(int argc, char** argv)
        {
            g_runtime_global_context.startSystems(m_LuaPath);
            LOG_DEBUG("Application is running!");
            praseCmdline(argc, argv);
            if (!std::filesystem::is_empty(m_LuaPath)) {
                loadLua(m_LuaPath);
            }
        }

        Application::~Application()
        {
            g_runtime_global_context.shutdownSystems();
        }

        void Application::praseCmdline(int argc, char** argv)
        {
            cmdline_parser.add<std::string>("scriptpath", 's', R"(
                Tao can run with lua script.
                Lua script is natively support to c/c++, runs as efficiently as c/c++.
            )", false, "./TaoLua/");
            cmdline_parser.parse_check(argc, argv);
            m_LuaPath = cmdline_parser.get<std::string>("scriptpath");
        }

        void Application::loadLua(const std::filesystem::path& luapath)
        {
            
        }
    }
}