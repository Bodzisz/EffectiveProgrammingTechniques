//
// Created by bodzisz on 18.11.2021.
//

#ifndef LIST03_TREESTATIC_H
#define LIST03_TREESTATIC_H

#include "NodeStatic.h"


class TreeStatic
{
private:
    NodeStatic root;

public:
    TreeStatic();
    ~TreeStatic();

    NodeStatic *getRoot();
    void printTree();
};


#endif //LIST03_TREESTATIC_H
