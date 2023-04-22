#include "Admin.h"
#include "Customer.h"
#include <deque>
#include <array>
#include <iostream>

const std::array<char, 25> invalidSymbols = { ' ','!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','№','?' };

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
				std::cout << "Оберіть параметр для зміни:\n1. Логін покупця.\n2. Пароль покупця.\n3. До попереднього меню.\nВаш вибір: ";
				std::cin >> userInput;
				if (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION) {
					std::cout << "Некоректний вибір. Повторіть спробу, будь-ласка.\n";
				}
			} while (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION);

			switch (userInput) {
			case 1:
				while (true) {
					std::cout << "Введіть новий логін для покупця " << customers[customerID].getLogin() << ": ";
					std::cin >> newLogin;
					if (newLogin.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "Логін містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newLogin.size() < LOGIN_MIN_SIZE || newLogin.size() > LOGIN_MAX_SIZE) {
						std::cout << "Мінімальна довжина логіну - " << LOGIN_MIN_SIZE << " символів, максимальна довжина логіну - " << LOGIN_MAX_SIZE << " символів. Повторіть спробу, будь-ласка.\n";
					}
					else break;
				}
				customers[customerID].setLogin(newLogin);
				std::cout << "Логін успішно змінено. Нові дані користувача:\nЛогін: " << customers[customerID].getLogin() << "\nПароль: " << customers[customerID].getPassword() << "\nКод ролі: " << customers[customerID].getRole();
				break;

			case 2:
				while (true) {
					std::cout << "Введіть новий пароль для покупця " << customers[customerID].getLogin() << ": ";
					std::cin >> newPassword;
					if (newPassword.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "Пароль містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newPassword.size() < PASSWORD_MIN_SIZE || newPassword.size() > PASSWORD_MAX_SIZE) {
						std::cout << "Мінімальна довжина паролю - " << PASSWORD_MIN_SIZE << " символів, максимальна довжина паролю - " << PASSWORD_MAX_SIZE << " символів. Повторіть спробу, будь-ласка.\n";
					}
					else break;
				}
				customers[customerID].setPassword(newPassword);
				std::cout << "Пароль успішно змінено. Нові дані користувача:\nЛогін: " << customers[customerID].getLogin() << "\nПароль: " << customers[customerID].getPassword() << "\nКод ролі: " << customers[customerID].getRole();
				break;

			case 3:
				userInput = 0;
				do {
					std::cout << "Оберіть нову роль користувача у системі:\n1. Користувач.\n2. Адміністратор.\nВаш вибір: ";
					std::cin >> userInput;
					if (userInput < USER_CODE || userInput > ADMIN_CODE) {
						std::cout << "Некоректний вибір. Повторіть спробу, будь-ласка.\n";
					}
				} while (userInput < USER_CODE || userInput > ADMIN_CODE);

				switch (userInput) {
				case 1:
					customers[customerID].setRole(USER_CODE);
					std::cout << "Роль користувача успішно змінено.\n";
					break;

				case 2: 
					customers[customerID].setRole(ADMIN_CODE);
					std::cout << "Роль користувача успішно змінено.\n";
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
			std::cout << "Покупець з ID " << customerID << " був видалений.\n";
		}
		delete* it;
		users.erase(it);
	} else {
		std::cout << "Покупця з ID " << customerID << " не знайдено.\n";
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