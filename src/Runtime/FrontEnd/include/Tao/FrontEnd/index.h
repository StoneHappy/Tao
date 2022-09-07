#pragma once
#include <cpp-utilities/singleton.hpp>
#include <cpp-utilities/dll.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include <string>
namespace Tao
{
    namespace FrontEnd {
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
            virtual void show() = 0;

            virtual void attach(std::shared_ptr<Surface> Surface) = 0;
        };

        class CPP_UTIL_API GLFW_Window : public Window
        {
        public:
            GLFW_Window();
            GLFW_Window(const std::string& name, uint32_t width, uint32_t height);

            virtual void show() override;

            virtual void attach(std::shared_ptr<Surface> Surface) override;

            virtual ~GLFW_Window();
        private:
            std::vector<std::shared_ptr<Surface>> m_Surfaces;
            GLFWwindow* m_Window;
        };
    }
}