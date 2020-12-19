#pragma once
#include <cassert>
#include <fstream>



template <typename T> 
class kitchen_vector
{
private:
	int size;
	T *start;
	int capacity;
public:
	kitchen_vector(int A)
	{
		size = A;
		capacity = size * 2;
		start = new T[capacity];
	}
	kitchen_vector()
	{
		start = 0;
		size = 0;
		capacity = 0;
	}
	kitchen_vector(const kitchen_vector& a)
	{
		capacity = a.capacity;
		size = a.size;
		start = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			start[i] = a.start[i];
		}
	}
	kitchen_vector& operator=(const kitchen_vector& a) 
	{
		capacity = a.capacity;
		size = a.size;
		delete[] start;
		start = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			start[i] = a.start[i];
		}
		return *this;
	}
	void push_back(const T& a)
	{
		
		if (size >= capacity)
		{
			capacity = capacity*2 + 1;
			T* new_start = new T[capacity];
			for (int i = 0; i < capacity/2; i++)
			{
				new_start[i] = start[i];
			}
			delete[] start;
			start = new_start;
			
		}
		*(start + size) = a;
		size++;
	}
	~kitchen_vector() 
	{
		delete[] start;
	}
	T& operator[](int i) 
	{
		return start[i];
	}
	const T& operator[](int i) const
	{
		return start[i];
	}
	void clear()
	{
		size = 0;
	}
	int cnt() const
	{
		return size;
	}
	void erase(int i)
	{
		assert(i >= 0 && i < size);
		for (i; i < size - 1;i++)
			start[i + 1] = start[i];
		size--;
	}
	int get_size() const
	{
		return size;
	}

};
