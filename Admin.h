#include "User.h"
#include "Customer.h"
#include "Shop.h"
#include <iostream>
#include <limits>
#include <array>
#include <deque>

class Admin : public User
{
private:
	Shop shop;
	std::deque<User> users;
	std::deque<Product> products;
	std::deque<Order> orders;
public:
	Admin(int _id, int _role, std::wstring _login, std::wstring _password);

	std::deque<User> getUsers();
	void setUsers(const std::deque<User>& users);

	// Операції
	void addCustomer(User newCustomer);
	void editCustomer(int customerID);
	void delCustomer(int customerID);
	void addProduct(Product newProduct);
	void editProduct(int productID);
	void delProduct(int productID);
	void showAllOrdersAllProducts();
	void showProductInfoById(int productID);
	void delOrderProduct(int orderID);
	void delAllOrdersProduct(int productID);
	void delAllOrdersAllProducts();

	void showAllProducts();
	void showInfoProductByName(std::wstring productName);
	void showInfoProductByArticle(std::wstring article);
};