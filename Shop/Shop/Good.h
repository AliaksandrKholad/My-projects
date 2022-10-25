#pragma once

#include <string>
#include <fstream>

class Good
{
private:
	size_t id;
	std::string name;
	double price;
	size_t quantity;
public:
	Good();
	Good(size_t, std::string, double, size_t);
	size_t get_id();
	std::string get_name();
	double get_price();
	size_t get_quantity();
	friend std::ofstream& operator<<(std::ofstream&, Good&);
	friend std::ifstream& operator>>(std::ifstream&, Good&);
	~Good();
};

