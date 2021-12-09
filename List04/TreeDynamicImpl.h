//
// Created by bodzisz on 09.12.2021.
//

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
