#include "Tao/Core/index.h"
#include <cmdline.h>
#include <string>
namespace Tao
{
    namespace Core {
        Application::Application(int argc, char** argv)
        {
            cmdline::parser a;
            a.add<std::string>("scriptpath", 's', R"(
                Tao can run with lua script.
                Lua script is natively support to c/c++, runs as efficiently as c/c++.
            )", false);

            a.parse_check(argc, argv);
        }
    }
}