#include "User.h"
#include "Customer.h"
#include "Shop.h"
#include <deque>

class Admin : public User
{
private:
	Shop shop;
	std::deque<Customer> customers;
public:
	Admin(int _id, int _role, std::wstring _login, std::wstring _password);

	std::deque<Customer> getCustomers();
	void setCustomers(const std::deque<Customer>& customers);

	// Операції
	void addCustomer(Customer newCustomer);
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