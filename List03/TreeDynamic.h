//
// Created by bodzisz on 18.11.2021.
//

#ifndef LIST03_TREEDYNAMIC_H
#define LIST03_TREEDYNAMIC_H

#include "NodeDynamic.h"


class TreeDynamic
{
private:
    NodeDynamic *root;
public:
    TreeDynamic();
    ~TreeDynamic();

    NodeDynamic *getRoot();
    void printTree();
};


#endif //LIST03_TREEDYNAMIC_H
