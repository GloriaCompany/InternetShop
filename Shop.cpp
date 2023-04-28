#include "Shop.h"

std::deque<Product>Shop::getProducts() { return this->products; }

void Shop::setProducts(std::deque<Product>& products) { this->products = products; }