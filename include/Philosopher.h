#pragma once
#include <iostream>
#include <mutex>
#include "Fork.h"

class Philosopher
{
    public:

    int Id;
    int statePhilo;
    Fork *Left;
    Fork *Right;
    bool run;
    std::mutex philoMutex;
    
    Philosopher();
    Philosopher(int id);
    ~Philosopher();

    void Eat();
    void Hungry();
    void Think();
    void PickLeftFork(int number);
    void PutLeftFork(int number);
    void PickRightFork(int number);
    void PutRightFork(int number);
    void Dine(int number);

    int getId();
    void setId(int number);
    int getState();
    void setState(int number);

    enum PhilospherState
    {
        HUNGRY,
        EATING,
        THINKING,
        HAS_LEFT_FORK,
        HAS_RIGHT_FORK,
        HAS_BOTH_FORKS
    };
};