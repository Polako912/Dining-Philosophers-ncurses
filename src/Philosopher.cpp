#include "../include/Philosopher.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <string>

Philosopher::Philosopher()
{

}

Philosopher::Philosopher(int id)
{
    this->Id = id;
    //this->statePhilo = 2;
    statusPhilo.resize(id);
    //forkMutex.resize(id);
    //forkMutex[id];
    //this->run = true;
}

Philosopher::~Philosopher()
{
    
}

void Philosopher::Eat(int id)
{
    //statusPhilo[this->Id].state = EATING;
    std::cout << "Philosopher " << id << " is eating" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::Hungry(int id)
{
    //statusPhilo[this->Id].state = HUNGRY;
    std::cout << "Philosopher " << id << " is hungry" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::Think(int id)
{   
    //statusPhilo[this->Id].state = THINKING;
    std::cout << "Philosopher " << id << " is thinking" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::PickLeftFork(int id)
{
   std::cout << "Philosopher " << id << " has picked up left fork" << std::endl; 
}

void Philosopher::PutLeftFork(int id)
{
    std::cout<<"Philosopher " << id << " has put down left fork" << std::endl;
}

void Philosopher::PickRightFork(int id)
{
    std::cout<<"Philosopher " << id << " has picked up right fork" <<std::endl;
}

void Philosopher::PutRightFork(int id)
{
    std::cout << "Philosopher " << id << " has put down right fork" << std::endl;
}

int Philosopher::getId()
{
    return this->Id;
}

void Philosopher::setId(int number)
{
    this->Id = number;
}

// int Philosopher::getState()
// {
//     return statePhilo;
// }

// void Philosopher::setState(int number)
// {
//     Philosopher::statePhilo = number;
// }