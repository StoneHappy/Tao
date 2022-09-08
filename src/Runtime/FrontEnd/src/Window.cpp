#include "GLFW/glfw3.h"
#include "Tao/FrontEnd/index.h"
#include <cstddef>
#include <iostream>
#include <memory>
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

        void Window::show(){
            while (!glfwWindowShouldClose(m_glfwWindow))
            {
                glfwPollEvents();
            }
        }

        void Window::CreateGlfwWindow(const Tao::FrontEnd::Settings::WindowSettings& p_windowSettings)
        {
            m_glfwWindow = glfwCreateWindow(p_windowSettings.width, p_windowSettings.height, p_windowSettings.title.c_str(), nullptr, nullptr);
        }


        Window::~Window(){
            glfwDestroyWindow(m_glfwWindow);
        }
    }
}