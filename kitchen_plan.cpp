#include "kitchen_plan.h"

bool kitchen_plan::good_plan()
{
    for (int i = 0; i < appliances.get_size(); i++)
    {
        if (!appliances[i]->can_i_stand_here(appliances, i))
            return false;
    }
    return true;
}

void kitchen_plan::readfile(std::string A)
{
	for (int i=0; i < appliances.get_size(); i++)
	{
		delete appliances[i];
	}
	appliances.clear();
	std::ifstream fin;
	fin.open(A);
	char a;
	while (fin >> a)
	{
		if (a == '0')
		{
			technic* A = new technic();
			fin >> *A;
			appliances.push_back(A);
		}
		if (a == '1')
		{
			kitchen_cabinet* A = new kitchen_cabinet();
			fin >> *A;
			appliances.push_back(A);
		}
	}
	fin.close();

}


void kitchen_plan::writedown(std::string A)
{
	std::ofstream out;
	out.open(A);
	{

		for (int i = 0; i < appliances.get_size(); i++)
		{
			out << appliances[i]->get_type() << ' ';
			out << appliances[i]->get_name_size() << ' ';
			out << *appliances[i] << '\n';
		}

	}
	out.close();
}

kitchen_vector<rectangle*>&kitchen_plan::get_vector()
{
	return appliances;

}
