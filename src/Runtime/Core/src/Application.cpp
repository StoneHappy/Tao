#include "Tao/Core/index.h"
#include "Tao/Function/LogSystem/index.h"
#include <iostream>
#include <string>
#include <filesystem>

namespace Tao
{
    namespace Core {
        
        Application::Application(int argc, char** argv)
        {
            praseCmdline(argc, argv);
            g_runtime_global_context.startSystems(m_LuaPath);
            LOG_DEBUG("Application is running!");
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
            cmdline_parser.add("init", '\0', "Init project at workingspace");
            cmdline_parser.parse_check(argc, argv);
            m_LuaPath = cmdline_parser.get<std::string>("scriptpath");
        }

        void Application::loadLua(const std::filesystem::path& luapath)
        {
            if (std::filesystem::is_directory(luapath) && !std::filesystem::is_empty(m_LuaPath/"main.lua")) {
                g_runtime_global_context.m_script_system->runScript(luapath/"main.lua");
                g_runtime_global_context.m_script_system->runCode("main()");
            }
            else if(luapath.extension()==".lua") {
                g_runtime_global_context.m_script_system->runScript(luapath);
                g_runtime_global_context.m_script_system->runCode("main()");
            }
            else {
                LOG_ERROR("Please input luafile to Tao!")
            }
        }

        void Application::initProject()
        {
            
        }
    }
}