# Smart Traffic Control System (C++)

## Overview

This project implements a multithreaded smart traffic control system in
C++ that dynamically manages traffic signals based on vehicle density
and waiting time. It simulates real-time traffic conditions and
prioritizes emergency vehicles using a scheduling-based approach.

The system is inspired by operating system scheduling and modern
Intelligent Transportation Systems (ITS).

------------------------------------------------------------------------

## Features

-   Adaptive signal control based on traffic density
-   Starvation prevention using wait-time-based prioritization
-   Emergency vehicle (ambulance) priority handling
-   Real-time traffic simulation using multithreading
-   Thread-safe design using mutex and atomic variables
-   Modular object-oriented architecture

------------------------------------------------------------------------

## System Design

### Lane

Represents a road lane with: - Number of vehicles - Waiting time -
Emergency vehicle flag

### Traffic Controller

Acts as the decision engine: - Selects the next lane to receive the
green signal - Updates traffic conditions - Ensures fairness and
efficiency

### Threads

-   Traffic Generator Thread
    Continuously simulates incoming vehicles and emergency events

-   Controller Thread
    Manages signal switching and traffic flow

------------------------------------------------------------------------

## Scheduling Logic

    score = (cars * 2) + (waitTime * 3)

-   Higher number of vehicles increases priority
-   Waiting time ensures fairness and prevents starvation
-   Emergency vehicles override normal scheduling

------------------------------------------------------------------------

## Project Structure

    smart-traffic-system/
    │── main.cpp
    │
    ├── core/
    │     ├── TrafficController.h
    │     ├── TrafficController.cpp
    │
    ├── models/
    │     ├── Lane.h
    │     ├── Lane.cpp

------------------------------------------------------------------------

## Compilation and Execution

### Compile

    g++ main.cpp core/TrafficController.cpp models/Lane.cpp -o traffic -pthread

### Run

    ./traffic

------------------------------------------------------------------------

## Sample Output

    GREEN: North

    --- Traffic State ---
    North: 10 | wait: 0
    South: 15 | wait: 2
    East: 8  | wait: 3
    West: 20 | wait: 1

------------------------------------------------------------------------

## Concepts Used

-   Multithreading (std::thread)
-   Synchronization (std::mutex)
-   Atomic variables
-   Object-Oriented Programming
-   Scheduling algorithms
-   Simulation design

------------------------------------------------------------------------

## Real-World Relevance

This project models key ideas used in modern traffic systems:

-   Adaptive traffic signal control
-   Sensor-driven decision making (simulated)
-   Emergency vehicle prioritization
-   Load balancing across intersections

------------------------------------------------------------------------

## Future Improvements

-   GUI visualization using SFML
-   Vehicle detection using OpenCV
-   Multi-intersection coordination
-   Configurable system parameters
-   Data logging and analytics
-   Machine learning-based traffic prediction

