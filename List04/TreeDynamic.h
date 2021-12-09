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

#include "TreeDynamicImpl.h"


#endif //LIST04_TREEDYNAMIC_H
