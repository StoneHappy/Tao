#pragma once
#include "FrontEnd/index.h"
#include <cpp-utilities/singleton.hpp>
#include <cpp-utilities/dll.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
namespace Tao
{
    class CPP_UTIL_API Surface
    {
    public:
        Surface() = default;
        virtual ~Surface() = default;
    };

    class CPP_UTIL_API Window
    {
    public:
        Window() = default;
        virtual void Show() = 0;

        virtual void Attach(std::shared_ptr<Surface> Surface) = 0;
    };

    class CPP_UTIL_API GLFW_Window : public PublicSingleton<GLFW_Window>, Window
    {
    public:
        GLFW_Window();

        virtual void Show() override;

        virtual void Attach(std::shared_ptr<Surface> Surface) override;

        virtual ~GLFW_Window();
    private:
        std::vector<std::shared_ptr<Surface>> m_Surfaces;
        GLFWwindow* m_Window;
    };
}