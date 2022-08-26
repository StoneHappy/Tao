#include "FrontEnd/index.h"
#include "GLFW/glfw3.h"
#include <iostream>
namespace Tao
{
    void Window::Setup(){
        glfwInit();
        m_Window = glfwCreateWindow(200, 300, "Tao", nullptr, nullptr);
        std::cout << "Setup..." << std::endl;
    }
    void Window::Run(){
        while (!glfwWindowShouldClose(m_Window))
        {
            glfwPollEvents();
        }
        std::cout << "Run..." << std::endl;
    }
    void Window::Shutdown(){
        std::cout << "Shutdown..." << std::endl;
    }
}