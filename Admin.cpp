#include "Admin.h"
#include <iostream>
#include <limits>
#include <array>

// Масив символів, що повинні валідуватися
const std::array<wchar_t, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','№','?' };

Admin::Admin(int _id, int _role, std::wstring _login, std::wstring _password) : User(_id, _role, _login, _password) {}

std::deque<Customer> Admin::getCustomers() { return this->customers; }
void Admin::setCustomers(const std::deque<Customer>& customers) { this->customers = customers; }

// Додати клієнта
void Admin::addCustomer(Customer newCustomer)
{
	bool isExists = false;
    for (auto& customer : customers) {
        if (newCustomer.getId() == customer.getId()) {
			std::wcout << RED <<L"Покупець з таким ID вже існує. Повторіть спробу, будь-ласка.\n" << WHT;
			isExists = true;
            break;
        } else if (newCustomer.getLogin() == customer.getLogin()) {
			std::wcout << RED << L"Покупець з таким логіном вже існує. Повторіть спробу, будь-ласка.\n" << WHT;
			isExists = true;
			break;
		}
    }
    if (!isExists) {
		customers.push_back(newCustomer);
		std::wcout << GRN << L"Нового покупця успішно додано.\n";
    }
}

// Редагувати інформацію про клієнта
void Admin::editCustomer(int customerID)
{
	int userInput = 0;
	constexpr int USER_CODE = 1;
	constexpr int MENU_MIN_SELECTION = 1, MENU_MAX_SELECTION = 2;
	constexpr int LOGIN_MIN_LENGTH = 5, LOGIN_MAX_LENGTH = 15;
	constexpr int PASSWORD_MIN_LENGTH = 8, PASSWORD_MAX_LENGTH = 15;
	std::wstring newLogin, newPassword;

	for (auto& customer : customers) {
		if (customer.getId() == customerID) {
			while(true) 
			{
				std::wcout << WHT
					<< L"╭──────────────────────────────────╮\n"
					<< L"│" << RED << L"   Зміна параметрів користувача   " << WHT << L"│\n"
					<< L"├──────────────────────────────────┤\n"
					<< L"│" << CYN << L" 1. " << GRN << L"Логін покупця.		   " << WHT << L"│\n"
					<< L"│" << CYN << L" 2. " << GRN << L"Пароль покупця.		   " << WHT << L"│\n"
					<< L"│" << CYN << L" 3. " << GRN << L"До попереднього меню.	   " << WHT << L"│\n"
					<< L"╰──────────────────────────────────╯\n"
					<< L" Ваш вибір : " << CYN;
				try
				{
					std::wcin >> userInput;
				}
				catch (std::istream::failure e) {
					system("cls");
					std::wcout << RED << L" Введіть коректні дані.\n";
					std::wcin.clear();
					std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}

				switch (userInput) {
				case 1:
					while (true) {
						std::wcout << L"Введіть новий логін для покупця " << customers.at(customerID).getLogin() << L": ";
						std::wcin >> newLogin;
						if (newLogin.find(' ') != std::wstring::npos) {
							std::wcout << L"Логін містить некоректні символи. Повторіть спробу, будь-ласка.\n"; continue;
						}
						else if (newLogin.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::wstring::npos) {
							std::wcout << L"Логін містить некоректні символи. Повторіть спробу, будь-ласка.\n"; continue;
						}
						else if (newLogin.size() < LOGIN_MIN_LENGTH || newLogin.size() > LOGIN_MAX_LENGTH) {
							std::wcout << L"Мінімальна довжина логіну - " << LOGIN_MIN_LENGTH << L" символів, максимальна довжина логіну - " << LOGIN_MAX_LENGTH << L" символів. Повторіть спробу, будь-ласка.\n"; continue;
						}
						else break;
					}
					customers.at(customerID).setLogin(newLogin);
					std::wcout << L"Логін успішно змінено. Нові дані користувача:\nID: " << customers.at(customerID).getId()
						<< L"\nЛогін: " << customers.at(customerID).getLogin()
						<< L"\nПароль : " << customers.at(customerID).getPassword()
						<< L"\nКод ролі : " << customers.at(customerID).getRole();
					break;

				case 2:
					while (true) {
						std::wcout << L"Введіть новий пароль для покупця " << customers.at(customerID).getLogin() << L": ";
						std::wcin >> newPassword;
						if (newLogin.find(' ') != std::wstring::npos) {
							std::wcout << L"Пароль містить некоректні символи. Повторіть спробу, будь-ласка.\n";
						}
						else if (newPassword.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::wstring::npos) {
							std::wcout << L"Пароль містить некоректні символи. Повторіть спробу, будь-ласка.\n";
						}
						else if (newPassword.size() < PASSWORD_MIN_LENGTH || newPassword.size() > PASSWORD_MAX_LENGTH) {
							std::wcout << L"Мінімальна довжина паролю - " << PASSWORD_MIN_LENGTH << L" символів, максимальна довжина паролю - " << PASSWORD_MAX_LENGTH << L" символів. Повторіть спробу, будь-ласка.\n";
						}
						else break;
					}
					customers.at(customerID).setPassword(newPassword);
					std::wcout << L"Пароль успішно змінено. Нові дані користувача:\nID: " << customers.at(customerID).getId()
						<< L"\nЛогін: " << customers.at(customerID).getLogin()
						<< L"\nПароль : " << customers.at(customerID).getPassword()
						<< L"\nКод ролі : " << customers.at(customerID).getRole();
					break;

				case 3:
					userInput = 0;
					do {
						std::wcout << L"Оберіть нову роль користувача у системі:\n1. Користувач.\n2. Адміністратор.\nВаш вибір: ";
						std::wcin >> userInput;
						if (userInput < USER_CODE || userInput > ADMIN_CODE) {
							std::wcout << L"Некоректний вибір. Повторіть спробу, будь-ласка.\n";
						}
					} while (userInput < USER_CODE || userInput > ADMIN_CODE);

					switch (userInput) {
					case 1:
						customers.at(customerID).setRole(USER_CODE);
						std::wcout << L"Роль користувача успішно змінено.\n";
						break;

					case 2:
						customers.at(customerID).setRole(ADMIN_CODE);
						std::wcout << L"Роль користувача успішно змінено.\n";
						break;

					default:
						std::wcout << L"Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
						break;
					}
					break;

				default:
					std::wcout << L"Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
					break;
				}
			}
		}
	}
}

// Видалити клієнта
void Admin::delCustomer(int customerID)
{
	if (customers.empty()) {
		std::wcout << L"Наразі у магазині немає покупців.\n";
	} else {
		for (auto customer = customers.begin(); customer != customers.end(); ++customer) {
			if (customer->getId() == customerID) {
				customers.erase(customer);
				std::wcout << L"Покупець з ID " << customerID << L" був успішно видалений.\n";
				return;
			}
		}
		std::wcout << L"Покупця з ID " << customerID << L" не знайдено.\n";
	}
}

// Переглянути всі товари
void Admin::showAllProducts()
{
	if (shop.getProducts().empty()) {
		std::wcout << L"Наразі у магазині немає продуктів.\n";
	} else {
		std::wcout << L"Список усіх продуктів у магазині\n";
		for (auto& product : shop.getProducts()) {
			std::wcout << L"ID: " << product.getId()
				<< L"\nНазва продукту: " << product.getName()
				<< L"\nВартість продукту: " << product.getCost()
				<< L"\nАртикль: " << product.getArticle() << '\n';
		}
	}
}

// Знайти товар за назвою
void Admin::showInfoProductByName(std::wstring productName)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"Наразі у магазині немає продуктів.\n";
	} else {
		for (auto& product : shop.getProducts()) {
			if (product.getName() == productName) {
				std::wcout << L"Продукт з іменем " << productName << L" успішно зайдено.\n"
					<< L"Інформація про знайдений продукт:\n"
					<< L"ID: " << product.getId()
					<< L"\nНазва продукту: " << product.getName()
					<< L"\nВартість продукту: " << product.getCost()
					<< L"\nАртикль: " << product.getArticle() << '\n';
			}
		}
	}
}

// Знайти товар за артиклем
void Admin::showInfoProductByArticle(std::wstring article)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"Наразі у магазині немає продуктів.\n";
	} else {
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

// Відкрити інформацію про товар
void Admin::showProductInfoById(int productID)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"Наразі у магазині немає продуктів.\n";
	} else {
		for (auto& product : shop.getProducts()) {
			if (product.getId() == productID) {
				std::wcout << L"Продукт з ID " << productID << L" успішно зайдено.\n"
					<< L"Інформація про знайдений продукт:\n"
					<< L"ID: " << product.getId()
					<< L"\nНазва продукту: " << product.getName()
					<< L"\nВартість продукту: " << product.getCost()
					<< L"\nАртикль: " << product.getArticle() << '\n';
			}
		}
	}
}

// Додати товар
void Admin::addProduct(Product newProduct)
{
	bool isExists = false;
	for (auto& product : shop.getProducts()) {
		if (newProduct.getId() == product.getId()) {
			std::wcout << L"Продукт з таким ID вже існує. Повторіть спробу, будь-ласка.\n";
			isExists = true;
			break;
		}
	}
	if (!isExists) {
		shop.getProducts().push_back(newProduct);
		std::wcout << L"Новий продукт успішно додано.\n";
	}
}

// Редагувати інформацію про товар
void Admin::editProduct(int productID)
{
	int userInput = 0;
	constexpr int NAME_MIN_LENGTH = 5, NAME_MAX_LENGTH = 20;
	constexpr double MIN_COST = 1., MAX_COST = 100000000;
	constexpr int MENU_MIN_SELECTION = 1, MENU_MAX_SELECTION = 2;
	double newCost = 0;
	std::wstring newName;

	for (auto& product : shop.getProducts()) {
		if (product.getId() == productID) {
			do {
				std::wcout << L"Оберіть параметр для зміни:\n1. Ім'я продукту.\n2. Вартість продукту.\nВаш вибір: ";
				std::wcin >> userInput;
				if (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION) {
					std::wcout << L"Некоректний вибір. Повторіть спробу, будь-ласка.\n";
				}
			} while (userInput < MENU_MIN_SELECTION || userInput > MENU_MAX_SELECTION);

			switch (userInput) {
			case 1:
				while (true) {
					std::wcout << L"Введіть нове ім'я продукту " << shop.getProducts().at(productID).getName() << L": ";
					std::wcin >> newName;
					if (newName.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::wstring::npos) {
						std::wcout << L"Ім'я продукту містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newName.size() < NAME_MIN_LENGTH || newName.size() > NAME_MAX_LENGTH) {
						std::wcout << L"Мінімальна довжина імені продукту - " << NAME_MIN_LENGTH << L" символів, максимальна довжина імені - " << NAME_MAX_LENGTH << L" символів. Повторіть спробу, будь-ласка.\n";
					}
					else break;
				}
				shop.getProducts().at(productID).setName(newName);
				std::wcout << L"Ім'я продукту успішно змінено. Нові дані продукту:\nID: " << shop.getProducts().at(productID).getId()
					<< L"\nІм'я: " << shop.getProducts().at(productID).getName()
					<< L"\nВартість: " << shop.getProducts().at(productID).getCost() << L" грн.\n";
				break;

			case 2:
				do {
					std::wcout << L"Введіть нову вартість продукту: ";
					std::wcin >> newCost;
					if (newCost < MIN_COST || newCost > MAX_COST) {
						std::wcout << L"Мінімальна вартість продукту - " << MIN_COST << L", максимальна - " << MAX_COST << L". Повторіть спробу, будь-ласка.\n";
					}
				} while (newCost < MIN_COST || newCost > MAX_COST);

				shop.getProducts().at(productID).setCost(newCost);
				std::wcout << L"Вартість продукту успішно змінено. Нові дані продукту:\nID: " << shop.getProducts().at(productID).getId()
					<< L"\nІм'я: " << shop.getProducts().at(productID).getName()
					<< L"\nВартість: " << shop.getProducts().at(productID).getCost() << L" грн.\n";
				break;

			default:
				std::wcout << L"Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
				break;
			}
		}
	}
}

// Видалити товар
void Admin::delProduct(int productID)
{
	if (shop.getProducts().empty()) {
		std::wcout << L"Наразі у магазині немає продуктів.\n";
	} else {
		for (auto product = shop.getProducts().begin(); product != shop.getProducts().end(); ++product) {
			if (product->getId() == productID) {
				shop.getProducts().erase(product);
				std::wcout << L"Покупець з ID " << productID << L" був успішно видалений.\n";
				return;
			}
		}
		std::wcout << L"Покупця з ID " << productID << L" не знайдено.\n";
	}
}

// Переглянути всі замовлення на всі товари
void Admin::showAllOrdersAllProducts()
{
	if (customers.empty()) {
		std::wcout << L"Наразі у магазині немає покупців.\n";
	} else {
		for (auto& customer : customers) {
			if (customer.getOrders().empty()) {
				std::wcout << L"Наразі немає поточних замовлень.\n";
			} else {
				for (auto& order : customer.getOrders()) {
					std::wcout << L"ID: " << order.getId() << L"\nСписок продуктів:\n";
					for (auto& product : order.getProducts()) {
						std::wcout << L"ID: " << product.getId()
							<< L"\nІм'я продукту: " << product.getName()
							<< L"\nВартість: " << product.getCost()
							<< L"\nАртикль: " << product.getArticle() << '\n';
					}
					std::wcout << L"Загальна сума замовлення: " << order.getTotalAmount() << '\n';
					if (order.getActive() == true) {
						std::wcout << L"Статус замовлення: Активне.";
					} else if (order.getActive() == false) {
						std::wcout << L"Статус замовлення: Неактивне.";
					}
				}
			}
		}
	}
}

// Видалити обране замовлення
void Admin::delOrderProduct(int orderID)
{
	if (customers.empty()) {
		std::wcout << L"Наразі у магазині немає покупців.\n";
	} else {
		for (auto& customer : customers) {
			if (customer.getOrders().empty()) {
				std::wcout << L"Наразі немає поточних замовлень.\n";
			} else {
				for (auto order = customer.getOrders().begin(); order != customer.getOrders().end(); ++order) {
					if (order->getId() == orderID) {
						customer.getOrders().erase(order);
						std::wcout << L"Замовлення з ID " << orderID << L" було успішно видалено.\n";
						return;
					}
				}
			}
		}
	}
}

// Видалити всі замовлення певного товару
void Admin::delAllOrdersProduct(int productID)
{
	if (customers.empty()) {
		std::wcout << L"Наразі у магазині немає покупців.\n";
	} else {
		for (auto& customer : customers) {
			if (customer.getOrders().empty()) {
				std::wcout << L"Наразі немає поточних замовлень.\n";
			} else {
				for (auto& customer : customers) {
					if (customer.getOrders().empty()) {
						std::wcout << L"Наразі немає поточних замовлень.\n";
					} else {
						for (auto order = customer.getOrders().begin(); order != customer.getOrders().end(); ++order) {
							for (auto product = order->getProducts().begin(); product != order->getProducts().end(); ++product) {
								if (product->getId() == productID) {
									customer.getOrders().erase(order);
									std::wcout << L"Продукт з ID " << productID << L" було успішно видалено.\n";
									return;
								}
							}
						}
					}
				}
			}
		}
	}
}

// Видалити абсолютно всі замовлення на всі товари
void Admin::delAllOrdersAllProducts()
{
	if (customers.empty()) {
		std::wcout << L"Наразі у магазині немає покупців.\n";
	} else {
		for (auto& customer : customers) {
			if (customer.getOrders().empty()) {
				std::wcout << L"Наразі немає поточних замовлень.\n";
			} else {
				customer.getOrders().clear();
				std::wcout << L"Усі замовлення на усі продукти успішно видалені.\n";
			}
		}
	}
}