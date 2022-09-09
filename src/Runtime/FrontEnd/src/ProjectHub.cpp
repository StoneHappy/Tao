#include "Tao/FrontEnd/index.h"
#include <memory>

namespace Tao::FrontEnd {
    ProjectHub::ProjectHub()
    {
        Tao::FrontEnd::Settings::DeviceSettings deviceSetting;
        Tao::FrontEnd::Settings::WindowSettings windowSettings;

        windowSettings.width = 1024;
        windowSettings.height = 720;
        windowSettings.title = "Tao";

        m_device = std::make_unique<Tao::FrontEnd::Context::Device>(deviceSetting);
        m_window = std::make_unique<Tao::FrontEnd::Window>(*m_device,  windowSettings);
    }

    void ProjectHub::Run()
    {
        while (!m_window->ShouldClose()) {
            m_device->PollEvents();
        }
    }
}