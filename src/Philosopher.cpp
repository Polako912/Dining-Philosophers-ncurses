#pragma once
#include "Philosopher.h"
#include <mutex>
#include <thread>

Philosopher::Philosopher()
{

}

Philosopher::Philosopher(int id)
{
    this->Id = id;
}

Philosopher::~Philosopher()
{
    
}

void Philosopher::Eat()
{
    std::lock(Left.forkMutex, Right.forkMutex);

    std::lock_guard<std::mutex> left_lock(Left.forkMutex, std::adopt_lock);
    std::lock_guard<std::mutex> right_lock(Right.forkMutex, std::adopt_lock);
}

void Philosopher::Hungry()
{
    std::cout << "Philosopher " << this->Id << " is hungry" << std::endl;
}

void Philosopher::Think()
{
    std::cout << "Philosopher " << this->Id << " is thinking" << std::endl;
}

void Philosopher::PickLeftFork(int number)
{
    Fork fork;
    std::unique_lock<std::mutex> forkLock(Left.forkMutex);
    fork.setState(1);
    if(fork.getState == 1)
    { 
        std::cout<<"Philosopher " << this->Id << " has picked up" << Left.Id << " fork" << std::endl;
    }
    forkLock.unlock();
    fork.setState(0);
    if(fork.getState == 0)
    {
        PutLeftFork(number);
    }
}

void Philosopher::PutLeftFork(int number)
{
    std::cout<<"Philosopher " << this->Id << " has put down" << Left.Id << " fork" << std::endl;
}

void Philosopher::PickRightFork(int number)
{
    std::cout<<"Philosopher " << this->Id << " has picked up" << Right.Id << " fork" <<std::endl;
}

void Philosopher::PutRightFork(int number)
{

}

void Philosopher::Dine()
{
    
}

int Philosopher::getId()
{
    return this->Id;
}

void Philosopher::setId(int number)
{
    this->Id = number;
}

int Philosopher::getState()
{
    return statePhilo;
}

void Philosopher::setState(int number)
{
    Philosopher::statePhilo = number;
}