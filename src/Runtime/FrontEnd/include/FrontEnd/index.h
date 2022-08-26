#pragma once
#include <cpp-utilities/singleton.hpp>
#include <cpp-utilities/dll.h>
#include <GLFW/glfw3.h>
namespace Tao
{
    class CPP_UTIL_API Window : public PublicSingleton<Window>
    {
    public:
        Window() = default;
        void Setup();

        void Run();

        void Shutdown();
    private:
        GLFWwindow* m_Window;
    };
}