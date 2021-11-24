#include <iostream>
#include "TreeStatic.h"
#include "TreeDynamic.h"

int main() {

    TreeStatic staticTree;
    staticTree.getRoot()->addChild(5);
    staticTree.getRoot()->addChild(10);

    TreeStatic staticTree2;
    staticTree2.getRoot()->addChild(1);
    staticTree2.getRoot()->addChild(2);
    staticTree2.getRoot()->getChild(0)->addChild(3);
    staticTree2.getRoot()->getChild(0)->getChild(0)->addChild(4);
    std::cout << "BEFORE:" << std::endl;
    staticTree.printTree();
    std::cout << "\n";
    staticTree2.printTree();
    std::cout << "\n";

    staticTree.moveSubtree(staticTree.getRoot()->getChild(0), staticTree2.getRoot()->getChild(0));
    std::cout << "AFTER:" << std::endl;
    staticTree.printTree();
    std::cout << "\n";
    staticTree2.printTree();

    std::cout << "\n";
    //staticTree.getRoot()->treeTest();

    std::cout << "\n";

    TreeDynamic *dynamicTree = new TreeDynamic();
    dynamicTree->getRoot()->setValue(5);
    dynamicTree->getRoot()->addChild(10);
    dynamicTree->getRoot()->addChild(15);

    TreeDynamic *dynamicTree2 = new TreeDynamic();
    dynamicTree2->getRoot()->setValue(1);
    dynamicTree2->getRoot()->addChild(2);
    dynamicTree2->getRoot()->addChild(3);
    dynamicTree2->getRoot()->getChild(0)->addChild(4);

    std::cout << "BEFORE:" << std::endl;
    dynamicTree->printTree();
    std::cout << "\n";
    dynamicTree2->printTree();
    std::cout << "\n";


    dynamicTree->moveSubtree(dynamicTree->getRoot()->getChild(0), dynamicTree2->getRoot()->getChild(0));
    std::cout << "AFTER:" << std::endl;
    dynamicTree->printTree();
    std::cout << "\n";
    dynamicTree2->printTree();

    delete dynamicTree;
    delete dynamicTree2;

    return 0;
}
