#include <iostream>
#include "MySmartPointer.h"
#include "Tab.h"
#include "Table.h"

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

    Table entranceTab ("myName123", 10);
    entranceTab.setNewValueAt(1,100);
    entranceTab.setNewValueAt(2,2);
    entranceTab.print();

    Table entranceTab2("12133", 2);
    entranceTab2.setNewValueAt(0,4);
    entranceTab2.setNewValueAt(1,3);
    entranceTab2.print();

    Table entranceTab3 = entranceTab + entranceTab2;
    entranceTab3.print();

    entranceTab3 *= 2;


    return 0;
}
