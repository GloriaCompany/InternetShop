#include "Customer.h"
#include <iostream>

Customer::Customer(int _id, int _role, std::string _login, std::string _password)
	: User(_id, _role, _login, _password) {}

std::deque<Order> Customer::getOrders() { return this->orders; }
void Customer::setOrders(Order& order) { this->orders.push_back(order); }

void Customer::showInfoProduct(int id)
{
	for (auto& product : shop.getProducts())
	{
		if (product.getId() == id)
		{
			std::cout << "\n����� ��������: " << product.getName()
				<< "\n������� ��������: " << product.getCost()
				<< "\n�������: " << product.getArticle() << '\n';
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
			std::cout << "\n����� ��������: " << product.getName()
				<< "\n������� ��������: " << product.getCost()
				<< "\n�������: " << product.getArticle() << '\n';
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
		std::cout << "����� � ������� ���� ��������.\n";
	}
	else {
		std::cout << "������ ��� �������� � �������\n";
		for (auto& product : shop.getProducts()) {
			std::cout << "ID: " << product.getId()
				<< "\n����� ��������: " << product.getName()
				<< "\n������� ��������: " << product.getCost()
				<< "\n�������: " << product.getArticle() << '\n';
		}
	}
}

void Customer::showInfoProductByName(std::string productName)
{
	if (shop.getProducts().empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	}
	else {
		for (auto& product : shop.getProducts()) {
			if (product.getName() == productName) {
				std::cout << "������� � ��'�� " << productName << " ������ �������.\n"
					<< "���������� ��� ��������� �������:\n"
					<< "ID: " << product.getId()
					<< "\n����� ��������: " << product.getName()
					<< "\n������� ��������: " << product.getCost()
					<< "\n�������: " << product.getArticle() << '\n';
			}
		}
	}
}

void Customer::showInfoProductByArticle(std::string article)
{
	if (shop.getProducts().empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	}
	else {
		for (auto& product : shop.getProducts()) {
			if (product.getName() == article) {
				std::cout << "������� � �������� " << article << " ������ �������.\n"
					<< "���������� ��� ��������� �������:\n"
					<< "ID: " << product.getId()
					<< "\n����� ��������: " << product.getName()
					<< "\n������� ��������: " << product.getCost()
					<< "\n�������: " << product.getArticle() << '\n';
			}
		}
	}
}