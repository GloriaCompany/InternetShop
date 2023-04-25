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

	void addCustomer(std::deque<Customer>& customers, Customer& newCustomer);
	void editCustomer(std::deque<Customer>& customers, int customerID);
	void delCustomer(std::deque<Customer>& customers, int customerID);
	void addProduct(std::deque<Product>& products, Product& newProduct);
	void editProduct(std::deque<Product>& products, int productID);
	void delProduct(std::deque<Product>& products, int productID);
	void showAllOrdersAllProducts(std::deque<Order>& orders);
	void showProductInfoById(std::deque<Product>& products, int productID);
	void delOrderProduct(std::deque<Order>& orders, int orderID);
	void delAllOrdersProduct(std::deque<Order>& orders, int productID);
	void delAllOrdersAllProducts(std::deque<Order>& orders);

	void showAllProducts(std::deque<Product>& products) override;
	void showInfoProductByName(std::deque<Product>& products, std::string productName) override;
	void showInfoProductByArticle(std::deque<Product>& products, std::string article) override;
};