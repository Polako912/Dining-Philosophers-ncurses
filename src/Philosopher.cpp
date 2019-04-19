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

}

void Philosopher::Think()
{

}

void Philosopher::PickLeftFork(int number)
{
    std::cout<<"Philosopher " << this->Id << " has picked up" << Left.Id << " fork" << std::endl;
    
}

void Philosopher::PickRightFork(int number)
{
    std::cout<<"Philosopher " << this->Id << " has picked up" << Right.Id << " fork" <<std::endl;
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