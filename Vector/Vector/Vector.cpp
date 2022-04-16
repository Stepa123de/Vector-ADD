#include <iostream>
#include "MyVector.h"
#include <string.h>
#include "SecondVector.h"

int main()
{
	MyVector<int> mv =  MyVector<int>(1);
	SecondVector<int> sv1 = { 1,2,3 };

	SecondVector<int> sv = SecondVector<int> ( sv1);
	std::cout << sv;

	sv.say();
}
