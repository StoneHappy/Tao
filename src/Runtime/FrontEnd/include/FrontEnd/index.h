#pragma once
#include <cpp-utilities/singleton.h>
#include <cpp-utilities/dll.h>
namespace Tao
{
    class CPP_UTIL_API Window
    {
    public:
        Window() = default;
        void Setup();

        void Run();

        void Shutdown();
    private:
    };
}