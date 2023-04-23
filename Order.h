#pragma once
#include <deque>
#include "Product.h"

class Order
{
private:
	int id;
	std::deque<Product> products;
	double totalAmount;
	bool isActive;
public:
	int getId();
	std::deque<Product> getProducts();
	double getTotalAmount();
	bool getActive();
	
	void setId(int id);
	void setProducts(std::deque<Product>& products);
	void setActive(bool isActive);
};

