#pragma once
#include <iostream>
#include <mutex>
#include <vector>
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

    struct PhiloState
    {
        PhilosopherState state = PhilosopherState::THINKING;
    };

    int Id;
    //int statePhilo;
    //Fork *Left;
    //Fork *Right;
    bool run;
    std::vector<PhiloState> statusPhilo;
    //std::mutex forkMutex[5];
    //std::vector<std::unique_ptr<std::mutex>> forkMutex;
    
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
    //bool AbleToEat(int left, int right, int id);
    //void Dine(int number);

    int getId();
    void setId(int number);
    int getState();
    void setState(int number);
};