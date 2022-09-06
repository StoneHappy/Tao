#include "Tao/Function/Script/index.h"
#include "sol/sol.hpp"

namespace Tao::Function {
    ScriptSystem::ScriptSystem()
    {
        m_lua_state.open_libraries(sol::lib::base,
                             sol::lib::package,
                             sol::lib::coroutine,
                             sol::lib::string,
                             sol::lib::os,
                             sol::lib::math,
                             sol::lib::table,
                             sol::lib::debug,
                             sol::lib::bit32,
                             sol::lib::io,
                             sol::lib::utf8);
    }
    sol::protected_function_result ScriptSystem::runScript(const std::filesystem::path& script_path)
    {
        return m_lua_state.script_file(script_path.string());
    }
    sol::protected_function_result ScriptSystem::runCode(const std::string& script)
    {
        return m_lua_state.script(script);
    }
    void ScriptSystem::bindComponent()
    {

    }
}