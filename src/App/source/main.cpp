#include <iostream>
#include <FrontEnd/index.h>
int main(int argc, char *argv[])
{
    PublicSingleton<Tao::Window>::getInstance().Setup();
    PublicSingleton<Tao::Window>::getInstance().Run();
    PublicSingleton<Tao::Window>::getInstance().Shutdown();
}
