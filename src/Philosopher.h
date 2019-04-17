#include <iostream>
#include "Fork.h"

class Philosopher
{
    int Id;
    Fork Left;
    Fork Right;
    
    public:
    Philosopher();
    ~Philosopher();

    enum PhilospherState
    {
        HUNGRY,
        EATING,
        THINKING
    };
}