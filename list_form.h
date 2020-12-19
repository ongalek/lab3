#pragma once
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/spinbox.hpp>
#include <string>
#include <nana/gui/widgets/listbox.hpp>
class List_form
{
public:
	void run();
	List_form();
private:
	nana::form fm2;
	nana::listbox container;
};