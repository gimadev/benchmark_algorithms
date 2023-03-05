#include<chrono>
#include<string>
#pragma once
#ifndef TIMER_H_
#define TIMER_H_


class Timer
{
public:
    Timer(std::string);

    ~Timer();

    void Stop();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> st_point;

    std::chrono::time_point<std::chrono::high_resolution_clock> et_point;

    std::string point_name;
};

#endif