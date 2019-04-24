#include "../include/Philosopher.h"
#include <mutex>
#include <thread>

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
    std::lock(Left->forkMutex, Right->forkMutex);

    std::lock_guard<std::mutex> left_lock(Left->forkMutex, std::adopt_lock);
    std::lock_guard<std::mutex> right_lock(Right->forkMutex, std::adopt_lock);
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::Hungry()
{
    std::cout << "Philosopher " << this->Id << " is hungry" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::Think()
{
    std::cout << "Philosopher " << this->Id << " is thinking" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Philosopher::PickLeftFork(int number)
{
   std::cout << "Philosopher " << this->Id << " has picked up " << Right->Id << " fork" << std::endl; 
}

void Philosopher::PutLeftFork(int number)
{
    std::cout<<"Philosopher " << this->Id << " has put down " << Left->Id << " fork" << std::endl;
}

void Philosopher::PickRightFork(int number)
{
    std::cout<<"Philosopher " << this->Id << " has picked up " << Right->Id << " fork" <<std::endl;
}

void Philosopher::PutRightFork(int number)
{
    std::cout << "Philosopher " << this->Id << " has put down " << Right->Id << " fork" << std::endl;
}

void Philosopher::Dine(int number)
{
    Philosopher philo (number);

    philo.setState(rand()%3);

    while(run)
    {
        if(philo.getState() == 0)
        {

        }

        if(philo.getState() == 1)
        {

        }

        if(philo.getState() == 2)
        {

        }
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