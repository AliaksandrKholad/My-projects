#include "Menu.h"

Menu::Menu()
{
}

void Menu::show_menu()
{
	To_Do_List my_list;
	Menu menu;
	while (true) {
		std::cout << std::endl << " To do list options: " << std::endl << std::endl;
		std::cout << "  1) add task" << std::endl;
		std::cout << "  2) complete task" << std::endl;
		std::cout << "  3) show undone tasks" << std::endl;
		std::cout << "  4) show completed tasks" << std::endl;
		std::cout << "  5) delete undone task" << std::endl;
		std::cout << "  6) delete completed task" << std::endl;
		std::cout << "  7) delete all tasks" << std::endl;
		std::cout << "  8) quit" << std::endl << std::endl;
		size_t option;
		std::cout << " Select option and type it's number: ";
		my_list.is_number(option);
		if (option == _add_task)
		{
			my_list.add_task();
			menu.pause_and_cleare();
			continue;
		}
		else if (option == _complete_task)
		{
			std::string path = my_list.get_undone_tasks_file_path();
			my_list.show_tasks(path);
			my_list.complete_task();
			menu.pause_and_cleare();
			continue;
		}
		else if (option == _show_undone_tasks)
		{
			std::string path = my_list.get_undone_tasks_file_path();
			my_list.show_tasks(path);
			std::cout << std::endl << std::endl;
			menu.pause_and_cleare();
			continue;
		}
		else if (option == _show_completed_tasks)
		{
			std::string path = my_list.get_completed_tasks_file_path();
			my_list.show_tasks(path);
			std::cout << std::endl << std::endl;
			menu.pause_and_cleare();
			continue;
		}
		else if (option == _delete_undone_task)
		{
			std::string path = my_list.get_undone_tasks_file_path();
			my_list.show_tasks(path);
			my_list.delete_task(path);
			std::cout << std::endl;
			menu.pause_and_cleare();
			continue;
		}
		else if (option == _delete_completed_task)
		{
			std::string path = my_list.get_completed_tasks_file_path();
			my_list.show_tasks(path);
			my_list.delete_task(path);
			std::cout << std::endl;
			menu.pause_and_cleare();
			continue;
		}
		else if (option == _delete_all_tasks)
		{
			my_list.delete_all_tasks();
			menu.pause_and_cleare();
			continue;
		}
		else if (option == _quit)
		{
			std::cout << std::endl << " Thanks for using To Do List, have a good day!" << std::endl;
			break;
		}
	}
}

void Menu::pause_and_cleare()
{
	system("pause");
	system("cls");
}

Menu::~Menu()
{
}