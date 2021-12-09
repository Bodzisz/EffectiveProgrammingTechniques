//
// Created by bodzisz on 08.12.2021.
//

#ifndef LIST04_NODEDYNAMIC_H
#define LIST04_NODEDYNAMIC_H

#include <iostream>
#include <vector>
#include <queue>


template <typename T> class NodeDynamic
{
    std::vector<NodeDynamic<T>*> children;
    NodeDynamic<T> *parent;
    T value;

public:
    NodeDynamic();
    NodeDynamic(T nodeValue);
    NodeDynamic(T nodeValue, NodeDynamic<T> *parent);
    ~NodeDynamic();

    void setValue(T newValue);
    int getChildrenNumber();
    T getValue();
    NodeDynamic<T>* getChild(int offset);
    NodeDynamic<T>* getRoot();
    void addChild(T childValue);
    void addChild(NodeDynamic<T>* child);
    bool removeChild(NodeDynamic<T>* child);
    void print();
    void printAllBelow();
    bool moveSubtree(NodeDynamic *parentNode, NodeDynamic *newChildNode);

private:
    void printAllBelowRecursion(std::queue<NodeDynamic*> printQueue);
};

#include "NodeDynamicImpl.h"


#endif //LIST04_NODEDYNAMIC_H
