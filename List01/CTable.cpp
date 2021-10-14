//
// Created by bodzisz on 14/10/2021.
//

#include "CTable.h"


CTable::CTable()
{
    this->sName = "defaultName";
    this->tableSize = defaultTableSize;
    this->table = new int[tableSize];

    std::cout << "bezp:" + sName << std::endl;
}

CTable::CTable(std::string sName, int iTableLen)
{
    if(iTableLen <= 0)
    {
        this->tableSize = defaultTableSize;
    }
    else
    {
        this->tableSize = iTableLen;
    }
    this->sName = sName;
    this->table = new int[tableSize];
}

CTable::CTable(CTable &pcOther)
{
    this->sName = pcOther.sName + "_copy";
    this->tableSize = sizeof(pcOther.table) / sizeof(pcOther.table[0]);
    this->table = new int[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = pcOther.table[i];
    }
}

CTable::~CTable()
{
    std::cout << "usuwam " + sName << std::endl;
    delete [] table;
}

std::string CTable::getName() {
    return sName;
}

int *CTable::getTable() {
    return table;
}

void CTable::vSetName(std::string sName) {
    this->sName = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if(iTableLen < tableSize)
    {
        std::cout << "Invalid length to set" << std::endl;
        return false;
    }

    int *newTable = new int[iTableLen];
    this->copyTable(table, newTable, tableSize);

    tableSize = iTableLen;
    table = newTable;

    delete [] newTable;
}

CTable *CTable::pcClone() {
    CTable *copy = new CTable(sName, tableSize);

    this->copyTable(table, copy->table, tableSize);

    return copy;
}

void CTable::copyTable(int *table1, int *table2, int tableSize)
{
    for(int i = 0; i < tableSize; i++)
    {
        table2[i] = table1[i];
    }
}

void CTable::v_mod_tab(CTable *pcTab, int iNewSize) {
    std::cout << &"Setting size to new value: " [ iNewSize] << std::endl;
    pcTab->bSetNewSize(iNewSize);
}

void CTable::v_mod_tab(CTable cTab, int iNewSize) {
    std::cout << &"Setting size to new value: " [ iNewSize] << std::endl;
    cTab.bSetNewSize(iNewSize);
}


