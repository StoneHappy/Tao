#include "Tao/Function/Script/index.h"

namespace Tao::Function {
    ScriptSystem::ScriptSystem()
    {
        m_lua_state.open_libraries(sol::lib::base);
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