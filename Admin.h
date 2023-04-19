#pragma once
#include "User.h"
class Admin : public User
{
private:

public:
	Admin(int _id, int _role, std::string _login, std::string _password);

	void addCustomer();
	void editCustomer();
	void delCustomer();
	void addProduct();
	void editProduct();
	void delProduct();
	void showAllOrdersAllProducts();
	void delOrderProduct();
	void delAllOrdersProduct();
	void delAllOderdersAllProducts();

	void showAllProducts() override;
	void showInfoProductByName() override;
	void showInfoProductByArticle() override;
};