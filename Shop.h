#pragma once
#include <deque>
#include "Product.h"
class Shop
{
private:
	std::deque<Product> products;
public:
	std::deque<Product> getProducts();

	void setProducts(std::deque<Product>& products);
};