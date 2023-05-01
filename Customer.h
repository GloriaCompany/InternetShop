#pragma once
#include "User.h"
#include "Order.h"
#include "Shop.h"
#include <deque>

class Customer : public User
{
private:
	Shop shop;
	std::deque<Product> products;
	std::deque<Order> orders;
public:
	Customer();
	Customer(int _id, int _role, std::wstring _login, std::wstring _password);

	std::deque<Order> getOrders();
	void setOrder(Order order);
	void setOrders(std::deque<Order>& orders);

	void showInfoProduct(int id);
	void buyProduct(int id);
	void showAllOrders();
	void cancelOrder(int id);

	void showAllProducts();
	void showInfoProductByName(std::wstring productName);
	void showInfoProductByArticle(std::wstring article);
};