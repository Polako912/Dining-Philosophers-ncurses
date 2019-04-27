#include <iostream>
#include <ncurses.h>
#include "../include/Window.h"

Window::Window()
{
    
}

Window::~Window()
{

}

void Window::Visualise(int number, std::string status)
{
    for (int i = 0; i < number; i++)
    {
        mt.lock();
        move(i, 0);
        printw(" Filozof nr: %d | Stan: %s", i+1, status);
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
    printw("Widelec[%d] jest:\twolny", left+1);
    refresh();
    mt.unlock();
}

void Window::PutDownRightFork(int right)
{
    mt.lock();
    move(right, 55);
    clrtoeol();
    printw("Widelec[%d] jest:\twolny", right+1);
    refresh();
    mt.unlock();
}

void Window::PickUpLeftFork(int left)
{
    mt.lock();
    move(left, 55);
    clrtoeol();
    printw("Widelec[%d] jest:\zajety", left+1);
    refresh();
    mt.unlock();
}

void Window::PickUpRightFork(int right)
{
    mt.lock();
    move(right, 55);
    clrtoeol();
    printw("Widelec[%d] jest:\zajety", right+1);
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