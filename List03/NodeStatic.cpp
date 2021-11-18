//
// Created by bodzisz on 18/11/2021.
//

#include "NodeStatic.h"

NodeStatic::NodeStatic()
{
    value = 0;
    parent = NULL;
}

NodeStatic::NodeStatic(int value)
{
    parent = NULL;
    this->value = value;
}

NodeStatic::NodeStatic(int value, NodeStatic *parent)
{
    this->parent = parent;
    this->value = value;
}

NodeStatic::~NodeStatic()
{
}

void NodeStatic::setValue(int newValue)
{
    value = newValue;
}

int NodeStatic::getChildrenNumber() const
{
    return children.size();
}

NodeStatic *NodeStatic::getChild(int offset)
{
    if(offset < 0 || offset >= getChildrenNumber())
    {
        return NULL;
    }
    return &children[offset];
}

void NodeStatic::print()
{
    std::cout << " " << value;
}

void NodeStatic::printAllBelow()
{
    std::queue<NodeStatic> printQueue;
    print();
    for(int i = 0; i < getChildrenNumber(); i++)
    {
        printQueue.push(children[i]);
    }
    printAllBelowRecursion(printQueue);
}

void NodeStatic::printAllBelowRecursion(std::queue<NodeStatic> printQueue)
{
    if(!printQueue.empty()) {
        NodeStatic currentNode = printQueue.front();
        currentNode.print();
        for (int i = 0; i < currentNode.getChildrenNumber(); i++) {
            printQueue.push(currentNode.children[i]);
        }
        printQueue.pop();
        printAllBelowRecursion(printQueue);
    }
}

void NodeStatic::addChild(int childValue)
{
    NodeStatic child(childValue, this);
    children.emplace_back(child);
}

void NodeStatic::addChild(NodeStatic *child)
{
    children.emplace_back(*child);
}

void NodeStatic::treeTest()
{
    NodeStatic root;

    root.addChild(1);
    root.addChild(2);

    root.getChild(0)->addChild(3);
    root.getChild(0)->addChild(4);

    root.getChild(1)->addChild(5);
    root.getChild(1)->addChild(6);

    root.printAllBelow();
    std::cout << "\n";
    root.getChild(0)->getChild(0)->printUp();
}

void NodeStatic::printUp()
{
    print();
    if(parent != NULL)
    {
        parent->printUp();
    }
}

bool NodeStatic::moveSubtree(NodeStatic *parentNode, NodeStatic *newChildNode)
{
    if(parentNode == NULL || newChildNode == NULL)
    {
        return false;
    }

    parentNode->addChild(newChildNode);

    if(newChildNode->parent != NULL)
    {
        int index;
        for (int i = 0; i < newChildNode->parent->getChildrenNumber(); i++)
        {
            if (&(newChildNode->parent->children[i]) == newChildNode)
            {
                index = i;
                break;
            }
        }
        newChildNode->parent->children.erase(newChildNode->parent->children.begin() + index);
    }

    newChildNode->parent = parentNode;
    return true;
}








