#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include "GUI.h"
#include "kitchen_plan.h"
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/spinbox.hpp>
#include <string>
#include <nana/gui/widgets/listbox.hpp>


GUI::GUI()
{
}

//void GUI::mainform()
//{
//	nana::form fm(nullptr,{500, 500}, {});
//	nana::button button(fm, "let's check plan");
//	nana::button loadbutton(fm, "edit collection");
//	nana::textbox fmtext(fm);
//	nana::spinbox delbox(fm);
//	std::ifstream fin("layout.txt");
//	fm.div(std::string((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>()));
//	fin.close();
//	fm["button"] << button;
//	fm["textbox"] << fmtext;
//	fm["loadbutton"] << loadbutton;
//	fm["deletecouner"] << delbox;
//	fm.show();
//	loadbutton.events().click([&]
//	{
//		collectionform();
//	});
//	button.events().click([]
//	{
//		kitchen_plan a2;
//		a2.readfile();
//		nana::msgbox message;
//		if (a2.good_plan())
//		{
//			message << "all good";
//			message.show();
//		}
//		else
//		{
//			message << "your kitchen plan is shit";
//			message.show();
//		}
//		a2.writedown();
//	});
//	fm.collocate();
//	nana::exec();
//}
//
//void gui::collectionform()
//{
//	nana::form fm2(nullptr, { 500, 500 }, {});
//	nana::listbox container(fm2);
//	std::ifstream fin("layout2.txt");
//	fm2.div(std::string((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>()));
//	fm2["listbox"] << container;
//	fin.close();
//	fm2.collocate();
//	fm2.show();
//	container.append_header("type");
//	container.append_header("material/name");
//	container.append_header("size");
//	container.append_header("position");
//	auto cat = container.at(0);
//	cat.append({"1231132132", "12321132", "123312132", "12312"});
//	container.auto_draw(true);
//	nana::exec();
//
//}
