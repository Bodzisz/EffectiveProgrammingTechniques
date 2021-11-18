#include <iostream>
#include "TreeStatic.h"
#include "TreeDynamic.h"

int main() {

    TreeStatic staticTree;
    staticTree.getRoot()->treeTest();

    std::cout << "\n";

    TreeDynamic *dynamicTree = new TreeDynamic();
    dynamicTree->getRoot()->setValue(5);
    dynamicTree->getRoot()->addChild(10);
    dynamicTree->getRoot()->addChild(15);
    dynamicTree->printTree();

    delete dynamicTree;

    return 0;
}
