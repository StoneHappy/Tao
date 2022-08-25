#include "Core/test.h"
#include <chrono>
#include <iostream>
#include <cpp-utilities/thread_pool.h>
#include <thread>
bool test()
{
    thread_pool pool(10);
    for (int thid=0; thid < 5; thid++) {
        pool.add_worker([=](){
            std::cout << "thid = " << thid << std::endl;
            for (int i = 0; i < 5; i++) {
                std::this_thread::sleep_for(std::chrono::seconds(5));
                std::cout << i << std::endl;
            }
        });    
    }
    return true;
}

void Foo::test()
{
    
}