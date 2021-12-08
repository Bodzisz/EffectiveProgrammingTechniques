//
// Created by bodzisz on 08.12.2021.
//

#ifndef LIST04_TREEDYNAMIC_H
#define LIST04_TREEDYNAMIC_H

#include "NodeDynamic.h"


template<typename T> class TreeDynamic
{
    NodeDynamic<T>* root;

public:
    TreeDynamic();
    TreeDynamic(T rootValue);
    ~TreeDynamic();

    NodeDynamic<T>* getRoot();
    void printTree();
    bool moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode);

};


template<typename T> TreeDynamic<T>::TreeDynamic() {
    root = new NodeDynamic<T>();
}

template<typename T> TreeDynamic<T>::TreeDynamic(T rootValue) {
    root = new NodeDynamic<T>(rootValue);
}

template<typename T> TreeDynamic<T>::~TreeDynamic() {
    delete root;
}

template<typename T> NodeDynamic<T>* TreeDynamic<T>::getRoot() {
    return root;
}

template<typename T> void TreeDynamic<T>::printTree() {
    root->printAllBelow();
}

template<typename T> bool TreeDynamic<T>::moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode) {
    return root->moveSubtree(parentNode, newChildNode);
}


#endif //LIST04_TREEDYNAMIC_H
