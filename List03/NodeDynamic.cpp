//
// Created by bodzisz on 18.11.2021.
//

#include "NodeDynamic.h"

NodeDynamic::NodeDynamic()
{
    parent = NULL;
    value = 0;
}

NodeDynamic::NodeDynamic(int nodeValue)
{
    parent = NULL;
    value = nodeValue;
}

NodeDynamic::NodeDynamic(int nodeValue, NodeDynamic *parent)
{
    this->parent = parent;
    value = nodeValue;
}

NodeDynamic::~NodeDynamic()
{
    if(parent != NULL)
    {
        delete parent;
    }
    for(int i = 0; i < getChildrenNumber(); i++)
    {
        children[i]->deleteChildren();
    }
}

void NodeDynamic::deleteChildren()
{
    for(int i = 0; i < getChildrenNumber(); i++)
    {
        if(children[i]->getChildrenNumber() == 0)
        {
            delete children[i];
        }
        else
        {
            children[i]->deleteChildren();
        }
    }
}

void NodeDynamic::setValue(int newValue)
{
    value = newValue;
}

int NodeDynamic::getChildrenNumber() const
{
    return children.size();
}

void NodeDynamic::addChild(int childValue)
{
    children.emplace_back(new NodeDynamic(childValue, this));
}

NodeDynamic *NodeDynamic::getChild(int offset)
{
    if(offset >= getChildrenNumber() || offset < 0)
    {
        return NULL;
    }
    return children[offset];
}

void NodeDynamic::print()
{
    std::cout << " " << value;
}

void NodeDynamic::printAllBelow()
{
    std::queue<NodeDynamic> printQueue;
    print();
    for(int i = 0; i < getChildrenNumber(); i++)
    {
        printQueue.push(*children[i]);
    }
    printAllBelowRecursion(printQueue);
}

void NodeDynamic::printAllBelowRecursion(std::queue<NodeDynamic> printQueue)
{
    if(!printQueue.empty()) {
        NodeDynamic currentNode = printQueue.front();
        currentNode.print();
        for (int i = 0; i < currentNode.getChildrenNumber(); i++) {
            printQueue.push(*currentNode.children[i]);
        }
        printQueue.pop();
        printAllBelowRecursion(printQueue);
    }
}




