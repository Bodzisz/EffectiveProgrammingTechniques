#include <iostream>
#include "MySmartPointer.h"
#include "Tab.h"

int main()
{
    MySmartPointer<int> number(new int(5));
    std::cout << *number << std::endl;

    Tab tab;
    Tab other;
    tab.bSetSize(10);
    other.bSetSize(20);
    /*initialize c_tab, c_other*/
    tab = std::move(other);
    std::cout << tab.iGetSize() << std::endl;
    std::cout << other.iGetSize() << std::endl;


    return 0;
}
