//
// Created by bodzisz on 02.01.2022.
//

#ifndef LIST05_MYSMARTPOINTER_H
#define LIST05_MYSMARTPOINTER_H

#include "RefCounter.h"

template <typename T> class MySmartPointer
{
    T *pointer;
    RefCounter *counter;

public:
    MySmartPointer(T *pointer);
    MySmartPointer(const MySmartPointer<T> &other);
    ~MySmartPointer();
    T& operator*();
    T* operator->();
    MySmartPointer<T>& operator=(const MySmartPointer<T> &smartPointer);
};

template <typename T> MySmartPointer<T>::MySmartPointer(T *pointer) {
    this->pointer = pointer;
    counter = new RefCounter();
    counter->add();
}

template<typename T> MySmartPointer<T>::MySmartPointer(const MySmartPointer<T> &other)
{
    pointer = other.pointer;
    counter = other.counter;
    counter->add();
}

template<typename T> MySmartPointer<T>::~MySmartPointer()
{
    if (counter->dec() == 0)
    {
        delete pointer;
        delete counter;
    }
}

template<typename T> T& MySmartPointer<T>::operator*()
{
    return (*pointer);
}

template<typename T> T* MySmartPointer<T>::operator->()
{
    return pointer;
}

template<typename T> MySmartPointer<T>& MySmartPointer<T>::operator=(const MySmartPointer<T> &smartPointer)
{
    if(this != &smartPointer) {
        if(counter->dec() == 0)
        {
            delete pointer;
            delete counter;
        }
        pointer = smartPointer.pointer;
        counter = smartPointer.counter;
        counter->add();
    }
    return *this;
}


//#include "MySmartPointerImpl.h"


#endif //LIST05_MYSMARTPOINTER_H
