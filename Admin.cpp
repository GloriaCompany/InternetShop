#include "Admin.h"
#include <iostream>
#include <limits>
#include <array>

// ����� �������, �� ������ �����������
const std::array<char, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','�','?' };

Admin::Admin(int _id, int _role, std::string _login, std::string _password) : User(_id, _role, _login, _password) {}

// �������� ��� ��� �����
void Admin::setCustomersForAdmin(const std::deque<Customer>& customers) 
{
	if (customers.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		this->shopCustomers = customers;
	}
}

// �������� ��� ��� ��������
void Admin::setProductsForAdmin(const std::deque<Product>& products) 
{
	if (products.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		this->shopProducts = products;
	}
}

// �������� ��� ��� ����������
void Admin::setOrdersForAdmin(const std::deque<Order>& orders)
{
	if (orders.empty()) {
		std::cout << "����� � ������� ���� ���������.\n";
	} else {
		this->shopOrders = orders;
	}
}

// ������ �볺���
void Admin::addCustomer(Customer& newCustomer)
{
	bool isExists = false;
    for (auto& customer : this->shopCustomers) {
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
		this->shopCustomers.push_back(newCustomer);
    }
}

// ���������� ���������� ��� �볺���
void Admin::editCustomer(int customerID)
{
	int userInput = 0;
	constexpr int USER_CODE = 1, ADMIN_CODE = 2;
	constexpr int MENU_MIN_SELECTION = 1, MENU_MAX_SELECTION = 2;
	constexpr int LOGIN_MIN_LENGTH = 5, LOGIN_MAX_LENGTH = 15;
	constexpr int PASSWORD_MIN_LENGTH = 8, PASSWORD_MAX_LENGTH = 15;
	std::string newLogin, newPassword;

	for (auto& customer : this->shopCustomers) {
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
					std::cout << "������ ����� ���� ��� ������� " << this->shopCustomers.at(customerID).getLogin() << ": ";
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
				this->shopCustomers.at(customerID).setLogin(newLogin);
				std::cout << "���� ������ ������. ��� ��� �����������:\nID: " << this->shopCustomers.at(customerID).getId() 
					<< "\n����: " << this->shopCustomers.at(customerID).getLogin() 
					<< "\n������ : " << this->shopCustomers.at(customerID).getPassword()
					<< "\n��� ��� : " << this->shopCustomers.at(customerID).getRole();
				break;

			case 2:
				while (true) {
					std::cout << "������ ����� ������ ��� ������� " << this->shopCustomers.at(customerID).getLogin() << ": ";
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
				this->shopCustomers.at(customerID).setPassword(newPassword);
				std::cout << "������ ������ ������. ��� ��� �����������:\nID: " << this->shopCustomers.at(customerID).getId()
					<< "\n����: " << this->shopCustomers.at(customerID).getLogin()
					<< "\n������ : " << this->shopCustomers.at(customerID).getPassword()
					<< "\n��� ��� : " << this->shopCustomers.at(customerID).getRole();
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
					this->shopCustomers.at(customerID).setRole(USER_CODE);
					std::cout << "���� ����������� ������ ������.\n";
					break;

				case 2: 
					this->shopCustomers.at(customerID).setRole(ADMIN_CODE);
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
void Admin::delCustomer(int customerID)
{
	for (auto customer = this->shopCustomers.begin(); customer != this->shopCustomers.end(); customer++) {
		if (customer->getId() == customerID) {
			this->shopCustomers.erase(customer);
			std::cout << "������� � ID " << customerID << " ���� ������ ��������.\n";
		}
	}
}

// ����������� �� ������
void Admin::showAllProducts()
{
	if (this->shopProducts.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		std::cout << "������ ��� �������� � �������\n";
		for (auto& product : this->shopProducts) {
			std::cout << "ID: " << product.getId()
				<< "\n����� ��������: " << product.getName()
				<< "\n������� ��������: " << product.getCost()
				<< "\n�������: " << product.getArticle() << '\n';
		}
	}
}

// ������ ����� �� ������
void Admin::showInfoProductByName(std::string productName)
{
	if (this->shopProducts.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		for (auto& product : this->shopProducts) {
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
void Admin::showInfoProductByArticle(std::string article)
{
	if (this->shopProducts.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		for (auto& product : this->shopProducts) {
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
void Admin::showProductInfoById(int productID)
{
	if (this->shopProducts.empty()) {
		std::cout << "����� � ������� ���� ��������.\n";
	} else {
		for (auto& product : this->shopProducts) {
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
void Admin::addProduct(Product& newProduct)
{
	bool isExists = false;
	for (auto& product : this->shopProducts) {
		if (newProduct.getId() == product.getId()) {
			std::cout << "������� � ����� ID ��� ����. �������� ������, ����-�����.\n";
			isExists = true;
			break;
		}
	}
	if (!isExists) {
		this->shopProducts.push_back(newProduct);
	}
}

// ���������� ���������� ��� �����
void Admin::editProduct(int productID)
{
	int userInput = 0;
	constexpr int NAME_MIN_LENGTH = 5, NAME_MAX_LENGTH = 20;
	constexpr double MIN_COST = 1., MAX_COST = std::numeric_limits<double>::max();
	constexpr int MENU_MIN_SELECTION = 1, MENU_MAX_SELECTION = 2;
	double newCost = 0;
	std::string newName;

	for (auto& product : this->shopProducts) {
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
					std::cout << "������ ���� ��'� �������� " << this->shopProducts.at(productID).getName() << ": ";
					std::cin >> newName;
					if (newName.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "��'� �������� ������ ��������� �������. �������� ������, ����-�����.\n";
					}
					else if (newName.size() < NAME_MIN_LENGTH || newName.size() > NAME_MAX_LENGTH) {
						std::cout << "̳������� ������� ���� �������� - " << NAME_MIN_LENGTH << " �������, ����������� ������� ���� - " << NAME_MAX_LENGTH << " �������. �������� ������, ����-�����.\n";
					}
					else break;
				}
				this->shopProducts.at(productID).setName(newName);
				std::cout << "��'� �������� ������ ������. ��� ��� ��������:\nID: " << this->shopProducts.at(productID).getId() 
					<< "\n��'�: " << this->shopProducts.at(productID).getName()
					<< "\n�������: " << this->shopProducts.at(productID).getCost() << " ���.\n";
				break;

			case 2:
				do {
					std::cout << "������ ���� ������� ��������: ";
					std::cin >> newCost;
					if (newCost < MIN_COST || newCost > MAX_COST) {
						std::cout << "̳������� ������� �������� - " << MIN_COST << ", ����������� - " << MAX_COST << ". �������� ������, ����-�����.\n";
					}
				} while (newCost < MIN_COST || newCost > MAX_COST);

				this->shopProducts.at(productID).setCost(newCost);
				std::cout << "������� �������� ������ ������. ��� ��� ��������:\nID: " << this->shopProducts.at(productID).getId()
					<< "\n��'�: " << this->shopProducts.at(productID).getName()
					<< "\n�������: " << this->shopProducts.at(productID).getCost() << " ���.\n";
				break;

			default:
				std::cout << "��-�! ������� �������. �������� ������, ����-�����.\n";
				break;
			}
		}
	}
}

// �������� �����
void Admin::delProduct(int productID)
{
	for (auto product = this->shopProducts.begin(); product != this->shopProducts.end(); product++) {
		if (product->getId() == productID) {
			this->shopProducts.erase(product);
			std::cout << "������� �� ID " << productID << " ��� ������ ���������.\n";
		}
	}
}

// ����������� �� ���������� �� �� ������
void Admin::showAllOrdersAllProducts()
{
	if (this->shopOrders.empty()) {
		std::cout << "����� ���� �������� ���������.\n";
	} else {
		std::cout << "�� ������ ����������\n";
		for (auto& order : this->shopOrders) {
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
void Admin::delOrderProduct(int orderID)
{
	if (this->shopOrders.empty()) {
		std::cout << "����� ���� �������� ���������.\n";
	} else {
		for (auto order = this->shopOrders.begin(); order != this->shopOrders.end(); order++) {
			if (order->getId() == orderID) {
				this->shopOrders.erase(order);
				std::cout << "���������� � ID " << orderID << " ���� ������ ��������.\n";
			}
		}
	}
}

// �������� �� ���������� ������� ������
void Admin::delAllOrdersProduct(int productID)
{
	if (this->shopOrders.empty()) {
		std::cout << "����� ���� �������� ���������.\n";
	} else {
		for (auto order = this->shopOrders.begin(); order != this->shopOrders.end(); ) {
			for (auto product = order->getProducts().begin(); product != order->getProducts().end();) {
				if (product->getId() == productID) {
					product = order->getProducts().erase(product);
				} else {
					++product;
				}
			}
			if (order->getProducts().empty()) {
				order = this->shopOrders.erase(order);
			} else {
				++order;
			}
		}
	}
}

// �������� ��������� �� ���������� �� �� ������
void Admin::delAllOrdersAllProducts()
{
	if (this->shopOrders.empty()) {
		std::cout << "����� ���� �������� ���������.\n";
	} else {
		this->shopOrders.clear();
		std::cout << "�� ���������� �� �� �������� ������ �������.\n";
	}
}