#include "Customer.h"
#include <iostream>

Customer::Customer(int _id, int _role, std::string _login, std::string _password)
	: User(_id, _role, _login, _password) {}

std::deque<Order> Customer::getOrders() { return this->orders; }
void Customer::setOrders(Order& order) { this->orders.push_back(order); }

void Customer::showInfoProduct(std::deque<Product>& products, int id)
{
	for (auto& product : products)
	{
		if (product.getId() == id)
		{
			std::cout << "\nНазва продукту: " << product.getName()
				<< "\nВартість продукту: " << product.getCost()
				<< "\nАртикль: " << product.getArticle() << '\n';
		}
	}
}

void Customer::buyProduct(Order order)
{
	orders.push_back(order);
}

void Customer::showAllOrders()
{
	for (auto& order : orders)
	{
		for (auto& product : order.getProducts())
		{
			std::cout << "\nНазва продукту: " << product.getName()
				<< "\nВартість продукту: " << product.getCost()
				<< "\nАртикль: " << product.getArticle() << '\n';
		}
	}
}

void Customer::cancelOrder(int id)
{
	for (auto& order : orders)
	{
		if (order.getId() == id)
		{
			order.setActive(false);
		}
	}
}

void Customer::showAllProducts(std::deque<Product>& products)
{
	std::cout << "Список усіх продуктів у магазині\n";
	for (auto& product : products) {
		std::cout << "ID: " << product.getId()
			<< "\nНазва продукту: " << product.getName()
			<< "\nВартість продукту: " << product.getCost()
			<< "\nАртикль: " << product.getArticle() << '\n';
	}
}

void Customer::showInfoProductByName(std::deque<Product>& products, std::string productName)
{
	for (auto& product : products) {
		if (product.getName() == productName) {
			std::cout << "Продукт з іменем " << productName << " успішно зайдено.\n"
				<< "Інформація про знайдений продукт:\n"
				<< "ID: " << product.getId()
				<< "\nНазва продукту: " << product.getName()
				<< "\nВартість продукту: " << product.getCost()
				<< "\nАртикль: " << product.getArticle() << '\n';
		}
	}
}

void Customer::showInfoProductByArticle(std::deque<Product>& products, std::string article)
{
	for (auto& product : products) {
		if (product.getName() == article) {
			std::cout << "Продукт з артиклем " << article << " успішно зайдено.\n"
				<< "Інформація про знайдений продукт:\n"
				<< "ID: " << product.getId()
				<< "\nНазва продукту: " << product.getName()
				<< "\nВартість продукту: " << product.getCost()
				<< "\nАртикль: " << product.getArticle() << '\n';
		}
	}
}