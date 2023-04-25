#pragma once
#include <string>
#include <deque>

class Product
{
private:
	int id;
	std::string name;
	std::string article;
	double cost;
public:
	Product(int _id, std::string _name, std::string _article, double _cost);

	int getId();
	std::string getName();
	std::string getArticle();
	double getCost();

	void setId(int id);
	void setName(std::string name);
	void setArticle(std::string article);
	void setCost(double cost);
};

