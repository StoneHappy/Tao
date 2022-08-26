#include <chrono>
#include <iostream>
#include <FrontEnd/index.h>
#include <cpp-utilities/thread_pool.h>
#include <thread>
int main(int argc, char *argv[])
{
    thread_pool pool;
    pool.add_worker([](){
        PublicSingleton<Tao::Window>::getInstance().Setup();
        PublicSingleton<Tao::Window>::getInstance().Run();
        PublicSingleton<Tao::Window>::getInstance().Shutdown();
    });
    pool.add_worker([](){
        for (int i=0; i < 5; i++) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::cout << i << std::endl;
        }
    });
}
