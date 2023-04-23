#pragma once
#include <deque>
#include "Product.h"
class Order
{
private:
	int id;
	std::deque<Product> products;
	double totalAmount;
public:
	int getId();
	std::deque<Product> getProducts();
	double getTotalAmount();
	
	void setId(int id);
	void setProducts(std::deque<Product> products);
};

