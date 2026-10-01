#pragma once
#include <vector>
#include <mutex>
#include <atomic>
#include "../models/Lane.h"

class TrafficController {
private:
    std::vector<Lane> lanes;
    std::mutex mtx;

public:
    std::atomic<bool> running;

    TrafficController();

    void update();
    void display();
    void generateTraffic();
    int selectLane();
};