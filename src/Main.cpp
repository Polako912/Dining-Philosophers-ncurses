#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include "ncurses.h"
//#include <concurrent_vector.h>
#include "../include/Philosopher.h"
#include "../include/Window.h"

bool AbleToEat(int left, int right, int id);
void Dine(int number, int count);

bool run = true;

const int number = 5000;

Window win;

std::vector<int> philosophers;
std::vector<int> forks;
std::mutex forkMutex[number];
//std::list<std::mutex> forkMutex;
//std::vector<std::mutex> forkMutex;
//concurrent_vector<std::mutex> forkMutex;

int main()
{
    initscr();
    srand(time(NULL));

    Philosopher philo;
    //Window win;

    int number;

    cbreak();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    std::cout << "Podaj liczbe filozofow" << std::endl;
    std::cin >> number;
    
    win.Visualise(number);
    //forkMutex.resize(number);
    //std::vector<std::mutex> forkMutex(number);

    std::thread threads[number];

    for (int i = 0; i < number; i++)
    {
        philosophers.push_back(i+1);
        forks.push_back(i+1);
        threads[i] = std::thread(Dine, i, number);
    }

    char tmp = 'm';

    while(tmp != 'n')
    {
        tmp = static_cast<char>(std::cin.get());
        if (tmp == 'n') 
        {
            run = false;
        }
    }

    for(int k = 0; k < number; k++)
    {
        threads[k].join();
        std::cout<<"Philosopher "<< k+1 <<" has finished"<<std::endl ;
    }

    endwin();
    exit(0);
}

bool AbleToEat(int left, int right, int id)
{
    Philosopher philo;
    //Window win;

    while(true) if(forkMutex[left].try_lock())
    {
        //philo.PickLeftFork(id);
        win.PickUpLeftFork(left);
        //win.RefreshFork(left, "zajety");
        //win.RefreshPhiosopher(id, "ma lewy widelec");
        //statusPhilo[this->Id].state = HAS_LEFT_FORK;

        if(forkMutex[right].try_lock())
        {
            //philo.PickRightFork(id);
            win.PickUpRightFork(right);
            //win.RefreshFork(right, "zajety");
            //win.RefreshPhiosopher(id, "ma oba widelce");
            //win.RefreshPhiosopher(id, "je");
            //statusPhilo[this->Id].state = HAS_BOTH_FORKS;
            //philo.Eat(id);
            return true;
        }
        else
        {
            forkMutex[left].unlock();
            win.PutDownLeftFork(left);
            //win.RefreshPhiosopher(left, "odlozyl lewy widelec");
            //philo.PutLeftFork(id);
        }
    }
}

void Dine(int number, int count)
{
    Philosopher philo (number);
    Fork fork (number);
    //Window win;

    int left = std::min(number, (number + 1) % (count));
    int right = std::max(number, (number + 1) % (count));

    //philo.setState(0);

    while(run)
    {
        if(AbleToEat(left, right, number))
        {
            //philo.PutLeftFork(number);
            win.PutDownLeftFork(number);
            //win.RefreshFork(left, "wolny");
            forkMutex[left].unlock();
            //philo.PutRightFork(number);
            win.PickUpRightFork(number);
            //win.RefreshFork(right, "wolny");
            forkMutex[right].unlock();
            //win.RefreshPhiosopher(number, "mysli");
            //philo.Think(number);
        }
    }
}