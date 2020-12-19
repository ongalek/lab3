#pragma once 
#include "kitchen_cabinet.h"
#include "tech.h"
#include "kitchen_plan.h"
#include "kitchen_vector.h"
void Assert()
{
	kitchen_cabinet IKEA("IKEA");
	kitchen_cabinet HOFF("HOFF");
	technic Microwave;
	HOFF.set_coordinates({ -30,-50,-12 });
	HOFF.set_size({ 2,2,2 });
	IKEA.set_coordinates({ 1, 2, 3 });
	IKEA.set_size({ -1, 1, 1 });
	Microwave.set_coordinates({ 10,10,0 });
	Microwave.set_size({ 1,1,1 });
	assert(IKEA.get_size().x >= 0 && IKEA.get_size().y >= 0 && IKEA.get_size().z >= 0);
	assert(IKEA.getmat() != "");
	rectangle* CAB1 = &IKEA;
	rectangle* CAB2 = &HOFF;
	rectangle* TECH1 = &Microwave;
	kitchen_vector<rectangle*> plan;
	plan.push_back(CAB1);
	plan.push_back(CAB2);
	plan.push_back(TECH1);
	kitchen_plan A1(plan);
	//assert(A1.good_plan());
	kitchen_plan A2; //если будете делать чтение файлов, уберите комментарий, при выполнении задачи программа выполнится без ошибок
	//A2.readfile();
	//assert(A2.good_plan());
	//A2.writedown();
	//plan.clear();
	//assert(plan.get_size() == 0);
	
	
}