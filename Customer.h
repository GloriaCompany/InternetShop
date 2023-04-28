#pragma once
#include "User.h"
#include "Order.h"
#include "Shop.h"
#include <deque>

class Customer : public User
{
private:
	Shop shop;
	std::deque<Order> orders;
public:
	Customer(int _id, int _role, std::string _login, std::string _password);

	std::deque<Order> getOrders();
	void setOrders(Order& order);

	void showInfoProduct(int id);
	void buyProduct(Order order);
	void showAllOrders();
	void cancelOrder(int id);

	void showAllProducts();
	void showInfoProductByName(std::string productName);
	void showInfoProductByArticle(std::string article);
};