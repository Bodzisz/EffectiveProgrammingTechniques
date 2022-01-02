//
// Created by bodzisz on 02.01.2022.
//

#ifndef LIST05_TAB_H
#define LIST05_TAB_H

#define DEF_TAB_SIZE 10
class Tab
{
    int *tab;
    int size;

    void copy(const Tab &other);

public:
    Tab();
    Tab(const Tab &other);
    Tab(Tab &&other);
    Tab operator=(const Tab &other);
    Tab operator=(Tab &&other);
    ~Tab();
    bool bSetSize(int newSize);
    int iGetSize() { return(size); }

};


#endif //LIST05_TAB_H
