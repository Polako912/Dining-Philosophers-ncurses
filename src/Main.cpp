#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include "ncurses.h"
#include "../include/Philosopher.h"
#include "../include/Window.h"

bool AbleToEat(int left, int right, int id);
void Dine(int number, int count);

bool run = true;

Window win;
Fork fork;

std::vector<int> philosophers;
std::vector<int> forks;

std::mutex forkMutex[5000];

int main()
{
    initscr();
    srand(time(NULL));

    Philosopher philo;

    int number;

    cbreak();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    std::cout << "Podaj liczbe filozofow" << std::endl;
    std::cin >> number;
    
    win.Visualise(number);

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
    }

    endwin();
    exit(0);
}

bool AbleToEat(int left, int right, int id)
{
    while(run) if(forkMutex[left].try_lock())
    {
        win.PickUpLeftFork(left, id);

        if(forkMutex[right].try_lock())
        {
            win.PickUpRightFork(right, id);
            win.ReadyToEat(id);
            return true;
        }
        else
        {
            win.PutDownLeftFork(left, id);
            forkMutex[left].unlock();
            win.Hungry(id);
        }
    }
}

void Dine(int number, int count)
{
    Philosopher philo (number);
    Fork fork (number);

    int left = std::min(number, (number + 1) % (count));
    int right = std::max(number, (number + 1) % (count));

    while(run)
    {
        if(AbleToEat(left, right, number))
        {
            win.Eat(number);

            win.PutDownLeftFork(number, count);
            forkMutex[left].unlock();

            win.PickUpRightFork(number, count);
            forkMutex[right].unlock();
            
            win.Think(number);
        }
    }
}