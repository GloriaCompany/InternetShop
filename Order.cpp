#include "Order.h"

int Order::getId() { return this->id; }
std::deque<Product> Order::getProducts() { return this->products; }
double Order::getTotalAmount() { return this->totalAmount; }
bool Order::getActive() { return this->isActive; }

void Order::setId(int id) { this->id = id; }
void Order::setProducts(Product& product) { this->products.push_back(product); }
void Order::setActive(bool isActive) { this->isActive = isActive; }