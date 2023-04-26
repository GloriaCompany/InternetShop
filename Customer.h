#pragma once
#include "User.h"

class Customer : public User
{
private:

public:
	Customer() {};
	Customer(int _id, int _role, std::string _login, std::string _password);

	void showInfoProduct();
	void buyProduct();
	void showAllOrders();
	void cancelOrder();

	void showAllProducts(std::deque<Product>& products) override;
	void showInfoProductByName(std::deque<Product>& products, std::string productName) override;
	void showInfoProductByArticle(std::deque<Product>& products, std::string article) override;
};