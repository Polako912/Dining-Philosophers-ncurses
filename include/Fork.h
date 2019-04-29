#pragma once
#include <iostream>
#include <mutex>

class Fork
{
    public:

    int Id;
    int stateFork;
    
    Fork();
    Fork(int number);
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