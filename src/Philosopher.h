#include <iostream>
#include "Fork.h"

class Philosopher
{
    int Id;
    Fork Left;
    Fork Right;
    std::mutex philoMutex;
    
    public:
    
    Philosopher();
    Philosopher(int id);
    ~Philosopher();

    void Eat();
    void Hungry();
    void Think();
    void PickLeftFork(int number);
    void PickRightFork(int number);
    void Dine();

    enum PhilospherState
    {
        HUNGRY,
        EATING,
        THINKING
    };
}