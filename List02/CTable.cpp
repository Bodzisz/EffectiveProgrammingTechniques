//
// Created by bodzisz on 14/10/2021.
//

#include "CTable.h"


CTable::CTable()
{
    name = defaultName;
    tableSize = defaultTableSize;
    table = new int[tableSize];

    std::cout << "bezp:" + name << std::endl;
}

CTable::CTable(std::string sName, int tableSize)
{
    if(tableSize <= 0)
    {
        this->tableSize = defaultTableSize;
    }
    else
    {
        this->tableSize = tableSize;
    }
    this->name = sName;
    this->table = new int[tableSize];
}

CTable::CTable(CTable &pcOther)
{
    name = pcOther.name;
    tableSize = pcOther.tableSize;
    table = new int[tableSize];
    this->copyTable(pcOther.table, table, pcOther.tableSize);
}

CTable::~CTable()
{
    std::cout << "usuwam " + name << std::endl;
    delete [] table;
}

std::string CTable::getName() const {
    return name;
}

int *CTable::getTable() const {
    return table;
}

void CTable::setName(std::string name) {
    this->name = name;
}

bool CTable::setNewSize(int iTableLen) {
    if(iTableLen <= 0)
    {
        std::cout << "Invalid length to set" << std::endl;
        return false;
    }
    int *newTable = new int[iTableLen];
    if(iTableLen < tableSize)
    {
        this->copyTable(table, newTable, 0,  iTableLen);
    }
    else
    {
        this->copyTable(table, newTable, 0, tableSize);
    }

    tableSize = iTableLen;
    table = newTable;

    return true;

}

CTable *CTable::pcClone() {
    return new CTable(*this);
}

void CTable::copyTable(const int *copyFromTable, int *copyToTable, int startIndex, int tableSize)
{
    for(int i = 0; i < tableSize; i++)
    {
        copyToTable[startIndex + i] = copyFromTable[i];
    }
}

void CTable::copyTable(int *copyFromTable, int *copyToTable, int tableSize)
{
    copyTable(copyToTable, copyFromTable, 0, tableSize);
}

int CTable::getTableSize() const
{
    return tableSize;
}

//void CTable::operator=(CTable &pcOther) {
//    table = pcOther.table;
//    tableSize = pcOther.tableSize;
//}

void CTable::operator=(CTable &pcOther) {
    tableSize = pcOther.tableSize;
    table = new int[tableSize];
    copyTable(pcOther.table, table, tableSize);
}

int* CTable::operator+(CTable &pcOther) {
    int* resultTable = new int[tableSize + pcOther.tableSize];
    copyTable(table, resultTable, tableSize);
    copyTable(pcOther.table, resultTable, tableSize, pcOther.tableSize);
    return resultTable;
}

void CTable::print()
{
    for(int i = 0; i < tableSize; i++)
    {
        std::cout << table[i] << " ";
    }
    std::cout << "\n";
}

void CTable::setNewValueAt(int offset, int newVal)
{
    if(offset >= tableSize || offset < 0)
    {
        std::cout << "Wrong offset value";
    }
    else
    {
        table[offset] = newVal;
    }
}

void CTable::setTable(int *table, int tableSize) {
    this->table = table;
    this->tableSize = tableSize;
}








