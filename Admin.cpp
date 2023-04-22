#include "Admin.h"
#include "Customer.h"
#include <deque>
#include <array>
#include <iostream>

const std::array<char, 25> invalidSymbols = { ' ','!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','�','?' };

Admin::Admin(int _id, int _role, std::string _login, std::string _password)
	: User(_id, _role, _login, _password) {}

void Admin::addCustomer(std::deque<Customer>& customers, Customer& customer)
{
	customers.push_back(customer);
}

void Admin::editCustomer(std::deque<Customer>& customers, const int customerID)
{
	int userInput = 0;
	const int USER_CODE = 1, ADMIN_CODE = 2;
	const int MENU_MIN_SELECTION = 1, MENU_MAX_SELECTION = 2;
	const int LOGIN_MIN_SIZE = 5, LOGIN_MAX_SIZE = 15;
	const int PASSWORD_MIN_SIZE = 8, PASSWORD_MAX_SIZE = 15;
	std::string newLogin, newPassword;

	for (auto& customer : customers) {
		if (customer.getId() == customerID) {
			do {
				std::cout << "������ �������� ��� ����:\n1. ���� �������.\n2. ������ �������.\n3. �� ������������ ����.\n��� ����: ";
				std::cin >> userInput;
				if (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION) {
					std::cout << "����������� ����. �������� ������, ����-�����.\n";
				}
			} while (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION);

			switch (userInput) {
			case 1:
				while (true) {
					std::cout << "������ ����� ���� ��� ������� " << customers[customerID].getLogin() << ": ";
					std::cin >> newLogin;
					if (newLogin.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "���� ������ ��������� �������. �������� ������, ����-�����.\n";
					}
					else if (newLogin.size() < LOGIN_MIN_SIZE || newLogin.size() > LOGIN_MAX_SIZE) {
						std::cout << "̳������� ������� ����� - " << LOGIN_MIN_SIZE << " �������, ����������� ������� ����� - " << LOGIN_MAX_SIZE << " �������. �������� ������, ����-�����.\n";
					}
					else break;
				}
				customers[customerID].setLogin(newLogin);
				std::cout << "���� ������ ������. ��� ��� �����������:\n����: " << customers[customerID].getLogin() << "\n������: " << customers[customerID].getPassword() << "\n��� ���: " << customers[customerID].getRole();
				break;

			case 2:
				while (true) {
					std::cout << "������ ����� ������ ��� ������� " << customers[customerID].getLogin() << ": ";
					std::cin >> newPassword;
					if (newPassword.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "������ ������ ��������� �������. �������� ������, ����-�����.\n";
					}
					else if (newPassword.size() < PASSWORD_MIN_SIZE || newPassword.size() > PASSWORD_MAX_SIZE) {
						std::cout << "̳������� ������� ������ - " << PASSWORD_MIN_SIZE << " �������, ����������� ������� ������ - " << PASSWORD_MAX_SIZE << " �������. �������� ������, ����-�����.\n";
					}
					else break;
				}
				customers[customerID].setPassword(newPassword);
				std::cout << "������ ������ ������. ��� ��� �����������:\n����: " << customers[customerID].getLogin() << "\n������: " << customers[customerID].getPassword() << "\n��� ���: " << customers[customerID].getRole();
				break;

			case 3:
				userInput = 0;
				do {
					std::cout << "������ ���� ���� ����������� � ������:\n1. ����������.\n2. �����������.\n��� ����: ";
					std::cin >> userInput;
					if (userInput < USER_CODE || userInput > ADMIN_CODE) {
						std::cout << "����������� ����. �������� ������, ����-�����.\n";
					}
				} while (userInput < USER_CODE || userInput > ADMIN_CODE);

				switch (userInput) {
				case 1:
					customers[customerID].setRole(USER_CODE);
					std::cout << "���� ����������� ������ ������.\n";
					break;

				case 2: 
					customers[customerID].setRole(ADMIN_CODE);
					std::cout << "���� ����������� ������ ������.\n";
					break;
				}
				break;
			}
		}
	}
}

void Admin::delCustomer(std::deque<User*>& users, const int customerID)
{
	auto it = find_if(users.begin(), users.end(), [customerID](User* user) { return user->getId() == customerID; });
	if (it != users.end()) {
		if (dynamic_cast<Customer*>(*it)) {
			std::cout << "�������� � ID " << customerID << " ��� ���������.\n";
		}
		delete* it;
		users.erase(it);
	} else {
		std::cout << "������� � ID " << customerID << " �� ��������.\n";
	}
}

void Admin::addProduct(std::deque<Product>& products, const Product& product)
{

}

void Admin::editProduct(std::deque<Product>& products, const int productID)
{

}

void Admin::delProduct(std::deque<Product>& products, const int productID)
{

}

void Admin::showAllOrdersAllProducts(std::deque<Order>& orders, std::deque<Product>& products)
{

}

void Admin::delOrderProduct(std::deque<Order>& orders, const int productID)
{

}

void Admin::delAllOrdersProduct(std::deque<Order>& orders, const int productID)
{

}

void Admin::delAllOrdersAllProducts(std::deque<Order>& orders)
{

}

void Admin::showAllProducts(std::deque<Product>& products)
{

}

void Admin::showInfoProductByName(std::deque<Product>& products, std::string productName)
{

}

void Admin::showInfoProductByArticle(std::deque<Product>& products, std::string article)
{

}