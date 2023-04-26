#include "User.h"
#include "Customer.h"
#include <deque>

class Admin : public User
{
private:
	std::deque<Customer> shopCustomers;
	std::deque<Product> shopProducts;
	std::deque<Order> shopOrders;
public:
	Admin(int _id, int _role, std::string _login, std::string _password);

	// Отримання інформації з магазину
	void setCustomersForAdmin(const std::deque<Customer>& customers);
	void setProductsForAdmin(const std::deque<Product>& products);
	void setOrdersForAdmin(const std::deque<Order>& orders);

	// Операції
	void addCustomer(Customer& newCustomer);
	void editCustomer(int customerID);
	void delCustomer(int customerID);
	void addProduct(Product& newProduct);
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