#pragma once
#include "list_form.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include "GUI.h"
#include "kitchen_plan.h"
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/spinbox.hpp>
#include <string>
#include <nana/gui/widgets/listbox.hpp>
#include <nana/gui/widgets/label.hpp>
#include "kitchen_plan.h"
#include <nana/gui/filebox.hpp>
#include "Trie.h"

class main_form 
{
public:
	void run();
	main_form();
	void makelist();
	void show_descending();
private:
	nana::form fm;
	nana::button check_button;
	nana::button edit_button;
	nana::textbox fm_text;
	nana::spinbox del_box;
	nana::button load_button;
	bstree<int> A2;
	nana::listbox container;
	nana::filebox picker;
	nana::button save_button;
	nana::button add_button;
	nana::textbox textbox1;
	nana::textbox textbox2;
	nana::textbox textbox3;
	nana::textbox textbox4;
	nana::label label1;
	nana::label label2;
	nana::label label3;
	nana::label label4;


};