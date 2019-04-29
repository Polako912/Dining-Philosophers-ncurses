#include <iostream>
#include <ncurses.h>
#include <chrono>
#include <thread>
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
        printw("Filozof nr %d jest glodny", i+1);
        refresh();
        move(i, 55);
        clrtoeol();
        printw("Widelec[%d] jest: wolny", i+1);
        refresh();  
        mt.unlock();
    }
}

void Window::PutDownLeftFork(int left, int id)
{
    mt.lock();
    // move(id, 0);
    // printw("Filozof nr %d ma widelec nr [%d]", id+1, left+1);
    // refresh();
    move(left, 55);
    clrtoeol();
    printw("Widelec[%d] jest: wolny", left+1);
    refresh();
    mt.unlock();
    //std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Window::PutDownRightFork(int right, int id)
{
    mt.lock();
    // move(id, 0);
    // printw("Filozof nr %d ma widelec nr [%d]", id+1, right+1);
    // refresh();
    move(right, 55);
    clrtoeol();
    printw("Widelec[%d] jest: wolny", right+1);
    refresh();
    mt.unlock();
    //std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Window::PickUpLeftFork(int left, int id)
{
    mt.lock();
    // move(id, 0);
    // printw("Filozof nr %d ma widelec nr [%d]", id+1, left+1);
    // refresh();
    move(left, 55);
    clrtoeol();
    printw("Widelec[%d] jest: zajety", left+1);
    refresh();
    mt.unlock();
    //std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Window::PickUpRightFork(int right, int id)
{
    mt.lock();
    // move(id, 0);
    // printw("Filozof nr %d ma widelec nr [%d]", id+1, right+1);
    // refresh();
    move(right, 55);
    clrtoeol();
    printw("Widelec[%d] jest: zajety", right+1);
    refresh();
    mt.unlock();
    //std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Window::Eat(int number)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
    mt.lock();
    move(number, 0);
    clrtoeol();
    printw("Filozof nr %d je obiad", number+1);
    refresh();
    mt.unlock();
}

void Window::Think(int number)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
    mt.lock();
    move(number, 0);
    clrtoeol();
    printw("Filozof nr %d mysli", number+1);
    refresh();
    mt.unlock();
}

void Window::Hungry(int number)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
    mt.lock();
    move(number, 0);
    clrtoeol();
    printw("Filozof nr %d jest glodny", number+1);
    refresh();
    mt.unlock();
}

void Window::ReadyToEat(int number)
{
    mt.lock();
    move(number, 0);
    clrtoeol();
    printw("Filozof nr %d ma oba widelce", number+1);
    refresh();
    mt.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}

void Window::RefreshPhiosopher(int id, std::string status)
{
    mt.lock();
    move(id, 0);
    printw(" Filozof nr: %d | Stan: %s", id+1, status);
    refresh();
    //std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
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