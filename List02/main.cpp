#include <iostream>
#include "CTable.h"

int main()
{
    std::cout << "\nEx.4 \n\n";

    CTable *myTable1 = new CTable();
    CTable *myTable2 = new CTable("myName", 5);
    CTable myTable3("myName3", 10);
    int *myTable2Nums = myTable2->getTable();
    for(int i = 0; i < 5; i++)
    {
       myTable2Nums[i] = i;
    }
    for(int i = 0; i < 5; i++)
    {
        std::cout << myTable2Nums[i] << " ";
    }
    std::cout << "\n\n";


    CTable *newTab = myTable2->pcClone();
    std::cout << "New tab:" << std::endl;
    std::cout << "Name:" << newTab->getName() << " table: " << std::endl;
    for(int i = 0; i < newTab->getTableSize(); i++)
    {
        std::cout << newTab->getTable()[i] << " ";
    }
    std::cout << "\n";

    CTable tab00, tab01;
    tab00.setNewSize(6);
    tab01.setNewSize(4);
    tab00 = tab01;

    tab01.setNewValueAt(2, 123);

    std::cout << "tab00 table size: " << tab00.getTableSize() << std::endl;
    std::cout << "tab01 table size: " << tab01.getTableSize() << "\n\n";
    std::cout << "TABS USED IN MERGE: " << std::endl;
    tab00.print();
    tab01.print();


    CTable mergedTab = (tab00 + tab01);
    std::cout << "\nMERGED TAB: " << std::endl;
    mergedTab.print();
    std::cout << "\n\n";

    CTable entranceTab ("myName123", 10);
    entranceTab.setNewValueAt(1,100);
    entranceTab.setNewValueAt(2,2);
    entranceTab.print();

    entranceTab *= 2;
    entranceTab.print();

    CTable anotherTable("sfsadsa", 5);;
    anotherTable.setNewValueAt(0,2);
    anotherTable.setNewValueAt(1,5);
    entranceTab = (anotherTable * 2);
    entranceTab.print();

    std::cout << "\n\n";

    delete myTable1;
    delete myTable2;
    delete newTab;



    return 0;
}
