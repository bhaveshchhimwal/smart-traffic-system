#pragma once
#include <string>

class Lane {
public:
    std::string name;
    int cars;
    int waitTime;
    bool hasAmbulance;

    Lane(std::string n);

    void addCars(int count);
    void passCars(int count);
};