#pragma once

#include <string>
#include <fstream>

class Task
{
private:
	std::string task_text;
	bool is_completed;
	
public:
	Task();
	Task(std::string);
	std::string get_task_text() const;
	bool get_is_completed() const;
	void set_is_completed(bool &);
	friend std::ostream& operator<<(std::ostream&, const Task&);
	friend std::istream& operator>>(std::istream&, Task&);
	~Task();
};