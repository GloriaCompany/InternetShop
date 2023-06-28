#pragma once
#include <string>
#include <deque>

class Product
{
private:
	int id;
	std::wstring name;
	std::wstring article;
	double cost;
public:
	Product(int _id, std::wstring _name, std::wstring _article, double _cost);

	int getId();
	std::wstring getName();
	std::wstring getArticle();
	double getCost();

	void setId(int id);
	void setName(std::wstring name);
	void setArticle(std::wstring article);
	void setCost(double cost);
};

