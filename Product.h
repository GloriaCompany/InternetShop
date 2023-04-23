#pragma once
#include <string>
#include <deque>
#include "Order.h"

class Product
{
private:
	int id;
	std::string name;
	double cost;
public:
	Product(int _id, std::string _name, double _cost);

	int getId();
	std::string getName();
	double getCost();

	void setId(int id);
	void setName(std::string name);
	void setCost(double cost);
};

