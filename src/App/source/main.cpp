#include <chrono>
#include <iostream>
#include <Tao/Core/index.h>
#include <Tao/FrontEnd/index.h>
#include <cpp-utilities/thread_pool.h>
#include <thread>
int main(int argc, char *argv[])
{
#if 0
    thread_pool pool;
    pool.add_worker([](){
        PublicSingleton<Tao::GLFW_Window>::getInstance().Show();
    });
    pool.add_worker([](){
        for (int i=0; i < 5; i++) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::cout << i << std::endl;
        }
    });
#endif
    Tao::Core::Application app(argc, argv);
}
