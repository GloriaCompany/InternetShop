#include "Order.h"

int Order::getId() { return this->id; }
std::deque<Product> Order::getProducts() { return this->products; }
double Order::getTotalAmount() { return this->totalAmount; }
bool Order::getActive() { return this->isActive; }

void Order::setId(int id) { this->id = id; }
void Order::setProducts(std::deque<Product>& products) { this->products = products; }
void Order::setActive(bool isActive) { this->isActive = isActive; }