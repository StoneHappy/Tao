#include "Tao/FrontEnd/index.h"
#include "GLFW/glfw3.h"
#include <stdexcept>
namespace Tao::FrontEnd::Context {
    Device::Device(const Tao::FrontEnd::Settings::DeviceSettings& p_deviceSettings)
    {
        int initializationCode = glfwInit();
        if (initializationCode == GLFW_FALSE) {
            throw std::runtime_error("Failed to Init GLFW!");
        }
        else {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, p_deviceSettings.contextMajorVersion);
		    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, p_deviceSettings.contextMinorVersion);
            // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, p_deviceSettings.contextMajorVersion);
		    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, p_deviceSettings.contextMinorVersion);
        }
        m_isAlive = true;
    }
    Device::~Device()
    {
        if (m_isAlive)
        {
            glfwTerminate();
        }
    }

    void Device::PollEvents() const
    {
        glfwPollEvents();
    }
}