//
// Created by bodzisz on 09.12.2021.
//

template<typename T> NodeDynamic<T>::NodeDynamic() {
    parent = NULL;
    value = T();
}

template<typename T> NodeDynamic<T>::NodeDynamic(T nodeValue) {
    value = nodeValue;
}

template<typename T> NodeDynamic<T>::NodeDynamic(T nodeValue, NodeDynamic<T> *parent) {
    this->parent = parent;
    value = nodeValue;
}

template<typename T> NodeDynamic<T>::~NodeDynamic() {
    for(int i = 0; i < getChildrenNumber(); i++)
    {
        delete children[i];
    }
}

template<typename T> void NodeDynamic<T>::setValue(T newValue) {
    value = newValue;
}

template<typename T> int NodeDynamic<T>::getChildrenNumber() {
    return children.size();
}

template<typename T> T NodeDynamic<T>::getValue() {
    return value;
}

template<typename T> NodeDynamic<T>* NodeDynamic<T>::getChild(int offset) {
    if(offset >= getChildrenNumber() || offset < 0)
    {
        return NULL;
    }
    return children[offset];
}

template<typename T> NodeDynamic<T>* NodeDynamic<T>::getRoot() {
    NodeDynamic<T>* node = this;
    while(node->parent != NULL) {
        node = node->parent;
    }
    return node;
}

template<typename T> void NodeDynamic<T>::addChild(T childValue) {
    children.push_back(new NodeDynamic<T>(childValue, this));
}

template<typename T> void NodeDynamic<T>::addChild(NodeDynamic<T>* child) {
    children.push_back(child);
}

template<typename T> bool NodeDynamic<T>::removeChild(NodeDynamic<T>* child) {
    for(int i = 0; i < getChildrenNumber(); i++)
    {
        if(children[i] == child)
        {
            children.erase(children.begin() + i);
            return true;
        }
    }
    return false;
}

template<typename T> void NodeDynamic<T>::print() {
    std::cout << " " << value;
}

template<typename T> void NodeDynamic<T>::printAllBelow() {
    std::queue<NodeDynamic*> printQueue;
    print();
    for(int i = 0; i < getChildrenNumber(); i++)
    {
        printQueue.push(children[i]);
    }
    printAllBelowRecursion(printQueue);
}

template<typename T> bool NodeDynamic<T>::moveSubtree(NodeDynamic *parentNode, NodeDynamic *newChildNode) {
    if(parentNode == NULL || newChildNode == NULL || parentNode->getRoot() == newChildNode->getRoot())
    {
        return false;
    }

    if(newChildNode->parent != NULL)
    {
        newChildNode->parent->removeChild(newChildNode);
    }

    newChildNode->parent = parentNode;
    parentNode->addChild(newChildNode);
    return true;
}

template<typename T> void NodeDynamic<T>::printAllBelowRecursion(std::queue<NodeDynamic*> printQueue) {
    if(!printQueue.empty()) {
        NodeDynamic *currentNode = printQueue.front();
        currentNode->print();
        for (int i = 0; i < currentNode->getChildrenNumber(); i++) {
            printQueue.push(currentNode->children[i]);
        }
        printQueue.pop();
        printAllBelowRecursion(printQueue);
    }
}
