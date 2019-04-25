#include <iostream>
#include <vector>
#include <thread>
#include "../include/Philosopher.h"

bool AbleToEat(int left, int right, int id);
void Dine(int number);

const int number = 5;

std::vector<int> philosophers;
std::vector<int> forks;
std::mutex forkMutex[number];

int main()
{
    srand(time(NULL));

    Philosopher philo;

    //int number = 5;

    //std::cout << "Podaj liczbe filozofow" << std::endl;
    //std::cin >> number;

    std::thread threads[number];

    for (int i = 0; i < number; i++)
    {
        philosophers.push_back(i+1);
        forks.push_back(i+1);
        threads[i] = std::thread(Dine, i);
    }

    char tmp;

    while(tmp != 'n')
    {
        tmp = static_cast<char>(std::cin.get());
        if (tmp == 'n') 
        {
            philo.run = false;
        }
    }

    for(int k = 0; k < number; k++)
    {
        threads[k].join();
        std::cout<<"Philosopher "<< k+1 <<" has finished"<<std::endl ;
    }

    return 0;
}

bool AbleToEat(int left, int right, int id)
{
    Philosopher philo;

    while(true) if(forkMutex[left].try_lock())
    {
        philo.PickLeftFork(id);
        //statusPhilo[this->Id].state = HAS_LEFT_FORK;

        if(forkMutex[right].try_lock())
        {
            philo.PickRightFork(id);
            //statusPhilo[this->Id].state = HAS_BOTH_FORKS;
            philo.Eat(id);
            return true;
        }
        else
        {
            forkMutex[left].unlock();
            philo.PutLeftFork(id);
        }
    }
}

void Dine(int number)
{
    Philosopher philo (number);
    Fork fork (number);

    int left = std::min(number, (number + 1) % (5));
    int right = std::max(number, (number + 1) % (5));

    //philo.setState(0);

    while(true)
    {
        if(AbleToEat(left, right, number))
        {
            philo.PutLeftFork(number);
            forkMutex[left].unlock();
            philo.PutRightFork(number);
            forkMutex[right].unlock();
            philo.Think(number);
        }
    }
}