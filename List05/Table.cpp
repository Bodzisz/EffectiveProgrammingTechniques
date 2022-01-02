//
// Created by bodzisz on 14/10/2021.
//

#include "Table.h"


Table::Table()
{
    name = defaultName;
    tableSize = defaultTableSize;
    table = new int[tableSize];

    std::cout << "bezp:" + name << std::endl;
}

Table::Table(std::string sName, int tableSize)
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

Table::Table(const Table &pcOther)
{
    std::cout << std::endl << "COPY CONSTRUCTOR" << std::endl;
    name = pcOther.name;
    tableSize = pcOther.tableSize;
    table = new int[tableSize];
    fillWithZeros();
    this->copyTable(pcOther.table, table, pcOther.tableSize);
}

Table::Table(Table &&other)
{
    std::cout << std::endl << "MOVE CONSTRUCTOR" << std::endl;
    name = other.name;
    tableSize = other.tableSize;
    table = other.table;

    other.table = NULL;
    other.tableSize = 0;
    other.name = defaultName;
}

Table::~Table()
{
    delete [] table;
}

std::string Table::getName() const {
    return name;
}

int *Table::getTable() const {
    return table;
}

void Table::setName(std::string name) {
    this->name = name;
}

bool Table::setNewSize(int iTableLen) {
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

Table *Table::pcClone() {
    return new Table(*this);
}

void Table::copyTable(const int *copyFromTable, int *copyToTable, int startIndex, int copyFromTableSize)
{
    for(int i = 0; i < copyFromTableSize; i++)
    {
        copyToTable[startIndex + i] = copyFromTable[i];
    }
}

void Table::copyTable(int *copyFromTable, int *copyToTable, int copyFromTableSize)
{
    copyTable(copyFromTable, copyToTable, 0, copyFromTableSize);
}

int Table::getTableSize() const
{
    return tableSize;
}

//void Table::operator=(Table &pcOther) {
//    table = pcOther.table;
//    tableSize = pcOther.tableSize;
//}

Table& Table::operator=(Table pcOther)
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


Table Table::operator+(Table pcOther)
{
    Table result(defaultName, tableSize + pcOther.tableSize);
    copyTable(table, result.table, tableSize);
    copyTable(pcOther.table, result.table, tableSize, pcOther.tableSize);
    //return result;
    return std::move(result);
}

Table Table::operator*=(int multiplicator) {
    for(int i = 0; i < tableSize; i++)
    {
        table[i] *= multiplicator;
    }
    //return *this;
    return std::move(*this);
}

Table Table::operator*(int multiplicator)
{
    Table result(*this);
    for(int i = 0; i < result.tableSize; i++)
    {
        result.table[i] *= multiplicator;
    }
    //return result;
    return std::move(result);
}

void Table::print()
{
    for(int i = 0; i < tableSize; i++)
    {
        std::cout << table[i] << " ";
    }
    std::cout << "\n";
}

void Table::setNewValueAt(int offset, int newVal)
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

void Table::setTable(int *table, int tableSize) {
    this->table = table;
    this->tableSize = tableSize;
}

void Table::fillWithZeros()
{
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = 0;
    }
}

Table Table::operator=(Table &&other)
{
    std::cout << std::endl << "MOVE ASSIGNMENT OPERATOR" << std::endl;
    if(this != &other) {
        delete[] table;

        table = other.table;
        tableSize = other.tableSize;
        name = other.name;

        other.table = NULL;
        other.tableSize = 0;
        other.name = defaultName;
    }
    return *this;
}















