#include "List01Functions.h"
#include <iostream>

// wedlug mnie "5" powinno być parametrem funkcji
void List01Functions::vAllocTableAdd5(int iSize)
{
    if(iSize <= 0)
    {
        std::cout << "Wrong size of the table" << std::endl;
    }
    else
    {

        int *dynamicAllocTable = new int[iSize];
        for (int i = 0; i < iSize; i++)
        {
            dynamicAllocTable[i] = i + 5;
            std::cout << dynamicAllocTable[i] << std::endl;
        }

        delete[] dynamicAllocTable;
    }
}

bool List01Functions::bAllocTable2Dim(int ***piTable, int iSizeX, int iSizeY)
{
    if(iSizeX <= 0 || iSizeY <= 0)
    {
        return false;
    }

    *piTable = new int*[iSizeY];
    int x = 0;

    for(int i = 0; i < iSizeY; i++)
    {
        (*piTable)[i] = new int[iSizeX];
        for(int j = 0; j < iSizeX; j++)
        {
            (*piTable)[i][j] = ++x;
        }
    }

    return true;
}

bool List01Functions::bDeallocTable2Dim(int **piTable, int iSizeX, int iSizeY)
{
    if(iSizeX <= 0 || iSizeY <= 0)
    {
        return false;
    }

    for(int i = 0; i < iSizeY; i++)
    {
        delete [] piTable[i];
    }
    delete[] piTable;

    return true;
}
