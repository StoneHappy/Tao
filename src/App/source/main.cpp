#include <iostream>
#include <FrontEnd/index.h>
int main(int argc, char *argv[])
{
    Tao::Window window;
    window.Setup();
    window.Run();
    window.Shutdown();
}
