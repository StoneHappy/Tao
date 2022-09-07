#include "Tao/Core/index.h"
#include "Tao/FrontEnd/index.h"
#include "Tao/Function/LogSystem/index.h"
#include "Tao/Function/Script/index.h"
#include <memory>
namespace Tao
{
    namespace Core {
        RuntimeGlobalContext g_runtime_global_context;
        void RuntimeGlobalContext::startSystems()
        {
            m_logger_system = std::make_shared<Tao::Function::LogSystem>();
            m_script_system = std::make_shared<Tao::Function::ScriptSystem>();
            m_window        = std::make_shared<Tao::FrontEnd::GLFW_Window>("Tao", 1024, 768);
        }

        void RuntimeGlobalContext::shutdownSystems()
        {
            m_logger_system.reset();
        }
    }
}