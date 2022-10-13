#pragma once

#include "To_Do_List.h"

enum options
{
	_add_task = 1,
	_complete_task = 2,
	_show_undone_tasks = 3,
	_show_completed_tasks = 4,
	_delete_undone_task = 5,
	_delete_completed_task = 6,
	_delete_all_tasks = 7,
	_quit = 8
};

class Menu
{
private:
public:
	Menu();
	void show_menu();
	void pause_and_cleare();
	~Menu();
};

