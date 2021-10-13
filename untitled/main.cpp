#include <iostream>

#define ASSERT(x) { if(!(x)) { std::cout << "Assertion failed! Line: " << __LINE__; __debugbreak(); }; }

void v_alloc_table_add_5(int iSize)
{
//    ASSERT(iSize > 0);

    int* p_array = new int[iSize];

    for(int i = 0; i < iSize; i++)
        p_array[i] = i + 5;

    for(int i = 0; i < iSize; i++)
        std::cout << p_array[i] << '\n';

    delete[] p_array;
}

bool b_alloc_table_2_dim(int** pi_table, int iSizeX, int iSizeY)
{
    pi_table = new int*[iSizeY];

    for(int i = 0; i < iSizeY; i++)
        pi_table[i] = new int[iSizeX];

//    if(pi_table == nullptr)
//        return false;

    for(int i = 0; i < iSizeY; i++)
    {
        for(int j = 0; j < iSizeX; j++)
        {
            std::cout << pi_table[i][j];
        }

        std::cout << '\n';
    }

    return true;
}

bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY)
{
//    if(piTable == nullptr || iSizeY <= 0)
//        return false;

    for(int i = 0; i < iSizeY; i++)
    {
        delete[] piTable[i];
    }

    delete[] piTable;

    return true;
}

int main()
{
    int** table;

    v_alloc_table_add_5(15);

    std::cout << b_alloc_table_2_dim(table, 4, 7);

    std::cout << b_dealloc_table_2_dim(table, 4, 7);

    return 0;
}

