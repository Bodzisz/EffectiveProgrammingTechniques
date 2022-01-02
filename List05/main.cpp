#include <iostream>
#include "MySmartPointer.h"

int main()
{
    MySmartPointer<int> number(new int(5));
    std::cout << *number << std::endl;


    return 0;
}
