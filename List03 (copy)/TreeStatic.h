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
    TreeStatic(NodeStatic *root);
    ~TreeStatic();

    NodeStatic *getRoot();
    void printTree();
    void moveSubtree(NodeStatic *parentNode, NodeStatic *newChildNode);
    std::vector<TreeStatic> split_trees(NodeStatic *node);
};


#endif //LIST03_TREESTATIC_H
