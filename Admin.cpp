#include "Admin.h"
#include <iostream>
#include <limits>
#include <array>

// Масив символів, що повинні валідуватися
const std::array<char, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','№','?' };

Admin::Admin(int _id, int _role, std::string _login, std::string _password) : User(_id, _role, _login, _password) {}

// Отримати дані про клєнтів
void Admin::setCustomersForAdmin(const std::deque<Customer>& customers) 
{
	if (customers.empty()) {
		std::cout << "Наразі у магазині немає покупців.\n";
	} else {
		this->shopCustomers = customers;
	}
}

// Отримати дані про продукти
void Admin::setProductsForAdmin(const std::deque<Product>& products) 
{
	if (products.empty()) {
		std::cout << "Наразі у магазині немає продуктів.\n";
	} else {
		this->shopProducts = products;
	}
}

// Отримати дані про замовлення
void Admin::setOrdersForAdmin(const std::deque<Order>& orders)
{
	if (orders.empty()) {
		std::cout << "Наразі у магазині немає замовлень.\n";
	} else {
		this->shopOrders = orders;
	}
}

// Додати клієнта
void Admin::addCustomer(Customer& newCustomer)
{
	bool isExists = false;
    for (auto& customer : this->shopCustomers) {
        if (newCustomer.getId() == customer.getId()) {
			std::cout << "Покупець з таким ID вже існує. Повторіть спробу, будь-ласка.\n";
			isExists = true;
            break;
        } else if (newCustomer.getLogin() == customer.getLogin()) {
			std::cout << "Покупець з таким логіном вже існує. Повторіть спробу, будь-ласка.\n";
			isExists = true;
			break;
		}
    }
    if (!isExists) {
		this->shopCustomers.push_back(newCustomer);
    }
}

// Редагувати інформацію про клієнта
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
				std::cout << "Оберіть параметр для зміни:\n1. Логін покупця.\n2. Пароль покупця.\n3. До попереднього меню.\nВаш вибір: ";
				std::cin >> userInput;
				if (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION) {
					std::cout << "Некоректний вибір. Повторіть спробу, будь-ласка.\n";
				}
			} while (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION);

			switch (userInput) {
			case 1:
				while (true) {
					std::cout << "Введіть новий логін для покупця " << this->shopCustomers.at(customerID).getLogin() << ": ";
					std::cin >> newLogin;
					if (newLogin.find(' ') != std::string::npos) {
						std::cout << "Логін містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newLogin.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "Логін містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newLogin.size() < LOGIN_MIN_LENGTH || newLogin.size() > LOGIN_MAX_LENGTH) {
						std::cout << "Мінімальна довжина логіну - " << LOGIN_MIN_LENGTH << " символів, максимальна довжина логіну - " << LOGIN_MAX_LENGTH << " символів. Повторіть спробу, будь-ласка.\n";
					}
					else break;
				}
				this->shopCustomers.at(customerID).setLogin(newLogin);
				std::cout << "Логін успішно змінено. Нові дані користувача:\nID: " << this->shopCustomers.at(customerID).getId() 
					<< "\nЛогін: " << this->shopCustomers.at(customerID).getLogin() 
					<< "\nПароль : " << this->shopCustomers.at(customerID).getPassword()
					<< "\nКод ролі : " << this->shopCustomers.at(customerID).getRole();
				break;

			case 2:
				while (true) {
					std::cout << "Введіть новий пароль для покупця " << this->shopCustomers.at(customerID).getLogin() << ": ";
					std::cin >> newPassword;
					if (newLogin.find(' ') != std::string::npos) {
						std::cout << "Пароль містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newPassword.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "Пароль містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newPassword.size() < PASSWORD_MIN_LENGTH || newPassword.size() > PASSWORD_MAX_LENGTH) {
						std::cout << "Мінімальна довжина паролю - " << PASSWORD_MIN_LENGTH << " символів, максимальна довжина паролю - " << PASSWORD_MAX_LENGTH << " символів. Повторіть спробу, будь-ласка.\n";
					}
					else break;
				}
				this->shopCustomers.at(customerID).setPassword(newPassword);
				std::cout << "Пароль успішно змінено. Нові дані користувача:\nID: " << this->shopCustomers.at(customerID).getId()
					<< "\nЛогін: " << this->shopCustomers.at(customerID).getLogin()
					<< "\nПароль : " << this->shopCustomers.at(customerID).getPassword()
					<< "\nКод ролі : " << this->shopCustomers.at(customerID).getRole();
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
					this->shopCustomers.at(customerID).setRole(USER_CODE);
					std::cout << "Роль користувача успішно змінено.\n";
					break;

				case 2: 
					this->shopCustomers.at(customerID).setRole(ADMIN_CODE);
					std::cout << "Роль користувача успішно змінено.\n";
					break;

				default: 
					std::cout << "Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
					break;
				}
				break;

			default:
				std::cout << "Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
				break;
			}
		}
	}
}

// Видалити клієнта
void Admin::delCustomer(int customerID)
{
	for (auto customer = this->shopCustomers.begin(); customer != this->shopCustomers.end(); customer++) {
		if (customer->getId() == customerID) {
			this->shopCustomers.erase(customer);
			std::cout << "Покупця з ID " << customerID << " було успішно видалено.\n";
		}
	}
}

// Переглянути всі товари
void Admin::showAllProducts()
{
	if (this->shopProducts.empty()) {
		std::cout << "Наразі у магазині немає продуктів.\n";
	} else {
		std::cout << "Список усіх продуктів у магазині\n";
		for (auto& product : this->shopProducts) {
			std::cout << "ID: " << product.getId()
				<< "\nНазва продукту: " << product.getName()
				<< "\nВартість продукту: " << product.getCost()
				<< "\nАртикль: " << product.getArticle() << '\n';
		}
	}
}

// Знайти товар за назвою
void Admin::showInfoProductByName(std::string productName)
{
	if (this->shopProducts.empty()) {
		std::cout << "Наразі у магазині немає продуктів.\n";
	} else {
		for (auto& product : this->shopProducts) {
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
}

// Знайти товар за артиклем
void Admin::showInfoProductByArticle(std::string article)
{
	if (this->shopProducts.empty()) {
		std::cout << "Наразі у магазині немає продуктів.\n";
	} else {
		for (auto& product : this->shopProducts) {
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
}

// Відкрити інформацію про товар
void Admin::showProductInfoById(int productID)
{
	if (this->shopProducts.empty()) {
		std::cout << "Наразі у магазині немає продуктів.\n";
	} else {
		for (auto& product : this->shopProducts) {
			if (product.getId() == productID) {
				std::cout << "Продукт з ID " << productID << " успішно зайдено.\n"
					<< "Інформація про знайдений продукт:\n"
					<< "ID: " << product.getId()
					<< "\nНазва продукту: " << product.getName()
					<< "\nВартість продукту: " << product.getCost()
					<< "\nАртикль: " << product.getArticle() << '\n';
			}
		}
	}
}

// Додати товар
void Admin::addProduct(Product& newProduct)
{
	bool isExists = false;
	for (auto& product : this->shopProducts) {
		if (newProduct.getId() == product.getId()) {
			std::cout << "Продукт з таким ID вже існує. Повторіть спробу, будь-ласка.\n";
			isExists = true;
			break;
		}
	}
	if (!isExists) {
		this->shopProducts.push_back(newProduct);
	}
}

// Редагувати інформацію про товар
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
				std::cout << "Оберіть параметр для зміни:\n1. Ім'я продукту.\n2. Вартість продукту.\nВаш вибір: ";
				std::cin >> userInput;
				if (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION) {
					std::cout << "Некоректний вибір. Повторіть спробу, будь-ласка.\n";
				}
			} while (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION);

			switch (userInput) {
			case 1:
				while (true) {
					std::cout << "Введіть нове ім'я продукту " << this->shopProducts.at(productID).getName() << ": ";
					std::cin >> newName;
					if (newName.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
						std::cout << "Ім'я продукту містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newName.size() < NAME_MIN_LENGTH || newName.size() > NAME_MAX_LENGTH) {
						std::cout << "Мінімальна довжина імені продукту - " << NAME_MIN_LENGTH << " символів, максимальна довжина імені - " << NAME_MAX_LENGTH << " символів. Повторіть спробу, будь-ласка.\n";
					}
					else break;
				}
				this->shopProducts.at(productID).setName(newName);
				std::cout << "Ім'я продукту успішно змінено. Нові дані продукту:\nID: " << this->shopProducts.at(productID).getId() 
					<< "\nІм'я: " << this->shopProducts.at(productID).getName()
					<< "\nВартість: " << this->shopProducts.at(productID).getCost() << " грн.\n";
				break;

			case 2:
				do {
					std::cout << "Введіть нову вартість продукту: ";
					std::cin >> newCost;
					if (newCost < MIN_COST || newCost > MAX_COST) {
						std::cout << "Мінімальна вартість продукту - " << MIN_COST << ", максимальна - " << MAX_COST << ". Повторіть спробу, будь-ласка.\n";
					}
				} while (newCost < MIN_COST || newCost > MAX_COST);

				this->shopProducts.at(productID).setCost(newCost);
				std::cout << "Вартість продукту успішно змінено. Нові дані продукту:\nID: " << this->shopProducts.at(productID).getId()
					<< "\nІм'я: " << this->shopProducts.at(productID).getName()
					<< "\nВартість: " << this->shopProducts.at(productID).getCost() << " грн.\n";
				break;

			default:
				std::cout << "Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
				break;
			}
		}
	}
}

// Видалити товар
void Admin::delProduct(int productID)
{
	for (auto product = this->shopProducts.begin(); product != this->shopProducts.end(); product++) {
		if (product->getId() == productID) {
			this->shopProducts.erase(product);
			std::cout << "Продукт за ID " << productID << " був успішно видалений.\n";
		}
	}
}

// Переглянути всі замовлення на всі товари
void Admin::showAllOrdersAllProducts()
{
	if (this->shopOrders.empty()) {
		std::cout << "Наразі немає поточних замовлень.\n";
	} else {
		std::cout << "Всі поточні замовлення\n";
		for (auto& order : this->shopOrders) {
			std::cout << "ID: " << order.getId() << "\nСписок продуктів:\n";
			for (auto& product : order.getProducts())
			{
				std::cout << "ID: " << product.getId()
					<< "\nІм'я продукту: " << product.getName()
					<< "\nВартість: " << product.getCost()
					<< "\nАртикль: " << product.getArticle() << '\n';
			}
			std::cout << "Загальна сума замовлення: " << order.getTotalAmount() << '\n';
			if (order.getActive() == true) {
				std::cout << "Статус замовлення: Активне.";
			}
			else if (order.getActive() == false) {
				std::cout << "Статус замовлення: Неактивне.";
			}
		}
	}
}

// Видалити обране замовлення
void Admin::delOrderProduct(int orderID)
{
	if (this->shopOrders.empty()) {
		std::cout << "Наразі немає поточних замовлень.\n";
	} else {
		for (auto order = this->shopOrders.begin(); order != this->shopOrders.end(); order++) {
			if (order->getId() == orderID) {
				this->shopOrders.erase(order);
				std::cout << "Замовлення з ID " << orderID << " було успішно видалене.\n";
			}
		}
	}
}

// Видалити всі замовлення певного товару
void Admin::delAllOrdersProduct(int productID)
{
	if (this->shopOrders.empty()) {
		std::cout << "Наразі немає поточних замовлень.\n";
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

// Видалити абсолютно всі замовлення на всі товари
void Admin::delAllOrdersAllProducts()
{
	if (this->shopOrders.empty()) {
		std::cout << "Наразі немає поточних замовлень.\n";
	} else {
		this->shopOrders.clear();
		std::cout << "Усі замовлення на усі продукти успішно видалені.\n";
	}
}