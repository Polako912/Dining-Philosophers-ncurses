#include <iostream>
#include "Fork.h"

class Philosopher
{
    int Id;
    Fork Left;
    Fork Right;
    
    public:
    Philosopher();
    Philosopher(int id);
    ~Philosopher();

    void Eat();
    void Hungry();
    void Think();

    enum PhilospherState
    {
        HUNGRY,
        EATING,
        THINKING
    };
}