#include "Tao/FrontEnd/index.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <memory>
#include <stdint.h>
#include <string>
namespace Tao
{
    namespace FrontEnd {
        GLFW_Window::GLFW_Window()
        {
            glfwInit();
            m_Window = glfwCreateWindow(200, 300, "Tao", nullptr, nullptr);
        }

        GLFW_Window::GLFW_Window(const std::string& name, uint32_t width, uint32_t height)
        {
            glfwInit();
            m_Window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
        }

        void GLFW_Window::show(){
            while (!glfwWindowShouldClose(m_Window))
            {
                glfwPollEvents();
            }
        }

        void GLFW_Window::attach(std::shared_ptr<Surface> Surface)
        {
            
        }
        GLFW_Window::~GLFW_Window(){
        }
    }
}