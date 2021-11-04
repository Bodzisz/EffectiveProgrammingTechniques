//
// Created by bodzisz on 14/10/2021.
//

#ifndef LIST01_CTABLE_H
#define LIST01_CTABLE_H

#include <string>
#include <iostream>

const int defaultTableSize = 10;
const std::string defaultName = "defaultName";

class CTable {
private:
    std::string name;
    int *table;
    int tableSize;

public:
    CTable();
    CTable (std::string name, int tableSize);
    CTable (CTable &pcOther);
    ~CTable();

    CTable *pcClone();

    void print();
    void setNewValueAt(int offset, int newVal);

    void operator=(CTable &pcOther);
    //int* operator+(CTable &pcOther);
    CTable* operator+(CTable &pcOther);

    // setters
    void setName(std::string name);
    bool setNewSize(int tableSize);
    void setTable(int *table, int tableSize);

    // getters
    std::string getName() const;
    int* getTable() const;
    int getTableSize() const;

private:
     void copyTable(int *copyFromTable, int *copyToTable, int tableSize);
     void copyTable(const int *copyFromTable, int *copyToTable, int startIndex, int tableSize);
};


#endif //LIST01_CTABLE_H
