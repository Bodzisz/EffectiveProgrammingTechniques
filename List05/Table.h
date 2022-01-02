//
// Created by bodzisz on 14/10/2021.
//

#ifndef LIST05_Table_H
#define LIST05_Table_H

#include <string>
#include <iostream>

const int defaultTableSize = 10;
const std::string defaultName = "defaultName";

class Table {
private:
    std::string name;
    int *table;
    int tableSize;

public:
    Table();
    Table (std::string name, int tableSize);
    Table (const Table &pcOther);
    Table(Table &&other);
    ~Table();

    Table *pcClone();

    void print();
    void setNewValueAt(int offset, int newVal);

    Table& operator=(Table pcOther);
    Table operator+(Table pcOther);
    Table operator*(int multiplicator);
    Table operator*=(int multiplicator);
    Table operator=(Table &&other);

    // setters
    void setName(std::string name);
    bool setNewSize(int tableSize);
    void setTable(int *table, int tableSize);

    // getters
    std::string getName() const;
    int* getTable() const;
    int getTableSize() const;

private:
     void copyTable(int *copyFromTable, int *copyToTable, int copyFromTableSize);
     void copyTable(const int *copyFromTable, int *copyToTable, int startIndex, int copyFromTableSize);
     void fillWithZeros();
};


#endif //LIST05_TABLE_H
