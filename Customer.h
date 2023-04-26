#pragma once
#include "User.h"
#include "Order.h"
#include <deque>

class Customer : public User
{
private:
	std::deque<Order> orders;
public:
	Customer(int _id, int _role, std::string _login, std::string _password);

	std::deque<Order> getOrders();
	void setOrders(Order& order);

	void showInfoProduct(std::deque<Product>& products, int id);
	void buyProduct(Order order);
	void showAllOrders();
	void cancelOrder(int id);

	void showAllProducts(std::deque<Product>& products);
	void showInfoProductByName(std::deque<Product>& products, std::string productName);
	void showInfoProductByArticle(std::deque<Product>& products, std::string article);
};