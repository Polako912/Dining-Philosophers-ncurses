#include <iostream>
#include <ncurses.h>
#include "../include/Window.h"

Window::Window()
{
    
}

Window::~Window()
{

}

void Window::Visualise(int number)
{
    for (int i = 0; i < number; i++)
    {
        mt.lock();
        move(i, 0);
        printw("Filozof nr: %d | jest glodny", i+1);
        refresh();
        move(i, 55);
        clrtoeol();
        printw("Widelec[%d] jest: wolny", i+1);
        refresh();  
        mt.unlock();
    }
}

void Window::PutDownLeftFork(int left)
{
    mt.lock();
    move(left, 55);
    clrtoeol();
    printw("Widelec[%d] jest: wolny", left+1);
    refresh();
    mt.unlock();
}

void Window::PutDownRightFork(int right)
{
    mt.lock();
    move(right, 55);
    clrtoeol();
    printw("Widelec[%d] jest: wolny", right+1);
    refresh();
    mt.unlock();
}

void Window::PickUpLeftFork(int left)
{
    mt.lock();
    move(left, 55);
    clrtoeol();
    printw("Widelec[%d] jest: zajety", left+1);
    refresh();
    mt.unlock();
}

void Window::PickUpRightFork(int right)
{
    mt.lock();
    move(right, 55);
    clrtoeol();
    printw("Widelec[%d] jest: zajety", right+1);
    refresh();
    mt.unlock();
}

void Window::Eat(int number)
{
    mt.lock();
    move(number, 0);
    clrtoeol();
    printw("Filozof nr %d je obiad", number);
    refresh();
    mt.unlock();
}

void Window::Think(int number)
{
    mt.lock();
    move(number, 0);
    clrtoeol();
    printw("Filozof nr %d mysli", number);
    refresh();
    mt.unlock();
}

void Window::Hungry(int number)
{
    mt.lock();
    move(number, 0);
    clrtoeol();
    printw("Filozof nr %d jest glodny", number);
    refresh();
    mt.unlock();
}

void Window::ReadyToEat(int number)
{
    mt.lock();
    move(number, 0);
    clrtoeol();
    printw("Filozof nr %d ma oba widelce", number);
    refresh();
    mt.unlock();
}

void Window::RefreshPhiosopher(int id, std::string status)
{
    mt.lock();
    move(id, 0);
    printw(" Filozof nr: %d | Stan: %s", id+1, status);
    refresh();
    mt.unlock();
}

void Window::RefreshFork(int id, std::string status)
{
    mt.lock();
    move(id, 55);
    clrtoeol();
    printw("Widelec[%d] jest: %s", id+1, status);
    refresh();
    mt.unlock();
}