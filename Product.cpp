#include "Product.h"

Product::Product(int _id, std::string _name, double _cost) : id(_id), name(_name), cost(_cost) {}

int Product::getId() { return this->id; }
std::string Product::getName() { return this->name; }
double Product::getCost() { return this->cost; }

void Product::setId(int id) { this->id = id; }
void Product::setName(std::string name) { this->name = name; }
void Product::setCost(double cost) { this->cost = cost; }
