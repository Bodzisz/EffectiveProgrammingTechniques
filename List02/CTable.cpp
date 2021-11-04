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
    this->table = new int[this->tableSize];
    fillWithZeros();
}

CTable::CTable(const CTable &pcOther)
{
    name = pcOther.name;
    tableSize = pcOther.tableSize;
    table = new int[tableSize];
    fillWithZeros();
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
        this->copyTable(table, newTable, iTableLen);
    }
    else
    {
        this->copyTable(table, newTable, tableSize);
    }

    delete [] table;

    tableSize = iTableLen;
    table = newTable;

    return true;

}

CTable *CTable::pcClone() {
    return new CTable(*this);
}

void CTable::copyTable(const int *copyFromTable, int *copyToTable, int startIndex, int copyFromTableSize)
{
    for(int i = 0; i < copyFromTableSize; i++)
    {
        copyToTable[startIndex + i] = copyFromTable[i];
    }
}

void CTable::copyTable(int *copyFromTable, int *copyToTable, int copyFromTableSize)
{
    copyTable(copyFromTable, copyToTable, 0, copyFromTableSize);
}

int CTable::getTableSize() const
{
    return tableSize;
}

//void CTable::operator=(CTable &pcOther) {
//    table = pcOther.table;
//    tableSize = pcOther.tableSize;
//}

CTable& CTable::operator=(CTable pcOther)
{
    if (this == &pcOther)
    {
        return *this;
    }

    delete [] table;
    tableSize = pcOther.tableSize;
    table = new int[tableSize];
    copyTable(pcOther.table, table, tableSize);
    return *this;
}


CTable CTable::operator+(CTable pcOther)
{
    CTable result(defaultName, tableSize + pcOther.tableSize);
    copyTable(table, result.table, tableSize);
    copyTable(pcOther.table, result.table, tableSize, pcOther.tableSize);
    return result;
}

CTable CTable::operator*=(int multiplicator) {
    for(int i = 0; i < tableSize; i++)
    {
        table[i] *= multiplicator;
    }
    return *this;
}

CTable CTable::operator*(int multiplicator)
{
    CTable result(*this);
    for(int i = 0; i < result.tableSize; i++)
    {
        result.table[i] *= multiplicator;
    }
    return result;
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

void CTable::fillWithZeros()
{
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = 0;
    }
}













