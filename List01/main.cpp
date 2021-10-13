#include <iostream>
#include "List01Functions.h"

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

    return 0;
}
