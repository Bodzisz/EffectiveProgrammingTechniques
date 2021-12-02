//
// Created by bodzisz on 18/11/2021.
//

#ifndef LIST03_NODESTATIC_H
#define LIST03_NODESTATIC_H

#include <vector>
#include <queue>
#include <iostream>

class NodeStatic {

private:
    std::vector<NodeStatic> children;
    NodeStatic *parent;
    int value;

public:
    NodeStatic();
    NodeStatic(int value);
    NodeStatic(int value, NodeStatic *parent);
    ~NodeStatic();

    void setValue(int newValue);

    int getChildrenNumber() const;
    std::vector<NodeStatic> *getChildren();
    NodeStatic *getChild(int offset);
    void addChild(int childValue);
    void addChild(NodeStatic *child);
    void setParent(NodeStatic *parent);
    void setChildren(std::vector<NodeStatic> children);


    void print();
    void printAllBelow();
    void printUp();

    void treeTest();
    bool moveSubtree(NodeStatic *parentNode, NodeStatic *newChildNode);

private:
    void printAllBelowRecursion(std::queue<NodeStatic> printQueue);
};


#endif //LIST03_NODESTATIC_H
