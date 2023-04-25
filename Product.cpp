#include "Product.h"

Product::Product(int _id, std::string _name, std::string _article, double _cost) : 
	id(_id), name(_name), article(_article), cost(_cost) {}

int Product::getId() { return this->id; }
std::string Product::getName() { return this->name; }
std::string Product::getArticle() { return this->article; }
double Product::getCost() { return this->cost; }

void Product::setId(int id) { this->id = id; }
void Product::setName(std::string name) { this->name = name; }
void Product::setArticle(std::string article) { this->article = article; }
void Product::setCost(double cost) { this->cost = cost; }
