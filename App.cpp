#include <iostream>
#include <atomic>
#include <future>
#include "system/connection.h"

int driver() {
    System::Connection c;
    int counter = 0;
    std::atomic<bool> quit = true;

    std::cout << "Pre connection call." << std::endl;

    std::shared_future<void> f = std::async(std::launch::async, &System::Connection::waitForConnection, &c, &quit);
    std::cout << "Waiting . . . " << std::endl;
    std::future_status status;
    do {
        status = f.wait_for(std::chrono::seconds(1));
        if (status == std::future_status::deferred) {
            std::cout << "deferred" << std::endl;
        } else if (status == std::future_status::timeout) {
            std::cout << "timeout" << std::endl;
            counter++;
            if (counter > 10) {
                quit = false;
            }
        } else if (status == std::future_status::ready) {
            std::cout << "ready" << std::endl;
        }
    } while (status != std::future_status::ready);

    std::cout << "End of driver." << std::endl;
}

int main() {
    driver();
}
