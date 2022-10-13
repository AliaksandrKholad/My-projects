#include "To_Do_List.h"

std::string To_Do_List::get_undone_tasks_file_path()
{
	return undone_tasks_file_path;
}

std::string To_Do_List::get_completed_tasks_file_path()
{
	return completed_tasks_file_path;
}

void To_Do_List::is_number(size_t& option) // check user input (is a number)
{
	if (!(std::cin >> option))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl << " There is no such an option, please try again" << std::endl;
	}
}

void To_Do_List::add_task()
{
	std::cout << std::endl << " Type your task: ";
	std::string task_text;
	char first_character{ task_text[0] };
	getline(std::cin, task_text);
	getline(std::cin, task_text); // data input
	std::string task_text_copy = task_text;
	char sps{ ' ' };
	for (size_t character{ 0 }; character < task_text.size(); ++character) // parsing input data
	{
		first_character = toupper(first_character);
		task_text[character] = tolower(task_text[character]);
		if (task_text[character] == sps)
		{
			++character;
			task_text[character] = toupper(task_text[character]);
		}
	}
	task_text.erase((remove(task_text.begin(), task_text.end(), ' ')), task_text.end()); // deleting all spaces
	Task task(task_text);
	std::ofstream write_undone_file_data(undone_tasks_file_path, std::ios::app);
	if (write_undone_file_data.is_open())
	{
		write_undone_file_data << task << std::endl;
		std::cout << std::endl << " Task \" " << task_text_copy << " \" was successfully added" << std::endl << std::endl;
	}
	write_undone_file_data.close();
}

void To_Do_List::complete_task()
{
	std::cout << std::endl << " Type task id you want to mark as completed: ";
	char id;
	std::cin >> id;
	if (isdigit(id))
	{
		size_t _id = static_cast<size_t>(id) - 48; // converting character to number
		Task undone_task;
		std::ifstream read_file_data(undone_tasks_file_path);
		while (true) // reading file with undone tasks
		{
			if (read_file_data.is_open())
			{
				read_file_data >> undone_task;
				if (read_file_data.eof())
				{
					break;
				}
				undone_tasks.push_back(undone_task); // adding undone tasks to undone tasks vector
			}
		}
		read_file_data.close();
		std::ofstream write_undone_file_data(undone_tasks_file_path);
		bool completed = true;
		if (_id >= 0 && _id < undone_tasks.size())
		{
			for (size_t task{ _id }; task <= _id; ++task) // changing task status and adding it to vector and then to file
			{
				if (_id == task)
				{
					undone_tasks[task].set_is_completed(completed); // changing task status
					completed_tasks.push_back(undone_tasks[task]); // adding task to completed tasks vector
					undone_tasks.erase(undone_tasks.begin() + task); // deleting undone task from undone tasks vector
					std::cout << std::endl << " Task with id " << id << " was successfully marked as completed" << std::endl << std::endl;
				}
			}
		}
		else
		{
			std::cout << std::endl << " There is no task with id " << id << std::endl << std::endl;
		}
		for (auto& undone_task : undone_tasks)
		{
			write_undone_file_data << undone_task << std::endl; // writing undone tasks to file
		}
		write_undone_file_data.close();
		undone_tasks.clear();
		std::ofstream wtite_completed_file_data(completed_tasks_file_path, std::ios::app);
		for (auto& completed_task : completed_tasks)
		{
			wtite_completed_file_data << completed_task << std::endl; // writing completed tasks to file
		}
		wtite_completed_file_data.close();
		completed_tasks.clear();
	}
	else
	{
		std::cout << std::endl << " " << id << " is not a number" << std::endl << std::endl;
	}
}

void To_Do_List::show_tasks(std::string &file_path)
{
	To_Do_List to_do_list;
	Task task;
	int task_id{ -1 };
	std::string task_text;
	std::ifstream read_file_data(file_path);
	if (read_file_data.is_open())
	{
		while (true) // reading tasks from file and console output them in a nice format
		{
			read_file_data >> task;
			if (read_file_data.eof())
			{
				break;
			}
			task_text = task.get_task_text();
			for (size_t character{ 1 }; character < task_text.size(); ++character)
			{
				if (isdigit(task_text[character]))
				{
					++character;
					if (isupper(task_text[character]))
					{
						task_text.insert(character, " ");
					}
					--character;
				}
				if (islower(task_text[character]))
				{
					++character;
					if (isdigit(task_text[character]))
					{
						task_text.insert(character, " ");
					}
					if (isupper(task_text[character]) )
					{
						task_text.insert(character, " ");
					}
					--character;
				}
			}
			++task_id;
			std::cout << std::endl << "  " << task_id << ") " << task_text;
		}
		std::cout << std::endl;
	}
	read_file_data.close();
}

void To_Do_List::delete_task(std::string &file_path)
{
	std::cout << std::endl << " Type task id you want to delete: ";
	char id;
	std::cin >> id;
	if (isdigit(id))
	{
		size_t _id = static_cast<size_t>(id) - 48; // converting character to number
		Task task;
		std::ifstream read_file_data(file_path);
		while (true) // reading tasks from file and adding them to all tasks vector
		{
			if (read_file_data.is_open())
			{
				read_file_data >> task;
				if (read_file_data.eof())
				{
					break;
				}
				all_tasks.push_back(task);
			}
		}
		read_file_data.close();
		if (_id >= 0 && _id < all_tasks.size())
		{
			all_tasks.erase(all_tasks.begin() + _id); // deleting task from all tasks vector
			std::cout << std::endl << " Task with id " << id << " was successfully deleted" << std::endl;
		}
		else
		{
			std::cout << std::endl << " There is no task with id " << id << std::endl;
		}
		std::ofstream write_file_data(file_path);
		for (auto& task : all_tasks)
		{
			write_file_data << task << std::endl; // writing tasks to file
		}
		write_file_data.close();
		all_tasks.clear();
	}
	else
	{
		std::cout << std::endl << " " << id << " is not a number" << std::endl;
	}
}

void To_Do_List::delete_all_tasks()
{
	std::ofstream delete_undone_file_data(undone_tasks_file_path, std::ios::trunc); // deleting all undone tasks
	std::ofstream delete_completed_file_data(completed_tasks_file_path, std::ios::trunc); // deleting all completed tasks
	if (delete_undone_file_data.is_open())
	{
		std::cout << std::endl << " All undone tasks were deleted" << std::endl;
	}
	if (delete_completed_file_data.is_open())
	{
		std::cout << std::endl << " All completed tasks were deleted" << std::endl << std::endl;
	}
	delete_undone_file_data.close();
	delete_completed_file_data.close();
}