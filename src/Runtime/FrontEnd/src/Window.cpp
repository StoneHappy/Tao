#include "FrontEnd/index.h"
#include <iostream>
namespace Tao
{
    void Window::Setup(){
        std::cout << "Setup..." << std::endl;
    }
    void Window::Run(){
        std::cout << "Run..." << std::endl;
    }
    void Window::Shutdown(){
        std::cout << "Shutdown..." << std::endl;
    }
}