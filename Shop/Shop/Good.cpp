#include "Good.h"

Good::Good() : id{ 0 }, name{ " " }, price{ 0.0 }, quantity{ 0 }
{
}

Good::Good(size_t id, std::string name, double price, size_t quantity) : Good()
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

size_t Good::get_id()
{
    return id;
}

std::string Good::get_name()
{
    return name;
}

double Good::get_price()
{
    return price;
}

size_t Good::get_quantity()
{
    return quantity;
}

Good::~Good()
{
}

std::ofstream& operator<<(std::ofstream& os, Good& good)
{
    os << good.id << " " << good.name << " " << good.price << " " << good.quantity << std::endl;
    return os;
}

std::ifstream& operator>>(std::ifstream& is, Good& good)
{
    is >> good.id >> good.name >> good.price >> good.quantity;
    return is;
}