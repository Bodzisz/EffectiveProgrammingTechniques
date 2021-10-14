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

    delete myTable1;
    delete myTable2;


    return 0;
}
