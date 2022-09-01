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
        sol::protected_function_result runScript(const std::filesystem::path& script_path);
        sol::protected_function_result runCode(const std::string& script);
    private:
        void bindComponent();
        sol::state m_lua_state;
    };
}