#pragma once
#include "MyVector.h"
#include <iostream>

template<class T>
class SecondVector: public MyVector<T> 
{
public:
	SecondVector(std::initializer_list<T> l) : MyVector<T>(l) {};
	SecondVector(T* array, size_t size) : MyVector<T>(array, size) {};
	SecondVector(const MyVector<T>& myvector) : MyVector<T>(myvector) {};
	SecondVector(T elem) : MyVector<T>(elem) {};
	//MyVector();

	void say() 
	{
		std::cout << "I am new Class";
	};
};

