#pragma once

#include "Task.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <exception>

class To_Do_List
{
private:
	std::string undone_tasks_file_path = "undone_tasks.txt";
	std::string completed_tasks_file_path = "completed_tasks.txt";
	std::vector<Task> undone_tasks;
	std::vector<Task> completed_tasks;
	std::vector<Task> all_tasks;
public:
	std::string get_undone_tasks_file_path();
	std::string get_completed_tasks_file_path();
	void is_number(size_t&);
	void add_task();
	void complete_task();
	void show_tasks(std::string&);
	void delete_task(std::string&);
	void delete_all_tasks();
};