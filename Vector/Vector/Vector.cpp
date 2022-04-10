#include <iostream>
#include "MyVector.h"
#include <string.h>

int main()
{
    MyVector<std::string> myvector;
    std::cin >> myvector;
    std::cout << myvector;
    std::cout << myvector[1];
}
