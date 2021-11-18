//
// Created by bodzisz on 18.11.2021.
//

#include "TreeStatic.h"

TreeStatic::TreeStatic()
{
    root = NodeStatic();
}

TreeStatic::~TreeStatic() {}

NodeStatic *TreeStatic::getRoot()
{
    return &root;
}

void TreeStatic::printTree()
{
    root.printAllBelow();
}
