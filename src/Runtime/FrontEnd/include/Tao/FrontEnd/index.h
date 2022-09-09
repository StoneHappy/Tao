#pragma once
#include "Tao/FrontEnd/index.h"
#include <cpp-utilities/singleton.hpp>
#include <cpp-utilities/dll.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

namespace Tao::FrontEnd::Settings {
    struct CPP_UTIL_API DeviceSettings
    {
        /**
		* Specify the client API major version that the created context must be compatible with. The exact
		* behavior of these hints depend on the requested client API
		*/
		uint8_t contextMajorVersion = 3;

		/**
		* Specify the client API minor version that the created context must be compatible with. The exact
		* behavior of these hints depend on the requested client API
		*/
		uint8_t contextMinorVersion = 2;
    };

    struct CPP_UTIL_API WindowSettings
    {
		/**
		* Title of the window (Displayed in the title bar)
		*/
		std::string title;

		/**
		* Width in pixels of the window
		*/
		uint16_t width;

		/**
		* Height in pixels of the window
		*/
		uint16_t height;
    };
}

namespace Tao::FrontEnd::Context {
    class CPP_UTIL_API Device
    {
    public:
        Device(const Tao::FrontEnd::Settings::DeviceSettings& p_deviceSettings);
        ~Device();
        void PollEvents() const;
    private:
        bool m_isAlive = false;
    };
}

namespace Tao
{
    namespace FrontEnd {
        class CPP_UTIL_API Window
        {
        public:
            Window();
            Window(const Tao::FrontEnd::Context::Device& p_device, const Tao::FrontEnd::Settings::WindowSettings& p_windowSettings);

            void SwapBuffers();

            bool ShouldClose();

            void SetShouldClose(bool p_value);

            virtual ~Window();
        private:
            void CreateGlfwWindow(const Tao::FrontEnd::Settings::WindowSettings& p_windowSettings);


            const Tao::FrontEnd::Context::Device& m_device;
            GLFWwindow* m_glfwWindow;
            static std::unordered_map<GLFWwindow*, Tao::FrontEnd::Window*> m_s_WINDOWS_MAP;
        };
    }
}

namespace Tao {
    namespace FrontEnd {
        class CPP_UTIL_API ProjectHub
        {
        public:
            ProjectHub();
            ~ProjectHub()=default;

            void Run();
        private:
            std::unique_ptr<Tao::FrontEnd::Context::Device> m_device;
            std::unique_ptr<Tao::FrontEnd::Window> m_window;
        };
    }
}


