#pragma once
#include "rectangle.h"
#include "kitchen_vector.h"
#include <string>
#include "tech.h"
#include "kitchen_cabinet.h"
class kitchen_plan
{
private:
	kitchen_vector <rectangle*> appliances;
public:
	bool good_plan();
	kitchen_plan(const kitchen_vector <rectangle*>& app)
	{
		appliances = app;
	}
	kitchen_plan()
	{

	}
	void readfile(std::string A);
	void writedown(std::string A);
	kitchen_vector<rectangle*>& get_vector();

};
