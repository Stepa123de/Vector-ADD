#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

template<class T>
class MyVector
{
private:
	size_t _size, _real;
	T* _array;

	void MemoryAdd();

	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const MyVector<T>& myVector);

	template<class T>
	friend std::istream& operator>> (std::istream& is,  MyVector<T>& myVector);

	

public:
	MyVector(std::initializer_list<T> l);
	MyVector(T* array,size_t size);
	MyVector();

	~MyVector();

	void Add(T object);

	size_t size();

	T& operator[](size_t i)
	{
		assert(i < _size);
		return _array[i];
	}

};

template<class T>
inline std::istream& operator>>(std::istream& is, MyVector<T>& myVector)
{
	T elem;

	do 
	{
		is >> elem;
		myVector.Add(elem);
	} while (is&&is.get()!='\n');

	return is;
}

template<class T>
inline std::ostream& operator<<(std::ostream& os, MyVector<T>& myvector)
{
	for (size_t i = 0; i < myvector.size(); i++)
	{
		os << myvector[i] << " ";
	}
	return os;
}

template<class T>
inline void MyVector<T>::MemoryAdd()
{
	if (_size == 0) _size = 1;
	
	T* array = new T[_size];

	for (size_t i = 0; i < _size;i++) array[i] = _array[i];

	_size *= 2;

	_array = new T[_size];

	for (size_t i = 0; i < _size/2;i++) _array[i] = array[i];
	//_array = (T*)realloc(_array, _size * sizeof(T));
}

template<class T>
inline MyVector<T>::~MyVector()
{
	delete [] _array;
}

template<class T>
inline MyVector<T>::MyVector(std::initializer_list<T> l)
{
	_size = l.size();
	_real = 0;
	_array = new T[_size];

	int i = 0;
	for (T elem : l)
	{
		this -> Add(elem);
		
	}
}

template<class T>
inline MyVector<T>::MyVector(T* array, size_t size)
{
	_size = size;
	_real = size;
	_array = new T[_size];
	for (size_t i = 0; i < _real; i++)
	{
		_array[i] = array[i];
	}
}

template<class T>
inline MyVector<T>::MyVector()
{
	_size = _real = 0;

	_array = new T[0];

}

template<class T>
inline void MyVector<T>::Add(T object)
{
	if (_size == _real) 
	{
		MemoryAdd();
	}

	_array[_real] = object;

	_real++;
}

template<class T>
inline size_t MyVector<T>::size()
{
	return _real;
}


