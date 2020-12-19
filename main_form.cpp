#include "main_forn.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/spinbox.hpp>
#include <string>
#include <nana/gui/widgets/listbox.hpp>
#include "list_form.h"
#include <nana/gui/filebox.hpp>
#include <filesystem>
#include <iostream>
#include "Trie.h"

void main_form::run()
{
	fm.show();
	edit_button.events().click([&]
		{
			container.clear();
			A2.clr();
			show_descending();
		});
	load_button.events().click([&]
	{
		container.clear();
		A2.clear();
		A2.clr();
		auto paths = picker.show();
		if (paths.empty())
		{
			std::cout << "Cancelled" << std::endl;
		}
		else
		{
			for (std::filesystem::path& p : paths )
				A2.rdf(p.string());
		}
		makelist();
		
	});
	save_button.events().click([&]
	{
		auto paths = picker.show();
		if (paths.empty())
		{
			std::cout << "Cancelled" << std::endl;
		}
		else
		{
			container.clear();
			A2.clr();
			for (std::filesystem::path& p : paths)
				A2.wrf(p.string());
		}	
	});
	check_button.events().click([&]
	{
		container.clear();
		A2.clr();
		makelist();
	});
	add_button.events().click([&]
	{
	if (textbox1.text() == "")
		return;
	else
	{
		nana::msgbox message;
		A2.add(std::stoi(textbox1.text()), textbox2.text());
		message << "node " << textbox1.text() << ' ' << textbox2.text() << " added";
		textbox1.select(1);
		textbox2.select(2);
		textbox1.del();
		textbox2.del();
		message.show();

	}
	});
	container.append_header("article");
	container.append_header("name");
	container.auto_draw(true);
	fm.collocate();
	nana::exec();
}

main_form::main_form() :
	fm(nullptr, { 500, 500 }, {}),
	check_button(fm, "show my trie"),
	edit_button(fm, "show descending"),
	load_button(fm, "load trie"),
	save_button(fm,"save trie"),
	container(fm),
	picker(nullptr, true),
	add_button(fm,"add to Trie"),
	label1(fm,"                                  Article                                   "),
	label2(fm, "                                 Name     "),
	textbox1(fm, ""),
	textbox2(fm, "")

{
	std::ifstream fin("layout.txt");
	fm.div(std::string((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>()));
	fin.close();
	fm["button"] << check_button;
	fm["textbox"] << container;
	fm["actionbut"] << edit_button << load_button << save_button << add_button; 
	fm["append"] << textbox1 << textbox2;
	fm["label"] << label1 << label2;
}
void main_form::makelist()
{	
	container.clear();
	auto cat = container.at(0);
	A2.clr();
	std::vector <std::pair<std::string, std::string>> a = A2.max_list(A2.get_tr());
	for (int i = 0; i < a.size(); i++)
	{   
		cat.append({ a[i].first,a[i].second });
	}
}

void main_form::show_descending()
{
	container.clear();
	auto cat = container.at(0);
	A2.clr();
	std::vector <std::pair<std::string, std::string>> a = A2.min_list(A2.get_tr());
	for (int i = 0; i < a.size(); i++)
	{
		cat.append({ a[i].first,a[i].second });
	}
}
