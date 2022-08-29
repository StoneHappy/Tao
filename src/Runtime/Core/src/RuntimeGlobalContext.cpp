#include "Tao/Core/index.h"
namespace Tao
{
    namespace Core {
        RuntimeGlobalContext g_runtime_global_context;
        void RuntimeGlobalContext::startSystems(const std::filesystem::path& lua_path)
        {
            m_logger_system = std::make_shared<LogSystem>();
        }

        void RuntimeGlobalContext::shutdownSystems()
        {
            m_logger_system.reset();
        }
    }
}