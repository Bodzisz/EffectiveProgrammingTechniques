#ifndef LIST01_LIST01FUNCTIONS_H
#define LIST01_LIST01FUNCTIONS_H


class List01Functions
{
public:
    void vAllocTableAdd5(int iSize);
    bool bAllocTable2Dim(int ***piTable, int iSizeX, int iSizeY);
    bool bDeallocTable2Dim(int **piTable, int iSizeX, int iSizeY);
};


#endif //LIST01_LIST01FUNCTIONS_H
