#pragma once
#include <iostream>
#include <mutex>
#include "Fork.h"

class Philosopher
{
    public:enum PhilospherState
    {
        HUNGRY,
        EATING,
        THINKING,
        HAS_LEFT_FORK,
        HAS_RIGHT_FORK,
        HAS_BOTH_FORKS
    };

    int Id;
    int statePhilo;
    PhilospherState state = PhilospherState::THINKING;
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
    void PickLeftFork();
    void PutLeftFork();
    void PickRightFork();
    void PutRightFork();
    void Dine(int number);

    int getId();
    void setId(int number);
    int getState();
    void setState(int number);
};