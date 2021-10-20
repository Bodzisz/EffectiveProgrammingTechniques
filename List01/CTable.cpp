//
// Created by bodzisz on 14/10/2021.
//

#include "CTable.h"


CTable::CTable()
{
    sName = defaultName;
    tableSize = defaultTableSize;
    table = new int[tableSize];

    std::cout << "bezp:" + sName << std::endl;
}

CTable::CTable(std::string sName, int iTableLen)
{
    if(iTableLen <= 0)
    {
        tableSize = defaultTableSize;
    }
    else
    {
        tableSize = iTableLen;
    }
    this->sName = sName;
    this->table = new int[tableSize];
}

CTable::CTable(CTable &pcOther)
{
    sName = pcOther.sName + "_copy";
    tableSize = pcOther.tableSize;
    table = new int[tableSize];
    this->copyTable(pcOther.table, table, pcOther.tableSize);
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
    if(iTableLen <= 0)
    {
        std::cout << "Invalid length to set" << std::endl;
        return false;
    }
    int *newTable = new int[iTableLen];
    if(iTableLen < tableSize)
    {
        this->copyTable(table, newTable, iTableLen);
    }
    else
    {
        this->copyTable(table, newTable, tableSize);
    }

    tableSize = iTableLen;
    table = newTable;

    return true;

}
// Pytanie czy nazwa klona ma mieć dopisek w sName _copy ?
CTable *CTable::pcClone() {
    return new CTable(*this);
}

void CTable::copyTable(const int *table1, int *table2, int tableSize)
{
    for(int i = 0; i < tableSize; i++)
    {
        table2[i] = table1[i];
    }
}


int CTable::getTableSize()
{
    return tableSize;
}


