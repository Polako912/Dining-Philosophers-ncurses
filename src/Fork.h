#include <iostream>

class Fork
{
    enum ForkState
    {
        FREE,
        TAKEN
    };

    public:
    
    int Id;
    std::mutex forkMutex;
    
    Fork();
    ~Fork();
}