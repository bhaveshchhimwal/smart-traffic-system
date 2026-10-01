#include "core/TrafficController.h"
#include <thread>
#include <chrono>

int main() {
    srand(time(0));

    TrafficController controller;

    // 🧵 Thread 1: Traffic generator
    std::thread t1(&TrafficController::generateTraffic, &controller);

    // 🧵 Thread 2: Controller loop
    std::thread t2([&]() {
        for (int i = 0; i < 50; i++) {
            controller.update();
            controller.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        controller.running = false;
    });

    t1.join();
    t2.join();

    return 0;
}