#include "Customer.h"
#include <iostream>

Customer::Customer() {}

Customer::Customer(int _id, int _role, std::wstring _login, std::wstring _password) : User(_id, _role, _login, _password) {}

Order Customer::getOrder() { return this->order; }
void Customer::setOrder(Order _order) { this->order = _order; }

void Customer::showInfoProduct(Shop& shop, int id)
{
	if (shop.getProducts().empty()) 
	{
		std::wcout << L"����� � ������� ���� ��������. ���������� ����-�����, �����.\n";
	} 
	else
	{
		for (auto& product : shop.getProducts())
		{
			if (product.getId() == id)
			{
				std::wcout << L"\n����� ��������: " << product.getName()
					<< L"\n������� ��������: " << product.getCost()
					<< L"\n�������: " << product.getArticle() << '\n';
			}
		}
	}
}

void Customer::buyProduct(Shop& shop, int id)
{
	std::deque<Product> orderProducts;
	orderProducts = this->order.getProducts();

	if (shop.getProducts().empty())
	{
		std::wcout << L"����� � ������� ���� ��������. ���������� ����-�����, �����.\n";
	}
	else
	{
		for (auto& product : shop.getProducts())
		{
			if (product.getId() == id)
			{
				orderProducts.push_back(product);
				this->order.setProducts(orderProducts);
			}
		}
	}
}

void Customer::showAllOrders()
{
	if (this->order.getProducts().empty())
	{
		std::wcout << L"����� � ��� ���� �������� ���������.\n";
	}
	else
	{
		for (auto& product : this->order.getProducts())
		{
			std::wcout << L"\n����� ��������: " << product.getName()
				<< L"\n������� ��������: " << product.getCost()
				<< L"\n�������: " << product.getArticle() << '\n';
		}
	}
}

void Customer::delOrder(int id)
{
	std::deque<Product> orderProducts;
	orderProducts = this->order.getProducts();

	if (this->order.getProducts().empty())
	{
		std::wcout << L"����� � ��� ���� �������� ���������.\n";
	}
	else
	{
		for (auto product = orderProducts.begin(); product != orderProducts.end(); ++product)
		{
			if (product->getId() == id)
			{
				orderProducts.erase(product);
				this->order.setProducts(orderProducts);
			}
		}
	}
}

void Customer::showAllProducts(Shop& shop)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"����� � ������� ���� ��������.\n";
	}
	else {
		std::wcout << L"������ ��� �������� � �������\n";
		for (auto& product : shop.getProducts()) {
			std::wcout << L"ID: " << product.getId()
				<< L"\n����� ��������: " << product.getName()
				<< L"\n������� ��������: " << product.getCost()
				<< L"\n�������: " << product.getArticle() << '\n';
		}
	}
}

void Customer::showInfoProductByName(Shop& shop, std::wstring productName)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"����� � ������� ���� ��������.\n";
	}
	else {
		for (auto& product : shop.getProducts()) {
			if (product.getName() == productName) {
				std::wcout << L"������� � ��'�� " << productName << L" ������ �������.\n"
					<< L"���������� ��� ��������� �������:\n"
					<< L"ID: " << product.getId()
					<< L"\n����� ��������: " << product.getName()
					<< L"\n������� ��������: " << product.getCost()
					<< L"\n�������: " << product.getArticle() << '\n';
			}
		}
	}
}

void Customer::showInfoProductByArticle(Shop& shop, std::wstring article)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"����� � ������� ���� ��������.\n";
	}
	else {
		for (auto& product : shop.getProducts()) {
			if (product.getName() == article) {
				std::wcout << L"������� � �������� " << article << L" ������ �������.\n"
					<< L"���������� ��� ��������� �������:\n"
					<< L"ID: " << product.getId()
					<< L"\n����� ��������: " << product.getName()
					<< L"\n������� ��������: " << product.getCost()
					<< L"\n�������: " << product.getArticle() << '\n';
			}
		}
	}
}