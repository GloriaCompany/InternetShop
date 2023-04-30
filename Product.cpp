#include "Product.h"

Product::Product(int _id, std::wstring _name, std::wstring _article, double _cost) : 
	id(_id), name(_name), article(_article), cost(_cost) {}

int Product::getId() { return this->id; }
std::wstring Product::getName() { return this->name; }
std::wstring Product::getArticle() { return this->article; }
double Product::getCost() { return this->cost; }

void Product::setId(int id) { this->id = id; }
void Product::setName(std::wstring name) { this->name = name; }
void Product::setArticle(std::wstring article) { this->article = article; }
void Product::setCost(double cost) { this->cost = cost; }
