NAME: SIMI ADENIYI
REMARK: This file contains how to compile the program


# Airport Simulation

## Overview
An event-driven simulation of airport operations implemented in C++, modeling aircraft landing, takeoff, and runway queue management over simulated time.

## Features
- Event-driven simulation architecture
- Object-oriented modeling of airport entities
- Configurable scheduling strategies
- Performance comparison between FIFO and optimized scheduling

## Tech Stack
- C++
- Object-Oriented Programming

## Architecture / Design
The simulation models airport operations as discrete events processed over simulated time. Custom scheduling logic was implemented and evaluated against FIFO scheduling to analyze performance impacts on queue wait times.


## Results
- Reduced average simulated queue wait times by **25%** compared to FIFO scheduling


To compile:

1) clang++ *.cpp -std=c++11 -o run

2) ./run filename.txt numRunways
	
	e.g. ./run test.txt 1
