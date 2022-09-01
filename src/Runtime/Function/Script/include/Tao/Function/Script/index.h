#pragma once
#include "sol/sol.hpp"
#include <cpp-utilities/dll.h>
#include <filesystem>
#include <string>
namespace Tao::Core {
    class RuntimeGlobalContext;
}
namespace Tao::Function
{
    class CPP_UTIL_API ScriptSystem
    {
    public:
        ScriptSystem();
        ~ScriptSystem() = default;
        /**
         * @brief run lua script file
         * 
         * #### Example Code
         * ```cpp
         * ScriptSystem scriptsystem;
         * scriptsystem.runScript("main.lua");
         * ```
         * 
         * @param script_path lua script file path
         * @return sol::protected_function_result 
         */
        sol::protected_function_result runScript(const std::filesystem::path& script_path);

        /**
         * @brief run lua code directly
         * 
         * #### Example Code
         * ```cpp
         * ScriptSystem scriptsystem;
         * scriptsystem.runScript("print('bark bark bark')");
         * ```
         * 
         * @param script 
         * @return sol::protected_function_result 
         */
        sol::protected_function_result runCode(const std::string& script);
    private:
        void bindComponent();
        sol::state m_lua_state;
    };
}