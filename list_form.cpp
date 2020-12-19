#include "list_form.h"
#include "main_forn.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/spinbox.hpp>
#include <string>
#include <nana/gui/widgets/listbox.hpp>

void List_form::run()
{
	fm2.show();
	container.append_header("type");
	container.append_header("name");
	container.auto_draw(true);
	
}

List_form::List_form() :
	fm2(nullptr, { 500, 500 }, {}),
	container(fm2)
{
	std::ifstream fin("layout2.txt");
	fm2.div(std::string((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>()));
	fm2["listbox"] << container;
	fin.close();
	fm2.collocate();

}


