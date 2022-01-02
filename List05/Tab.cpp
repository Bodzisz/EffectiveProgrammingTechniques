//
// Created by bodzisz on 02.01.2022.
//

#include "Tab.h"
#include <iostream>

Tab::Tab()
{
    tab = new int[DEF_TAB_SIZE];
    size = DEF_TAB_SIZE;
}

Tab::Tab(const Tab &other)
{
    copy(other);
    std::cout << "Copy ";
}

Tab::Tab(Tab &&other)
{
    tab = other.tab;
    size = other.size;
    other.tab = NULL;
    other.size = 0;
    std::cout << "MOVE ";
}

Tab::~Tab()
{
    std::cout << "Destr ";
    if (tab != NULL)
    {
        delete tab;
    }

}

Tab Tab::operator=(const Tab &other)
{
    std::cout << "op= ";
    if (tab != NULL) delete tab;
    copy(other);
    return(*this);
}

Tab Tab::operator=(Tab &&other)
{
    std::cout << "moveOp= ";
    if(this != &other)
    {
        delete[] tab;

        tab = other.tab;
        size = other.size;

        other.tab = NULL;
        other.size = 0;
    }
    return *this;
}

void Tab::copy(const Tab &other)
{
    tab = new int[other.size];
    size = other.size;
    for (int ii = 0; ii < other.size; ii++)
        tab[ii] = other.tab[ii];
}

bool Tab::bSetSize(int newSize)
{
    return size = newSize;
}




