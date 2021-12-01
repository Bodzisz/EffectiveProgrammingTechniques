//
// Created by bodzisz on 18.11.2021.
//

#ifndef LIST03_NODEDYNAMIC_H
#define LIST03_NODEDYNAMIC_H

#include <iostream>
#include <vector>
#include <queue>


class NodeDynamic
{
private:
    std::vector<NodeDynamic*> children;
    NodeDynamic *parent;
    int value;

public:
    NodeDynamic();
    NodeDynamic(int nodeValue);
    //NodeDynamic(NodeDynamic const& newNode);
    NodeDynamic(int nodeValue, NodeDynamic *parent);
    ~NodeDynamic();

    void setValue(int newValue);
    int getChildrenNumber();
    void addChild(int childValue);
    void addChild(NodeDynamic *child);
    NodeDynamic *getChild(int offset);
    bool removeChild(NodeDynamic *child);

    void print();
    void printAllBelow();
    void deleteChildren();
    bool moveSubtree(NodeDynamic *parentNode, NodeDynamic *newChildNode);

private:
    void printAllBelowRecursion(std::queue<NodeDynamic*> printQueue);
};


#endif //LIST03_NODEDYNAMIC_H
