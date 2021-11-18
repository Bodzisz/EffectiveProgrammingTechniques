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
    ~NodeStatic();

    void setValue(int newValue);

    int getChildrenNumber() const;
    NodeStatic *getChild(int offset);
    void addChild(int value);

    void print();
    void printAllBelow();
    void printUp();

    void treeTest();

private:
    void printAllBelowRecursion(std::queue<NodeStatic> printQueue);
};


#endif //LIST03_NODESTATIC_H