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