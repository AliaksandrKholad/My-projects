#include "Task.h"

Task::Task() : task_text{ " " }, is_completed{ false }
{
}

Task::Task(std::string task_text) : Task()
{
	this->task_text = task_text;
}

std::string Task::get_task_text() const
{
	return task_text;
}

bool Task::get_is_completed() const
{
	return is_completed;
}

void Task::set_is_completed(bool & _is_completed)
{
	is_completed = _is_completed;
}

Task::~Task()
{
}

std::ostream& operator<<(std::ostream& os, const Task& task)
{
	os << task.task_text << " " << task.is_completed;
	return os;
}

std::istream& operator>>(std::istream& is, Task& task)
{
	is >> task.task_text >> task.is_completed;
	return is;
}