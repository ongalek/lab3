#pragma once
#include "vector.h"
#include <vector>
#include "kitchen_vector.h"
#include <iostream>
#include <string>


class rectangle  
{
public:
	friend std::istream& operator>>(std::istream& ins, rectangle& elem)
	{
		ins >> elem.coordinates.x;
		ins >> elem.coordinates.y;
		ins >> elem.coordinates.z;
		ins >> elem.size.x;
		ins >> elem.size.y;
		ins >> elem.size.z;
		return ins;

	}
	friend std::ostream& operator<<(std::ostream& os, rectangle& elem)
	{
		os << elem.coordinates.x << " "; 
		os << elem.coordinates.y << " ";
		os << elem.coordinates.z << " ";
		os << elem.size.x << " ";
		os << elem.size.y << " ";
		os << elem.size.z << " ";
		return os;
	}
	vector get_coordinates() const
	{
		return coordinates;
	}
	void set_coordinates(const vector& coor)
	{
		coordinates = coor;
	}
	void set_size(const vector& newsize)
	{
		if (newsize.x < 0 || newsize.y < 0 || newsize.z < 0)
		{
			size = { 1,1,1 };
		}
		else size = newsize;
	}
	vector get_size() const
	{
		return size;
	}
	rectangle()
	{
		size = { 0, 0, 0 };
		coordinates = { 0, 0, 0 };
	}
	rectangle(const rectangle& a) 
	{
		coordinates = a.coordinates;
		size = a.size;
	}
	virtual bool can_i_stand_here(const kitchen_vector<rectangle*> &plan, int i) const = 0;
	virtual int get_type() const = 0;
	virtual std::string get_name_size() const = 0;
protected:
	vector coordinates;
	vector size;
	
};