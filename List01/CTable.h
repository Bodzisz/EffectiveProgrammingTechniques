//
// Created by bodzisz on 14/10/2021.
//

#ifndef LIST01_CTABLE_H
#define LIST01_CTABLE_H

#include <string>
#include <iostream>

const int defaultTableSize = 10;

class CTable {
private:
    std::string sName;
    int *table;
    int tableSize;

public:
    CTable();
    CTable (std::string sName, int iTableLen);
    CTable (CTable &pcOther);
    ~CTable();

    CTable *pcClone();
    void v_mod_tab(CTable *pcTab, int iNewSize);
    void v_mod_tab(CTable cTab, int iNewSize);

    // setters
    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);

    // getters
    std::string getName();
    int* getTable();

private:
     void copyTable(int* table1, int* table2, int tableSize);
};


#endif //LIST01_CTABLE_H
