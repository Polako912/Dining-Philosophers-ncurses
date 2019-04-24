#include "../include/Philosopher.h"
#include <mutex>
#include <thread>
#include <vector>

Philosopher::Philosopher()
{

}

Philosopher::Philosopher(int id)
{
    this->Id = id;
    this->statePhilo = 2;
    this->run = true;
}

Philosopher::~Philosopher()
{
    
}

void Philosopher::Eat()
{
    // std::lock(Left->forkMutex, Right->forkMutex);

    // std::lock_guard<std::mutex> left_lock(Left->forkMutex, std::adopt_lock);
    // std::lock_guard<std::mutex> right_lock(Right->forkMutex, std::adopt_lock);
    
    Philosopher::setState(1);
    std::cout << "Philosopher " << this->Id << " is eating" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::Hungry()
{
    Philosopher::setState(0);
    std::cout << "Philosopher " << this->Id << " is hungry" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::Think()
{   
    Philosopher::setState(2);
    std::cout << "Philosopher " << this->Id << " is thinking" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::PickLeftFork()
{
   std::cout << "Philosopher " << this->Id << " has picked up " << Right->Id << " fork" << std::endl; 
}

void Philosopher::PutLeftFork()
{
    std::cout<<"Philosopher " << this->Id << " has put down " << Left->Id << " fork" << std::endl;
}

void Philosopher::PickRightFork()
{
    std::cout<<"Philosopher " << this->Id << " has picked up " << Right->Id << " fork" <<std::endl;
}

void Philosopher::PutRightFork()
{
    std::cout << "Philosopher " << this->Id << " has put down " << Right->Id << " fork" << std::endl;
}

bool Philosopher::AbleToEat(int left, int right)
{
    std::vector<Philosopher> temp;
    temp[left].state = EATING;
}

void Philosopher::Dine(int number)
{
    Philosopher philo (number);
    Fork fork (number);

    philo.setState(0);

    while(this->run)
    {
        fork.forkMutex.try_lock();
        Philosopher::setState(3);
        PickLeftFork();
    }
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