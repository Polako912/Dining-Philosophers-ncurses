#include <iostream>

class Fork
{
    enum ForkState
    {
        FREE,
        TAKEN
    };

    int Id;
    
    Fork();
    ~Fork();
}