#include <iostream>
#include <chrono>
#include <thread>
#include "connection.h"

namespace System {
    void Connection::waitForConnection(std::atomic<bool>* interrupt) {
        int count = 0;
        while (*interrupt != false) {
            count++;
            std::cout << count << std::endl;
            std::cout << "Interrupt = " << *interrupt << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}