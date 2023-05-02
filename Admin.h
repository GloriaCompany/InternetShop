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
	std::deque<Product> products;
	std::deque<Order> orders;
	std::deque<Customer> customers;
public:
	Admin(int _id, int _role, std::wstring _login, std::wstring _password);

	std::deque<Customer> getCustomers();
	void setCustomers(const std::deque<Customer>& customers);

	// Операції
	void addCustomer(Customer newCustomer);
	void editCustomer(int customerID);
	void delCustomer(int customerID);
	void addProduct(Shop& shop, Product newProduct);
	void editProduct(Shop& shop, int productID);
	void delProduct(Shop& shop, int productID);
	void showAllOrders();
	void delOrderById(int orderID);
	void delAllOrdersProduct(int productID);
	void delAllOrdersAllProducts();

	void showAllProducts(Shop& shop);
	void showProductInfoById(Shop& shop, int productID);
	void showInfoProductByName(Shop& shop, std::wstring productName);
	void showInfoProductByArticle(Shop& shop, std::wstring article);
};