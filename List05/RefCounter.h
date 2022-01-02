//
// Created by bodzisz on 02.01.2022.
//

#ifndef LIST05_REFCOUNTER_H
#define LIST05_REFCOUNTER_H


class RefCounter
{
    int i_count;

public:
    RefCounter();
    int add();
    int dec();
    int get();
};


#endif //LIST05_REFCOUNTER_H
