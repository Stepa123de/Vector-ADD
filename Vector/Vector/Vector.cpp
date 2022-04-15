#include <iostream>
#include "MyVector.h"
#include <string.h>

int main()
{
    MyVector<int> myvector, myvector1;
    std::cin >> myvector;
    std::cin >> myvector1;
    std::cout << myvector << " "<<myvector.size() << "\n";
    std::cout << myvector1 << " " << myvector1.size() << "\n";

    //myvector.Add(5+2);
    //std::cout << myvector << " " << myvector.size() << "\n";
    
    //MyVector<int> myvector2 = myvector + myvector1;
    std::cout << myvector + myvector1;

  // std::cout << mvanswer;
}
