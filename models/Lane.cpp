#include "Lane.h"
#include <algorithm>
#include <cstdlib>

Lane::Lane(std::string n) {
    name = n;
    cars = rand() % 20;
    waitTime = 0;
    hasAmbulance = false;
}

void Lane::addCars(int count) {
    cars += count;
}

void Lane::passCars(int count) {
    cars = std::max(0, cars - count);
}