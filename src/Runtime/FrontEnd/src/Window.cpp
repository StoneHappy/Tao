#include "Tao/FrontEnd/index.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <memory>
namespace Tao
{
    namespace FrontEnd {
        GLFW_Window::GLFW_Window()
        {
            glfwInit();
            m_Window = glfwCreateWindow(200, 300, "Tao", nullptr, nullptr);
            std::cout << "Setup..." << std::endl;
        }

        void GLFW_Window::Show(){
            std::cout << "Run..." << std::endl;
            while (!glfwWindowShouldClose(m_Window))
            {
                glfwPollEvents();
            }
        }

        void GLFW_Window::Attach(std::shared_ptr<Surface> Surface)
        {
            
        }
        GLFW_Window::~GLFW_Window(){
            std::cout << "Shutdown..." << std::endl;
        }
    }
}