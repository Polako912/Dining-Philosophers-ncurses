#include "../include/Fork.h"
#include <mutex>

Fork::Fork()
{

}

Fork::~Fork()
{
    
}

int Fork::getId()
{
    return this->Id;
}

void Fork::setId(int number)
{
    this->Id = number;
}

int Fork::getState()
{
    return stateFork;
}

void Fork::setState(int number)
{
    Fork::stateFork = number;
}