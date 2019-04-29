#pragma once
#include <iostream>
#include <mutex>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <list>
#include <functional>
#include "Fork.h"

class Philosopher
{
    public:
    
    enum PhilosopherState
    {
        HUNGRY,
        EATING,
        THINKING,
        HAS_LEFT_FORK,
        HAS_RIGHT_FORK,
        HAS_BOTH_FORKS
    };

    int Id;
    Philosopher();
    Philosopher(int id);
    ~Philosopher();

    void Eat(int id);
    void Hungry(int id);
    void Think(int id);
    void PickLeftFork(int id);
    void PutLeftFork(int id);
    void PickRightFork(int id);
    void PutRightFork(int id);

    int getId();
    void setId(int number);
    int getState();
    void setState(int number);
};