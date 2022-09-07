#include "Tao/Core/index.h"
#include "Tao/Function/LogSystem/index.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

namespace Tao
{
    namespace Core {
        
        Application::Application(int argc, char** argv)
            : m_ExePath(std::filesystem::path(argv[0]).parent_path())
        {
            praseCmdline(argc, argv);
            g_runtime_global_context.startSystems();
            LOG_DEBUG("Application is running!");
            if (cmdline_parser.exist("init")) initProject();
            if (cmdline_parser.exist("run")) 
            {
                loadLua();
            }

            g_runtime_global_context.m_window->show();
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
            )", false, "TaoLua/");
            cmdline_parser.add("init", '\0', "Init project at workingspace");
            cmdline_parser.add("run", '\0', "Run project at workingspace");
            cmdline_parser.parse_check(argc, argv);
            m_LuaPath = cmdline_parser.get<std::string>("scriptpath");
        }

        void Application::loadLua()
        {
            if (!std::filesystem::exists(std::filesystem::current_path()/"main.lua")) {
std::ofstream mainlua(std::filesystem::current_path()/"main.lua");
                if (mainlua) {
                    mainlua.clear();
                    mainlua << \
R"(log = require("lua.log")
function main()
    log.trace('Tao: hello world!')
end
)"               \
                    << std::endl;
                }
                mainlua.close();
            }

            g_runtime_global_context.m_script_system->runScript(std::filesystem::current_path()/"main.lua");
            g_runtime_global_context.m_script_system->runCode("main()");
            // if (std::filesystem::is_directory(luapath) && !std::filesystem::is_empty(m_LuaPath/"main.lua")) {
            //     g_runtime_global_context.m_script_system->runScript(luapath/"main.lua");
            //     g_runtime_global_context.m_script_system->runCode("main()");
            // }
            // else if(luapath.extension()==".lua") {
            //     g_runtime_global_context.m_script_system->runScript(luapath);
            //     g_runtime_global_context.m_script_system->runCode("main()");
            // }
            // else {
            //     LOG_ERROR("Please input luafile to Tao!")
            // }
        }

        void Application::initProject()
        {
            LOG_INFO("Initializating project begin...")
            if (std::filesystem::exists(m_ExePath/"resources"/"lua")) {
                if (std::filesystem::exists(std::filesystem::current_path()/"lua")) std::filesystem::remove_all(std::filesystem::current_path()/"lua");
                std::filesystem::copy(m_ExePath/"resources"/"lua", std::filesystem::current_path()/"lua");
                std::ofstream mainlua(std::filesystem::current_path()/"main.lua");
                if (mainlua) {
                    mainlua.clear();
                    mainlua << \
R"(log = require("lua.log")
function main()
    log.trace('Tao: hello world!')
end
)"               \
                    << std::endl;
                }
                mainlua.close();
                if (std::filesystem::exists(std::filesystem::current_path()/".Tao/")) {
                    std::filesystem::remove_all(std::filesystem::current_path()/".Tao/");
                }
                std::filesystem::create_directory(std::filesystem::current_path()/".Tao/");
            }
            else {
                LOG_ERROR("Please install complete Tao!!!")
            }
            LOG_INFO("Initializating project end...")
        }
    }
}