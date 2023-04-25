#include "User.h"
#include "Customer.h"
#include "Product.h"
#include "Order.h"
#include <deque>

class Admin : public User
{
private:

public:
	Admin(int _id, int _role, std::string _login, std::string _password);

	void addCustomer(std::deque<Customer>& customers, const Customer& customer);
	void editCustomer(std::deque<Customer>& customers, const int customerID);
	void delCustomer(std::deque<Customer>& customers, const int customerID);
	void addProduct(std::deque<Product>& products, const Product& product);
	void editProduct(std::deque<Product>& products, const int productID);
	void delProduct(std::deque<Product>& products, const int productID);
	void showAllOrdersAllProducts(std::deque<Order>& orders);
	void delOrderProduct(std::deque<Product>& products, const int productID, const int orderID);
	void delAllOrdersProduct(std::deque<Product>& products, const int productID);
	void delAllOrdersAllProducts(std::deque<Order>& orders, std::deque<Product>& products);

	void showAllProducts(std::deque<Product>& products) override;
	void showInfoProductByName(std::deque<Product>& products, std::string productName) override;
	void showInfoProductByArticle(std::deque<Product>& products, std::string article) override;
};