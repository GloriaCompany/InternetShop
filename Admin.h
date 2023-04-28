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
	Admin(int _id, int _role, std::string _login, std::string _password);

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
	void showInfoProductByName(std::string productName);
	void showInfoProductByArticle(std::string article);
};