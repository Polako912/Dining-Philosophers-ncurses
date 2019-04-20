#pragma once
#include <iostream>
#include <mutex>

class Fork
{
    public:

    int Id;
    int stateFork;
    std::mutex forkMutex;
    
    Fork();
    ~Fork();

    int getId();
    void setId(int number);
    int getState();
    void setState(int number);

    enum ForkState
    {
        FREE,
        TAKEN
    };
};