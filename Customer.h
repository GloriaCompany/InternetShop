#pragma once
#include "User.h"

class Customer : public User
{
private:

public:
	Customer(int _id, int _role, std::string _login, std::string _password);

	void findProduct();
	void showInfoProduct();
	void buyProduct();
	void showAllOrders();
	void cancelOrder();

	void showAllProducts() override;
	void showInfoProductByName() override;
	void showInfoProductByArticle() override;
};