#include "TrafficController.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

TrafficController::TrafficController() {
    lanes.push_back(Lane("North"));
    lanes.push_back(Lane("South"));
    lanes.push_back(Lane("East"));
    lanes.push_back(Lane("West"));

    running = true;
}

// 🚦 Select best lane
int TrafficController::selectLane() {

    // 🚑 Emergency priority
    for (int i = 0; i < lanes.size(); i++) {
        if (lanes[i].hasAmbulance) {
            cout << "🚑 PRIORITY: " << lanes[i].name << endl;
            lanes[i].hasAmbulance = false;
            return i;
        }
    }

    int idx = 0;
    int bestScore = -1;

    for (int i = 0; i < lanes.size(); i++) {
        int score = lanes[i].cars * 2 + lanes[i].waitTime * 3;

        if (score > bestScore) {
            bestScore = score;
            idx = i;
        }
    }

    return idx;
}

// 🚗 Controller logic
void TrafficController::update() {
    lock_guard<mutex> lock(mtx);

    int idx = selectLane();

    cout << "\n🚦 GREEN: " << lanes[idx].name << endl;

    lanes[idx].passCars(5);

    for (int i = 0; i < lanes.size(); i++) {
        if (i == idx)
            lanes[i].waitTime = 0;
        else
            lanes[i].waitTime++;
    }
}

// 🚗 Traffic generator thread
void TrafficController::generateTraffic() {
    while (running) {
        {
            lock_guard<mutex> lock(mtx);

            // add cars
            for (auto &lane : lanes) {
                lane.addCars(rand() % 5);
            }

            // ambulance chance
            if (rand() % 20 == 0) {
                int idx = rand() % lanes.size();
                lanes[idx].hasAmbulance = true;
                cout << "🚑 Ambulance at " << lanes[idx].name << endl;
            }
        }

        this_thread::sleep_for(chrono::seconds(1));
    }
}

// 📊 Display
void TrafficController::display() {
    lock_guard<mutex> lock(mtx);

    cout << "\n--- Traffic State ---\n";
    for (auto &lane : lanes) {
        cout << lane.name
             << ": " << lane.cars
             << " | wait: " << lane.waitTime;

        if (lane.hasAmbulance)
            cout << " 🚑";

        cout << endl;
    }
}