#include <chrono>
#include <iostream>
#include <iomanip>
#include "Timer.h"

Timer::Timer(std::string name)
{
    point_name = name;
    st_point = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
    Stop();
}

void Timer::Stop()
{
    et_point = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(st_point).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(et_point).time_since_epoch().count();

    auto duration = end - start;
    double ms = duration * 0.001;

    int size = 30 - point_name.size();

    std::cout << point_name << std::setw(size) << ms << " ms" << std::endl;
}