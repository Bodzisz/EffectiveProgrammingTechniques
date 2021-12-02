//
// Created by bodzisz on 18.11.2021.
//

#include "TreeDynamic.h"

TreeDynamic::TreeDynamic()
{
    root = new NodeDynamic();
}

TreeDynamic::~TreeDynamic()
{
    delete root;
}

NodeDynamic *TreeDynamic::getRoot()
{
    return root;
}

void TreeDynamic::printTree()
{
    root->printAllBelow();
}

bool TreeDynamic::moveSubtree(NodeDynamic *parentNode, NodeDynamic *newChildNode)
{
    root->moveSubtree(parentNode, newChildNode);
}


