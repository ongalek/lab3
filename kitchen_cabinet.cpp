#include <iostream>
#include <string>
#include "Kitchen_Cabinet.h"
#include "kitchen_vector.h"
#include <cmath>


std::string kitchen_cabinet::getmat() const
{

	return material;
}

int kitchen_cabinet::get_type() const
{
	return 1;
}

bool kitchen_cabinet::can_i_stand_here(const kitchen_vector<rectangle*>& plan, int j) const
{
	double R = sqrt((size.x * size.x + size.y * size.y  + size.z * size.z)) / 2;
	double center_x = coordinates.x + size.x / 2;
	double center_y = coordinates.y + size.y / 2;
	double center_z = coordinates.z + size.z / 2; 
	for (int i = 0; i < plan.get_size(); i++)
	{
		if (i == j)
			continue;
		if (plan[i]->get_type() == 1)
		{
			double R1 = sqrt((plan[i]->get_size().x * plan[i]->get_size().x + plan[i]->get_size().y * plan[i]->get_size().y + plan[i]->get_size().z * plan[i]->get_size().z)) / 2;
			double center1_x = plan[i]->get_coordinates().x + plan[i]->get_size().x / 2;
			double center1_y = plan[i]->get_coordinates().y + plan[i]->get_size().y / 2;
			double center1_z = plan[i]->get_coordinates().z + plan[i]->get_size().z / 2;
			double delcentx = center1_x - center_x;
			double delcenty = center1_y - center_y;
			double delcentz = center1_z - center_z;
			double delta = sqrt(delcentx * delcentx + delcenty * delcenty + delcentz * delcentz);
			double min = R + R1 + 2;
			if (delta < min)
				return false;
		}
	}
	return true;
}

std::string kitchen_cabinet::get_name_size() const
{
	return material;
}

void kitchen_cabinet::set_mat(std::string mat)
{
	material = mat;
}

std::istream& operator>>(std::istream& ins, kitchen_cabinet& elem)
{
	ins >> elem.material;
	ins >> elem.coordinates.x;
	ins >> elem.coordinates.y;
	ins >> elem.coordinates.z;
	ins >> elem.size.x;
	ins >> elem.size.y;
	ins >> elem.size.z;
	return ins;
}
std::ostream& operator<<(std::ostream& os, kitchen_cabinet& elem)
{
	
	os << elem.coordinates.x << "  ";
	os << elem.coordinates.y << "  ";
	os << elem.coordinates.z << "  ";
	os << elem.size.x << "  ";
	os << elem.size.y << "  ";
	os << elem.size.z << "  ";
	return os;

}
