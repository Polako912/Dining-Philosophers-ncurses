#include <iostream>
#include <vector>
#include <thread>
#include "../include/Philosopher.h"

int main()
{
    srand(time(NULL));

    Philosopher *philo = new Philosopher;

    int number = 0;

    std::vector<int> philosophers;
    std::vector<int> forks;

    std::cout << "Podaj liczbe filozofow" << std::endl;
    std::cin >> number;

    std::thread threads[number];

    for (int i = 0; i < number; i++)
    {
        philosophers.push_back(i+1);
        forks.push_back(i+1);
        //threads[i] = std::thread(&Philosopher::Dine, &philo, i);
    }

    char tmp;

    while(tmp != 'n')
    {
        tmp = static_cast<char>(std::cin.get());
        if (tmp == 'n') 
        {
            philo->run = false;
        }
    }

    for(int k = 0; k < number; k++)
    {
        //threads[k].join();
        std::cout<<"Philosopher "<< k+1 <<" has finished"<<std::endl ;
    }

    return 0;
}