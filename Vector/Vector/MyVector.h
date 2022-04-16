#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

# define TRUE_PI 3.14159265358979323846 



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

	double sum();

public:
	MyVector(std::initializer_list<T> l);
	MyVector(T* array,size_t size);
	MyVector(const MyVector<T>& myvector);
	MyVector(T elem);
	MyVector();

	~MyVector();

	void Add(T object);

	size_t size();

	T& operator[](const size_t i)const;

	MyVector<T>& operator=(const MyVector<T> &myVector);
	
	MyVector<T> operator+(const MyVector<T> &myvector)const;

	MyVector<T> operator-(const MyVector<T> &myvector)const;

	MyVector<T> operator*(const MyVector<T> &myvector)const;

	MyVector<T> operator*(const int num)const;

	MyVector<T> operator/(const MyVector<T> &myvector)const;

	double scal(MyVector<T> &myVector);

	double len();

	double angle(MyVector<T> &myvector);
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
inline std::ostream& operator<<(std::ostream& os,const MyVector<T>& myvector) 
{
	for (size_t i = 0; i < myvector._real; i++)
	{
		os << myvector[i] << " ";
	}
	return os;
}

template<class T>
inline void MyVector<T>::MemoryAdd()
{
	//if (_size == 0) _size = 1;
	
	T* array = new T[_real];

	for (size_t i = 0; i < _real;i++) array[i] = _array[i];

	_size *= 2;

	_array = new T[_size];

	for (size_t i = 0; i < _real;i++) _array[i] = array[i];
	//_array = (T*)realloc(_array, _size * sizeof(T));
}

template<class T>
inline MyVector<T>::~MyVector()
{
	delete [] _array;
}

template<class T>
inline double MyVector<T>::sum()
{
	double d = 0;

	for (size_t i = 0; i < _real; i++)
	{
		d += _array[i];
	}

	return d;
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
inline MyVector<T>::MyVector(const MyVector<T>& myvector)
{
	_size = myvector._size;
	_real = myvector._real;
	_array = new T[_size];

	for (size_t i = 0; i < _real; i++) 
	{
		_array[i] = myvector[i];
	}

	

}

template<class T>
inline MyVector<T>::MyVector(T elem)
{
	_real = 0;
	_size = 1;
	_array = new T[_size];

	Add(elem);
}

template<class T>
inline MyVector<T>::MyVector()
{
	_size = 1;
	_real = 0;

	_array = new T[_size];

}

template<class T>
inline void MyVector<T>::Add(const T  object)
{
	if (_size == _real) 
	{
		MemoryAdd();
	}

	_array[_real] = object;

	_real++;
}

template<class T>
inline size_t MyVector<T>::size() //const
{
	return _real;
}

template<class T>
inline T& MyVector<T>::operator[](const size_t i) const
{
	assert(i < _size);
	return _array[i];
}

template<class T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector<T> &myVector)
{
	_size = myVector._size;
	_real = myVector._real;
	_array = new T[_size];

	for (size_t i = 0; i < _real; i++) 
	{
		_array[i] = myVector._array[i];
	}

	return *this;
}

template<class T>
inline MyVector<T> MyVector<T>::operator+(const MyVector<T> &myvector) const
{
	assert(!(_real != myvector._real));

	MyVector<T> plus;

	for (size_t i = 0; i < _real; i += 1)
	{
		T elem = _array[i] + myvector[i];
		plus.Add(elem);

	}

	return plus;

}

template<class T>
inline MyVector<T> MyVector<T>::operator-(const MyVector<T> &myvector) const
{
	assert(!(_real != myvector._real));

	MyVector<T> plus;

	for (size_t i = 0; i < _real; i += 1)
	{
		T elem = _array[i] - myvector[i];
		plus.Add(elem);

	}

	return plus;
}

template<class T>
inline MyVector<T> MyVector<T>::operator*(const MyVector<T> &myvector) const
{
	size_t size = _real;
	if (_real != myvector._real) 
	{
		size = std::min(_real, myvector._real);
		std::cout << "Size Vector A != Size Vector B, min size = " << size << " will be used!";
	}

	MyVector<T> plus;

	for (size_t i = 0; i < size; i += 1)
	{
		T elem = _array[i] * myvector[i];
		plus.Add(elem);

	}

	return plus;
}

template<class T>
inline MyVector<T> MyVector<T>::operator*(const int num) const
{
	MyVector<T> plus;

	for (size_t i = 0; i < _real; i += 1)
	{
		T elem = _array[i]*num;
		plus.Add(elem);

	}

	return plus;
}

template<class T>
inline MyVector<T> MyVector<T>::operator/(const MyVector<T> &myvector) const
{
	assert(!(_real != myvector._real));

	MyVector<T> plus;

	for (size_t i = 0; i < _real; i += 1)
	{
		T elem = _array[i] / myvector[i];
		plus.Add(elem);

	}

	return plus;
}

template<class T>
inline double MyVector<T>::scal(MyVector<T> &myVector)
{
	return (myVector * (*this)).sum();
}

template<class T>
inline double MyVector<T>::len()
{
	double back=0;

	for (int i = 0; i < _real; i++) 
	{
		back += _array[i] * _array[i];
	}

	back = sqrt(back);

	return back;
}

template<class T>
inline double MyVector<T>::angle(MyVector<T> &myVector)
{
	double myscal,a, b, cos,ans;


	myscal = scal(myVector);
	a = this->len();
	b = myVector.len();
	cos = myscal /(a*b);
	
	ans = acos(cos) * 180.0 / TRUE_PI;

	return ans;
}