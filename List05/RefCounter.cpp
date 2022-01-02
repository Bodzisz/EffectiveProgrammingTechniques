//
// Created by bodzisz on 02.01.2022.
//

#include "RefCounter.h"

RefCounter::RefCounter() {}

int RefCounter::add()
{
    return(++i_count);
}

int RefCounter::dec()
{
    return(--i_count);
}

int RefCounter::get()
{
    return i_count;
}
