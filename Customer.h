#pragma once
#include "User.h"
#include "Order.h"
#include "Shop.h"
#include <deque>

class Customer : public User
{
private:
	Order order;
public:
	Customer();
	Customer(int _id, int _role, std::wstring _login, std::wstring _password);
	Order getOrder();
	void setOrder(Order _order);

	void showInfoProduct(Shop& shop, int id);
	void buyProduct(Shop& shop, int id);
	void showAllOrders();
	void delOrder(int id);

	void showAllProducts(Shop& shop);
	void showInfoProductByName(Shop& shop, std::wstring productName);
	void showInfoProductByArticle(Shop& shop, std::wstring article);
};