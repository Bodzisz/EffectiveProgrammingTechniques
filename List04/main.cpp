#include <iostream>
#include "TreeDynamic.h"
#include <string>

int main()
{
    TreeDynamic<int> numberTree1(125);
    numberTree1.getRoot()->addChild(1);
    numberTree1.getRoot()->addChild(2);
    numberTree1.getRoot()->addChild(3);
    numberTree1.getRoot()->getChild(0)->addChild(77);
    numberTree1.getRoot()->getChild(0)->addChild(66);
    numberTree1.getRoot()->getChild(0)->getChild(0)->addChild(666);

    TreeDynamic<int> numberTree2(321);
    numberTree2.getRoot()->addChild(31);
    numberTree2.getRoot()->addChild(32);
    numberTree2.getRoot()->getChild(0)->addChild(33);

    std::cout << "BEFORE:" << std::endl;
    numberTree1.printTree();
    std::cout << "\n";
    numberTree2.printTree();
    std::cout << "\n";

    numberTree1.moveSubtree(numberTree1.getRoot()->getChild(0)->getChild(0),
                            numberTree2.getRoot()->getChild(0));

    std::cout << "AFTER:" << std::endl;
    numberTree1.printTree();
    std::cout << "\n";
    numberTree2.printTree();
    std::cout << "\n\n";

    NodeDynamic<int> *node = numberTree1.getRoot()->getChild(0)->getChild(0)->getChild(1)->getChild(0);
    std::cout << node->getValue() << std::endl;
    std::cout << node->getRoot()->getValue();
    std::cout << "\n\n";

    TreeDynamic<std::string> stringTree("HELLO");
    stringTree.getRoot()->addChild("WORLD");
    stringTree.getRoot()->addChild("123");
    stringTree.getRoot()->getChild(0)->addChild("FOO");
    stringTree.printTree();

    return 0;
}
