#ifndef LIST01_LIST01FUNCTIONS_H
#define LIST01_LIST01FUNCTIONS_H

#include "CTable.h"


class List01Functions
{
public:
    void vAllocTableAdd5(int iSize);
    bool bAllocTable2Dim(int ***piTable, int iSizeX, int iSizeY);
    bool bDeallocTable2Dim(int **piTable, int iSizeX, int iSizeY);

    void v_mod_tab(CTable *pcTab, int iNewSize);
    void v_mod_tab(CTable cTab, int iNewSize);
};


#endif //LIST01_LIST01FUNCTIONS_H
