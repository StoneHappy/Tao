#include "GLFW/glfw3.h"
#include "Tao/FrontEnd/index.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <stdint.h>
#include <string>
std::unordered_map<GLFWwindow*, Tao::FrontEnd::Window*> Tao::FrontEnd::Window::m_s_WINDOWS_MAP;

namespace Tao
{
    namespace FrontEnd {
        Window::Window(const Tao::FrontEnd::Context::Device& p_device, const Tao::FrontEnd::Settings::WindowSettings& p_windowSettings)
            :m_device(p_device)
        {
            CreateGlfwWindow(p_windowSettings);
        }

        void Window::CreateGlfwWindow(const Tao::FrontEnd::Settings::WindowSettings& p_windowSettings)
        {
            m_glfwWindow = glfwCreateWindow(200, 300, "Tao", nullptr, nullptr);
            if (m_glfwWindow==nullptr) {
                throw std::runtime_error("glfwwindow create error!");
            }
        }


        Window::~Window()
        {
            glfwDestroyWindow(m_glfwWindow);
        }

        void Window::SwapBuffers()
        {
            glfwSwapBuffers(m_glfwWindow);
        }

        bool Window::ShouldClose()
        {
            return glfwWindowShouldClose(m_glfwWindow);
        }

        void Window::SetShouldClose(bool p_value)
        {
            glfwSetWindowShouldClose(m_glfwWindow, p_value);
        }
    }
}