#include "Customer.h"
#include <iostream>

Customer::Customer() {}
Customer::~Customer() {}

Customer::Customer(size_t _id, int _role, std::wstring _login, std::wstring _password)
	: User(_id, _role, _login, _password) {}

std::deque<Order> Customer::getOrders() { return this->orders; }
void Customer::setOrders(std::deque<Order>& orders) { this->orders = orders; }

void Customer::showInfoProduct(int id)
{
	for (auto& product : shop.getProducts())
	{
		if (product.getId() == id)
		{
			std::wcout << L"\nНазва продукту: " << product.getName()
				<< L"\nВартість продукту: " << product.getCost()
				<< L"\nАртикль: " << product.getArticle() << '\n';
		}
	}
}

void Customer::buyProduct(int id)
{
	for (auto& product : shop.getProducts())
	{
		if (product.getId() == id)
		{
			products.push_back(product);

			for (auto& order : orders)
			{
				order.setProducts(products);
			}
		}
	}
}

void Customer::showAllOrders()
{
	for (auto& order : orders)
	{
		for (auto& product : order.getProducts())
		{
			std::wcout << L"\nНазва продукту: " << product.getName()
				<< L"\nВартість продукту: " << product.getCost()
				<< L"\nАртикль: " << product.getArticle() << '\n';
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

void Customer::showAllProducts()
{
	if (shop.getProducts().empty()) {
		std::wcout << L"Наразі у магазині немає продуктів.\n";
	}
	else {
		std::wcout << L"Список усіх продуктів у магазині\n";
		for (auto& product : shop.getProducts()) {
			std::wcout << L"ID: " << product.getId()
				<< L"\nНазва продукту: " << product.getName()
				<< L"\nВартість продукту: " << product.getCost()
				<< L"\nАртикль: " << product.getArticle() << '\n';
		}
	}
}

void Customer::showInfoProductByName(std::wstring productName)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"Наразі у магазині немає продуктів.\n";
	}
	else {
		for (auto& product : shop.getProducts()) {
			if (product.getName() == productName) {
				std::wcout << L"Продукт з ім'ям " << productName << L" успішно зайдено.\n"
					<< L"Інформація про знайдений продукт:\n"
					<< L"ID: " << product.getId()
					<< L"\nНазва продукту: " << product.getName()
					<< L"\nВартість продукту: " << product.getCost()
					<< L"\nАртикль: " << product.getArticle() << '\n';
			}
		}
	}
}

void Customer::showInfoProductByArticle(std::wstring article)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"Наразі у магазині немає продуктів.\n";
	}
	else {
		for (auto& product : shop.getProducts()) {
			if (product.getName() == article) {
				std::wcout << L"Продукт з артиклем " << article << L" успішно зайдено.\n"
					<< L"Інформація про знайдений продукт:\n"
					<< L"ID: " << product.getId()
					<< L"\nНазва продукту: " << product.getName()
					<< L"\nВартість продукту: " << product.getCost()
					<< L"\nАртикль: " << product.getArticle() << '\n';
			}
		}
	}
}