#pragma once
#include <iostream>
#include <mutex>
#include "Philosopher.h"

class Window
{
    public:

    std::mutex mt;
    Philosopher *philo;

    Window();
    ~Window();

    void Visualise(int number);
    void PutDownLeftFork(int left);
    void PutDownRightFork(int right);
    void PickUpLeftFork(int left);
    void PickUpRightFork(int right);
    void RefreshPhiosopher(int id, std::string status);
    void RefreshFork(int id, std::string status);

};