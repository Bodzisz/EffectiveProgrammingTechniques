#include <iostream>
#include "List01Functions.h"
#include "CTable.h"

int main()
{
    List01Functions functions;
    functions.vAllocTableAdd5(0);
    functions.vAllocTableAdd5(5);

    std::cout << std::endl;

    int **piTable;
    int iSizeX = 5;
    int iSizeY = 3;
    functions.bAllocTable2Dim(&piTable, iSizeX, iSizeY);
    for(int i = 0; i < iSizeY; i++)
    {
        for(int j = 0; j < iSizeX; j++)
        {
            std::cout << piTable[i][j] << " ";
        }
        std::cout << std::endl;
    }

    functions.bDeallocTable2Dim(piTable, iSizeX, iSizeY);

    // Zad 4

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

    functions.v_mod_tab(myTable2, 20);
    functions.v_mod_tab(myTable3, 20);

    std::cout << "pointer as parameter (should be 20): " << myTable2->getTableSize() << std::endl;
    std::cout << "object as parameter (should be 20): " << myTable3.getTableSize() << std::endl;

    std::cout << "\n\n";

    std::cout << "Old tab:" << std::endl;
    std::cout << "Name:" << myTable2->getName() << " table: " << std::endl;
    for(int i = 0; i < myTable2->getTableSize(); i++)
    {
        std::cout << myTable2->getTable()[i] << " ";
    }
    std::cout << "\n";

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
    std::cout << "tab01 table size: " << tab01.getTableSize() << std::endl;
    tab00.print();
    tab01.print();

    tab00.setTable((tab00 + tab01), tab00.getTableSize() + tab01.getTableSize());
    tab00.print();


    delete myTable1;
    delete myTable2;
    delete newTab;


    return 0;
}
