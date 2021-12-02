//
// Created by bodzisz on 18.11.2021.
//

#include "TreeStatic.h"

TreeStatic::TreeStatic()
{
    root = NodeStatic();
}

TreeStatic::TreeStatic(NodeStatic *root) {
    this->root = *root;
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

void TreeStatic::moveSubtree(NodeStatic *parentNode, NodeStatic *newChildNode)
{
    root.moveSubtree(parentNode, newChildNode);
}

std::vector<TreeStatic> TreeStatic::split_trees(NodeStatic *node)
{
    std::vector<TreeStatic> result;
    for(int i = 0; i < node->getChildrenNumber(); i++)
    {
        node->getChild(i)->setParent(NULL);
        result.push_back(node->getChild(i));
    }
    node->getChildren()->clear();
    return result;
}







