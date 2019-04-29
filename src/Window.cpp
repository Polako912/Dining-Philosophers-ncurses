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
        printw("Widelec[%d] jest:\twolny", i+1);
        refresh();  
        mt.unlock();
    }
}

void Window::PutDownLeftFork(int left, int id)
{
    mt.lock();
    move(left, 55);
    clrtoeol();
    printw("Widelec[%d] jest:\twolny", left+1);
    refresh();
    mt.unlock();
}

void Window::PutDownRightFork(int right, int id)
{
    mt.lock();
    move(right, 55);
    clrtoeol();
    printw("Widelec[%d] jest:\twolny", right+1);
    refresh();
    mt.unlock();
}

void Window::PickUpLeftFork(int left, int id)
{
    mt.lock();
    move(left, 55);
    clrtoeol();
    printw("Widelec[%d] jest:\tzajety", left+1);
    refresh();
    mt.unlock();
}

void Window::PickUpRightFork(int right, int id)
{
    mt.lock();
    move(right, 55);
    clrtoeol();
    printw("Widelec[%d] jest:\tzajety", right+1);
    refresh();
    mt.unlock();
}

void Window::Eat(int number)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
    mt.lock();
    move(number, 0);
    printw("Filozof nr %d \tje obiad\t", number+1);
    refresh();
    mt.unlock();
}

void Window::Think(int number)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
    mt.lock();
    move(number, 0);
    printw("Filozof nr %d \tmysli\t", number+1);
    refresh();
    mt.unlock();
}

void Window::Hungry(int number)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
    mt.lock();
    move(number, 0);
    printw("Filozof nr %d \tjest glodny\t", number+1);
    refresh();
    mt.unlock();
}

void Window::ReadyToEat(int number)
{
    mt.lock();
    move(number, 0);
    printw("Filozof nr %d \tma oba widelce\t", number+1);
    refresh();
    mt.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2500+(std::rand() % 1000)));
}