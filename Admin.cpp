#include "Admin.h"
#include "Customer.h"
#include "Product.h"
#include <deque>
#include <array>
#include <iostream>
#include <limits>

// ����� �������, �� ������ �����������
const std::array<char, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','�','?' };

Admin::Admin(int _id, int _role, std::string _login, std::string _password) : User(_id, _role, _login, _password) {}

// ������ �볺���
void Admin::addCustomer(std::deque<Customer>& customers, Customer& newCustomer)
{
	bool isExists = false;
    for (auto& customer : customers) {
        if (newCustomer.getId() == customer.getId()) {
			std::cout << "�������� � ����� ID ��� ����. �������� ������, ����-�����.\n";
			isExists = true;
            break;
        } else if (newCustomer.getLogin() == customer.getLogin()) {
			std::cout << "�������� � ����� ������ ��� ����. �������� ������, ����-�����.\n";
			isExists = true;
			break;
		}
    }
    if (!isExists) {
        customers.push_back(newCustomer);
    }
}

// ���������� ���������� ��� �볺���
void Admin::editCustomer(std::deque<Customer>& customers, int customerID)
{
	int userInput = 0;
	constexpr int USER_CODE = 1, ADMIN_CODE = 2;
	constexpr int MENU_MIN_SELECTION = 1, MENU_MAX_SELECTION = 2;
	constexpr int LOGIN_MIN_LENGTH = 5, LOGIN_MAX_LENGTH = 15;
	constexpr int PASSWORD_MIN_LENGTH = 8, PASSWORD_MAX_LENGTH = 15;
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
					std::cout << "������ ����� ���� ��� ������� " << customers.at(customerID).getLogin() << ": ";
					std::cin >> newLogin;
					if (newLogin.find(' ') != std::string::npos) {
						std::cout << "���� ������ ��������� �������. �������� ������, ����-�����.\n";
					}
					else if (newLogin.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "���� ������ ��������� �������. �������� ������, ����-�����.\n";
					}
					else if (newLogin.size() < LOGIN_MIN_LENGTH || newLogin.size() > LOGIN_MAX_LENGTH) {
						std::cout << "̳������� ������� ����� - " << LOGIN_MIN_LENGTH << " �������, ����������� ������� ����� - " << LOGIN_MAX_LENGTH << " �������. �������� ������, ����-�����.\n";
					}
					else break;
				}
				customers.at(customerID).setLogin(newLogin);
				std::cout << "���� ������ ������. ��� ��� �����������:\nID: " << customers.at(customerID).getId() << "\n����: " << customers.at(customerID).getLogin() << "\n������ : " << customers.at(customerID).getPassword() << "\n��� ��� : " << customers.at(customerID).getRole();
				break;

			case 2:
				while (true) {
					std::cout << "������ ����� ������ ��� ������� " << customers.at(customerID).getLogin() << ": ";
					std::cin >> newPassword;
					if (newLogin.find(' ') != std::string::npos) {
						std::cout << "������ ������ ��������� �������. �������� ������, ����-�����.\n";
					}
					else if (newPassword.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "������ ������ ��������� �������. �������� ������, ����-�����.\n";
					}
					else if (newPassword.size() < PASSWORD_MIN_LENGTH || newPassword.size() > PASSWORD_MAX_LENGTH) {
						std::cout << "̳������� ������� ������ - " << PASSWORD_MIN_LENGTH << " �������, ����������� ������� ������ - " << PASSWORD_MAX_LENGTH << " �������. �������� ������, ����-�����.\n";
					}
					else break;
				}
				customers.at(customerID).setPassword(newPassword);
				std::cout << "������ ������ ������. ��� ��� �����������:\nID: " << customers.at(customerID).getId() << "\n����: " << customers.at(customerID).getLogin() << "\n������: " << customers.at(customerID).getPassword() << "\n��� ���: " << customers.at(customerID).getRole();
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
					customers.at(customerID).setRole(USER_CODE);
					std::cout << "���� ����������� ������ ������.\n";
					break;

				case 2: 
					customers.at(customerID).setRole(ADMIN_CODE);
					std::cout << "���� ����������� ������ ������.\n";
					break;

				default: 
					std::cout << "��-�! ������� �������. �������� ������, ����-�����.\n";
					break;
				}
				break;

			default:
				std::cout << "��-�! ������� �������. �������� ������, ����-�����.\n";
				break;
			}
		}
	}
}

// �������� �볺���
void Admin::delCustomer(std::deque<Customer>& customers, int customerID)
{
	for (auto customer = customers.begin(); customer != customers.end(); customer++) {
		if (customer->getId() == customerID) {
			customers.erase(customer);
			std::cout << "������� � ID " << customerID << " ���� ������ ��������.\n";
		}
	}
}

// ����������� �� ������
void Admin::showAllProducts(std::deque<Product>& products)
{
	if (products.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		std::cout << "������ ��� �������� � �������\n";
		for (auto& product : products) {
			std::cout << "ID: " << product.getId()
				<< "\n����� ��������: " << product.getName()
				<< "\n������� ��������: " << product.getCost()
				<< "\n�������: " << product.getArticle() << '\n';
		}
	}
}

// ������ ����� �� ������
void Admin::showInfoProductByName(std::deque<Product>& products, std::string productName)
{
	if (products.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		for (auto& product : products) {
			if (product.getName() == productName) {
				std::cout << "������� � ������ " << productName << " ������ �������.\n"
					<< "���������� ��� ��������� �������:\n"
					<< "ID: " << product.getId()
					<< "\n����� ��������: " << product.getName()
					<< "\n������� ��������: " << product.getCost()
					<< "\n�������: " << product.getArticle() << '\n';
			}
		}
	}
}

// ������ ����� �� ��������
void Admin::showInfoProductByArticle(std::deque<Product>& products, std::string article)
{
	if (products.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		for (auto& product : products) {
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

// ³������ ���������� ��� �����
void Admin::showProductInfoById(std::deque<Product>& products, int productID)
{
	if (products.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		for (auto& product : products) {
			if (product.getId() == productID) {
				std::cout << "������� � ID " << productID << " ������ �������.\n"
					<< "���������� ��� ��������� �������:\n"
					<< "ID: " << product.getId()
					<< "\n����� ��������: " << product.getName()
					<< "\n������� ��������: " << product.getCost()
					<< "\n�������: " << product.getArticle() << '\n';
			}
		}
	}
}

// ������ �����
void Admin::addProduct(std::deque<Product>& products, Product& newProduct)
{
	bool isExists = false;
	for (auto& product : products) {
		if (newProduct.getId() == product.getId()) {
			std::cout << "������� � ����� ID ��� ����. �������� ������, ����-�����.\n";
			isExists = true;
			break;
		}
	}
	if (!isExists) {
		products.push_back(newProduct);
	}
}

// ���������� ���������� ��� �����
void Admin::editProduct(std::deque<Product>& products, int productID)
{
	int userInput = 0;
	constexpr int NAME_MIN_LENGTH = 5, NAME_MAX_LENGTH = 20;
	constexpr double MIN_COST = 1., MAX_COST = std::numeric_limits<double>::max();
	constexpr int MENU_MIN_SELECTION = 1, MENU_MAX_SELECTION = 2;
	double newCost = 0;
	std::string newName;

	for (auto& product : products) {
		if (product.getId() == productID) {
			do {
				std::cout << "������ �������� ��� ����:\n1. ��'� ��������.\n2. ������� ��������.\n��� ����: ";
				std::cin >> userInput;
				if (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION) {
					std::cout << "����������� ����. �������� ������, ����-�����.\n";
				}
			} while (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION);

			switch (userInput) {
			case 1:
				while (true) {
					std::cout << "������ ���� ��'� �������� " << products.at(productID).getName() << ": ";
					std::cin >> newName;
					if (newName.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "��'� �������� ������ ��������� �������. �������� ������, ����-�����.\n";
					}
					else if (newName.size() < NAME_MIN_LENGTH || newName.size() > NAME_MAX_LENGTH) {
						std::cout << "̳������� ������� ���� �������� - " << NAME_MIN_LENGTH << " �������, ����������� ������� ���� - " << NAME_MAX_LENGTH << " �������. �������� ������, ����-�����.\n";
					}
					else break;
				}
				products.at(productID).setName(newName);
				std::cout << "��'� �������� ������ ������. ��� ��� ��������:\nID: " << products.at(productID).getId() << "\n��'�: " << products.at(productID).getName() << "\n�������: " << products.at(productID).getCost() << " ���.\n";
				break;

			case 2:
				do {
					std::cout << "������ ���� ������� ��������: ";
					std::cin >> newCost;
					if (newCost < MIN_COST || newCost > MAX_COST) {
						std::cout << "̳������� ������� �������� - " << MIN_COST << ", ����������� - " << MAX_COST << ". �������� ������, ����-�����.\n";
					}
				} while (newCost < MIN_COST || newCost > MAX_COST);

				products.at(productID).setCost(newCost);
				std::cout << "������� �������� ������ ������. ��� ��� ��������:\nID: " << products.at(productID).getId() << "\n��'�: " << products.at(productID).getName() << "\n�������: " << products.at(productID).getCost() << " ���.\n";
				break;

			default:
				std::cout << "��-�! ������� �������. �������� ������, ����-�����.\n";
				break;
			}
		}
	}
}

// �������� �����
void Admin::delProduct(std::deque<Product>& products, int productID)
{
	for (auto product = products.begin(); product != products.end(); product++) {
		if (product->getId() == productID) {
			products.erase(product);
			std::cout << "������� �� ID " << productID << " ��� ������ ���������.\n";
		}
	}
}

// ����������� �� ���������� �� �� ������
void Admin::showAllOrdersAllProducts(std::deque<Order>& orders)
{
	if (orders.empty()) {
		std::cout << "����� ���� �������� ���������.\n";
	} else {
		std::cout << "�� ������ ����������\n";
		for (auto& order : orders) {
			std::cout << "ID: " << order.getId() << "\n������ ��������:\n";
			for (auto& product : order.getProducts())
			{
				std::cout << "ID: " << product.getId()
					<< "\n��'� ��������: " << product.getName()
					<< "\n�������: " << product.getCost()
					<< "\n�������: " << product.getArticle() << '\n';
			}
			std::cout << "�������� ���� ����������: " << order.getTotalAmount() << '\n';
			if (order.getActive() == true) {
				std::cout << "������ ����������: �������.";
			}
			else if (order.getActive() == false) {
				std::cout << "������ ����������: ���������.";
			}
		}
	}
}

// �������� ������ ����������
void Admin::delOrderProduct(std::deque<Order>& orders, int orderID)
{
	if (orders.empty()) {
		std::cout << "����� ���� �������� ���������.\n";
	} else {
		for (auto order = orders.begin(); order != orders.end(); order++) {
			if (order->getId() == orderID) {
				orders.erase(order);
				std::cout << "���������� � ID " << orderID << " ���� ������ ��������.\n";
			}
		}
	}
}

// �������� �� ���������� ������� ������
void Admin::delAllOrdersProduct(std::deque<Order>& orders, int productID)
{
	if (orders.empty()) {
		std::cout << "����� ���� �������� ���������.\n";
	} else {
		for (auto order = orders.begin(); order != orders.end(); ) {
			for (auto product = order->getProducts().begin(); product != order->getProducts().end();) {
				if (product->getId() == productID) {
					product = order->getProducts().erase(product);
				} else {
					++product;
				}
			}
			if (order->getProducts().empty()) {
				order = orders.erase(order);
			} else {
				++order;
			}
		}
	}
}

// �������� ��������� �� ���������� �� �� ������
void Admin::delAllOrdersAllProducts(std::deque<Order>& orders)
{
	if (orders.empty()) {
		std::cout << "����� ���� �������� ���������.\n";
	} else {
		orders.clear();
		std::cout << "�� ���������� �� �� �������� ������ �������.\n";
	}
}