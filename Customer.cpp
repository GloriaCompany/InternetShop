#include "Customer.h"

Customer::Customer(int _id, int _role, std::string _login, std::string _password)
	: User(_id, _role, _login, _password) {}

void Customer::showInfoProduct()
{

}

void Customer::buyProduct()
{

}

void Customer::showAllOrders()
{

}

void Customer::cancelOrder()
{

}

void Customer::showAllProducts(std::deque<Product>& products)
{

}

void Customer::showInfoProductByName(std::deque<Product>& products, std::string productName)
{

}

void Customer::showInfoProductByArticle(std::deque<Product>& products, std::string article)
{

}