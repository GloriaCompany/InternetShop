#include "Admin.h"

// Масив символів, що повинні валідуватися
const std::array<wchar_t, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','№','?' };

Admin::Admin(int _id, int _role, std::wstring _login, std::wstring _password) : User(_id, _role, _login, _password) {}

std::deque<Customer> Admin::getCustomers() { return this->customers; }
void Admin::setCustomers(const std::deque<Customer>& customers) { this->customers = customers; }

// Додати клієнта
void Admin::addCustomer(Customer newCustomer)
{
	constexpr int LOGIN_MIN_LENGTH = 5, LOGIN_MAX_LENGTH = 15;
	constexpr int PASSWORD_MIN_LENGTH = 8, PASSWORD_MAX_LENGTH = 15;

	if (newCustomer.getLogin().find(' ') != std::wstring::npos || newCustomer.getPassword().find(' ') != std::wstring::npos) 
	{
		std::wcout << RED << L"Логін або пароль містять некоректні символи. Повторіть спробу, будь-ласка.\n";
	} 
	else if (newCustomer.getLogin().find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::wstring::npos
			|| newCustomer.getPassword().find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::wstring::npos) 
	{
		std::wcout << RED << L"Логін або пароль містять некоректні символи. Повторіть спробу, будь-ласка.\n";
	}
	else if (newCustomer.getLogin().size() < LOGIN_MIN_LENGTH || newCustomer.getLogin().size() > LOGIN_MAX_LENGTH
		|| newCustomer.getPassword().size() < PASSWORD_MIN_LENGTH || newCustomer.getPassword().size() > PASSWORD_MAX_LENGTH) 
	{
		std::wcout << RED << L"Мінімальна довжина логіну - " << LOGIN_MIN_LENGTH << L" символів, максимальна довжина логіну - " << LOGIN_MAX_LENGTH << L" символів.\n";
		std::wcout << RED << L"Мінімальна довжина паролю - " << PASSWORD_MIN_LENGTH << L" символів, максимальна довжина паролю - " << PASSWORD_MAX_LENGTH << L" символів. \nПовторіть спробу, будь-ласка.\n";
	}
	else 
	{
		bool isExists = false;
		for (auto& customer : customers)
		{
			if (newCustomer.getId() == customer.getId())
			{
				std::wcout << RED << L"Покупець з таким ID вже існує. Повторіть спробу, будь-ласка.\n" << WHT;
				isExists = true;
				break;
			}
			else if (newCustomer.getLogin() == customer.getLogin())
			{
				std::wcout << RED << L"Покупець з таким логіном вже існує. Повторіть спробу, будь-ласка.\n" << WHT;
				isExists = true;
				break;
			}
		}
		if (!isExists && newCustomer.getRole() == CUSTOMER_CODE) 
		{
			this->customers.push_back(newCustomer);
			std::wcout << GRN << L"Нового покупця успішно додано.\n";
		}
	}
}

// Редагувати інформацію про клієнта
void Admin::editCustomer(int customerID)
{
	int customerInput = 0;
	constexpr int LOGIN_MIN_LENGTH = 5, LOGIN_MAX_LENGTH = 15;
	constexpr int PASSWORD_MIN_LENGTH = 8, PASSWORD_MAX_LENGTH = 15;
	std::wstring newLogin, newPassword;

	for (auto& customer : customers) 
	{
		if (customer.getId() == customerID && customer.getRole() == CUSTOMER_CODE)
		{
			while(true) 
			{
				std::wcout << WHT
					<< L"╭──────────────────────────────────╮\n"
					<< L"│" << RED << L"   Зміна параметрів користувача   " << WHT << L"│\n"
					<< L"├──────────────────────────────────┤\n"
					<< L"│" << CYN << L" 1. " << GRN << L"Логін покупця.		   " << WHT << L"│\n"
					<< L"│" << CYN << L" 2. " << GRN << L"Пароль покупця.		   " << WHT << L"│\n"
					<< L"│" << CYN << L" 3. " << GRN << L"Код ролі покупця.		   " << WHT << L"│\n"
					<< L"│" << CYN << L" 0. " << GRN << L"До попереднього меню.	   " << WHT << L"│\n"
					<< L"╰──────────────────────────────────╯\n"
					<< L" Оберіть опцію (0 - 3): " << CYN;
				try
				{
					std::wcin >> customerInput;
				}
				catch (std::istream::failure e) 
				{
					system("cls");
					std::wcout << RED << L" Введіть коректні дані.\n";
					std::wcin.clear();
					std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}

				switch (customerInput) 
				{
				case 1:
					while (true) {
						std::wcout << WHT << L"Введіть новий логін для покупця " << customer.getLogin() << L": " << CYN;
						std::wcin >> newLogin;

						if (newLogin.find(' ') != std::wstring::npos) 
						{
							std::wcout << RED << L"Логін містить некоректні символи. Повторіть спробу, будь-ласка.\n"; continue;
						}
						else if (newLogin.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::wstring::npos) 
						{
							std::wcout << RED << L"Логін містить некоректні символи. Повторіть спробу, будь-ласка.\n"; continue;
						}
						else if (newLogin.size() < LOGIN_MIN_LENGTH || newLogin.size() > LOGIN_MAX_LENGTH) 
						{
							std::wcout << RED << L"Мінімальна довжина логіну - " << LOGIN_MIN_LENGTH << L" символів, максимальна довжина логіну - " << LOGIN_MAX_LENGTH << L" символів. Повторіть спробу, будь-ласка.\n"; continue;
						}
						else break;
					}

					customer.setLogin(newLogin);
					std::wcout << GRN << L"Логін успішно змінено."
						<< WHT << L"\nНові дані користувача : \nID : " << customer.getId()
						<< WHT << L"\nЛогін: " << customer.getLogin()
						<< WHT << L"\nПароль : " << customer.getPassword()
						<< WHT << L"\nКод ролі : " << customer.getRole() << L"\n";
					break;

				case 2:
					while (true) 
					{
						std::wcout << WHT << L"Введіть новий пароль для покупця " << customer.getLogin() << L": " << CYN;
						std::wcin >> newPassword;

						if (newPassword.find(' ') != std::wstring::npos) 
						{
							std::wcout << RED << L"Пароль містить некоректні символи. Повторіть спробу, будь-ласка.\n";
						}
						else if (newPassword.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::wstring::npos) 
						{
							std::wcout << RED << L"Пароль містить некоректні символи. Повторіть спробу, будь-ласка.\n";
						}
						else if (newPassword.size() < PASSWORD_MIN_LENGTH || newPassword.size() > PASSWORD_MAX_LENGTH) 
						{
							std::wcout << RED << L"Мінімальна довжина паролю - " << PASSWORD_MIN_LENGTH << L" символів, максимальна довжина паролю - " << PASSWORD_MAX_LENGTH << L" символів. Повторіть спробу, будь-ласка.\n";
						}
						else break;
					}

					customer.setPassword(newPassword);
					std::wcout << GRN << L"Пароль успішно змінено."
						<< WHT << L"\nНові дані користувача : \nID : " << customer.getId()
						<< WHT << L"\nЛогін: " << customer.getLogin()
						<< WHT << L"\nПароль : " << customer.getPassword()
						<< WHT << L"\nКод ролі : " << customer.getRole();
					break;

				case 3:
					customerInput = 0;
					do 
					{
						std::wcout << WHT << L"Оберіть нову роль користувача у системі:\n1. Користувач.\n2. Адміністратор.\nВаш вибір: " << CYN;
						std::wcin >> customerInput;
						if (customerInput < CUSTOMER_CODE || customerInput > ADMIN_CODE) 
						{
							std::wcout << RED << L"Некоректний вибір. Повторіть спробу, будь-ласка.\n";
						}
					} while (customerInput < CUSTOMER_CODE || customerInput > ADMIN_CODE);

					switch (customerInput) {
					case 1:
						customer.setRole(CUSTOMER_CODE);
						std::wcout << GRN << L"Роль успішно змінено."
							<< WHT << L"\nНові дані користувача : \nID : " << customer.getId()
							<< WHT << L"\nЛогін: " << customer.getLogin()
							<< WHT << L"\nПароль : " << customer.getPassword()
							<< WHT << L"\nКод ролі : " << customer.getRole();
						break;

					case 2:
						customer.setRole(ADMIN_CODE);
						std::wcout << GRN << L"Роль успішно змінено."
							<< WHT << L"\nНові дані користувача : \nID : " << customer.getId()
							<< WHT << L"\nЛогін: " << customer.getLogin()
							<< WHT << L"\nПароль : " << customer.getPassword()
							<< WHT << L"\nКод ролі : " << customer.getRole();
						break;

					default:
						std::wcout << RED << L"Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
						break;
					}
					break;
				case 0:
				{
					break;
				}
				default:
					std::wcout << RED << L"Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
					break;
				}

				if (customerInput == 0)
				{
					break;
				}
			}
		}
	}
}

// Видалити клієнта
void Admin::delCustomer(int customerID)
{
	bool isExists = true;
	for (auto customer = customers.begin(); customer != customers.end(); ++customer) 
	{
		if (customer->getRole() != CUSTOMER_CODE) 
		{
			isExists = false;
		}
	}
	if (!isExists) 
	{
		std::wcout << RED << L"Наразі у магазині немає покупців.\n";
	}

	if (customers.empty()) 
	{
		std::wcout << RED << L"Наразі у магазині немає користувачів.\n";
	} 
	else 
	{
		for (auto customer = customers.begin(); customer != customers.end(); ++customer)
		{
			if (customer->getId() == customerID && customer->getRole() == CUSTOMER_CODE)
			{
				this->customers.erase(customer);
				std::wcout << GRN << L"Покупець з ID " << customerID << L" був успішно видалений.\n";
				return;
			}
		}
		std::wcout << RED << L"Покупця з ID " << customerID << L" не знайдено.\n";
	}
}

// Додати товар
void Admin::addProduct(Shop& shop, Product newProduct)
{
	constexpr double MIN_COST = 1., MAX_COST = 100000000;

	if (newProduct.getCost() < MIN_COST || newProduct.getCost() > MAX_COST) 
	{
		std::wcout << RED << L"Мінімальна вартість продукту - " << MIN_COST << L" грн., максимальна вартість продукту - " << MAX_COST << L" грн. Повторіть спробу, будь-ласка.\n";
	}
	else 
	{
		this->products = shop.getProducts();
		bool isExists = false;
		for (auto& product : shop.getProducts()) 
		{
			if (newProduct.getId() == product.getId()) 
			{
				std::wcout << RED << L"Продукт з таким ID вже існує. Повторіть спробу, будь-ласка.\n";
				isExists = true;
				break;
			}
		}
		if (!isExists) 
		{
			this->products.push_back(newProduct);
			shop.setProducts(this->products);
			std::wcout << GRN << L"Новий продукт успішно додано.\n";
		}
	}
}

// Редагувати інформацію про товар
void Admin::editProduct(Shop& shop, int productID)
{
	int customerInput = 0;
	constexpr int NAME_MIN_LENGTH = 5, NAME_MAX_LENGTH = 20;
	constexpr double MIN_COST = 1., MAX_COST = 100000000;
	constexpr int MENU_MIN_SELECTION = 1, MENU_MAX_SELECTION = 2;
	double newCost = 0;
	std::wstring newName;

	this->products = shop.getProducts();

	for (auto& product : this->products) 
	{
		if (product.getId() == productID) 
		{
			std::wcout << WHT
				<< L"╭──────────────────────────────────╮\n"                       
				<< L"│" << RED << L"   Зміна параметрів продукту      " << WHT << L"│\n"
				<< L"├──────────────────────────────────┤\n"
				<< L"│" << CYN << L" 1. " << GRN << L"Назва продукту.               " << WHT << L"│\n"
				<< L"│" << CYN << L" 2. " << GRN << L"Вартість продукту.            " << WHT << L"│\n"
				<< L"│" << CYN << L" 3. " << GRN << L"До попереднього меню.         " << WHT << L"│\n"
				<< L"╰──────────────────────────────────╯\n"
				<< L" Ваш вибір : " << CYN;
			try
			{
				std::wcin >> customerInput;
			}
			catch (std::istream::failure e) {
				system("cls");
				std::wcout << RED << L"Введіть коректні дані.\n";
				std::wcin.clear();
				std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			switch (customerInput) 
			{
			case 1:
				while (true) 
				{
					std::wcout << WHT << L"Введіть нове ім'я продукту: " << CYN;
					std::wcin >> newName;
					if (newName.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::wstring::npos) 
					{
						std::wcout << RED << L"Ім'я продукту містить некоректні символи. Повторіть спробу, будь-ласка.\n";
					}
					else if (newName.size() < NAME_MIN_LENGTH || newName.size() > NAME_MAX_LENGTH) 
					{
						std::wcout << RED << L"Мінімальна довжина імені продукту - " << NAME_MIN_LENGTH << L" символів, максимальна довжина імені - " << NAME_MAX_LENGTH << L" символів. Повторіть спробу, будь-ласка.\n";
					}
					else break;
				}

				product.setName(newName);
				shop.setProducts(this->products);
				std::wcout << GRN << L"Ім'я продукту успішно змінено.\n" 
					<< WHT << L"Нові дані продукту : \nID : " << product.getId()
					<< WHT << L"\nІм'я: " << product.getName()
					<< WHT << L"\nВартість: " << product.getCost() << L" грн.\n";
				break;

			case 2:
				do 
				{
					std::wcout << WHT << L"Введіть нову вартість продукту: " << CYN;
					std::wcin >> newCost;
					if (newCost < MIN_COST || newCost > MAX_COST) 
					{
						std::wcout << RED << L"Мінімальна вартість продукту - " << MIN_COST << L", максимальна - " << MAX_COST << L". Повторіть спробу, будь-ласка.\n";
					}
				} while (newCost < MIN_COST || newCost > MAX_COST);

				product.setCost(newCost);
				shop.setProducts(this->products);
				std::wcout << GRN << L"Вартість продукту успішно змінено.\n"
					<< WHT << L"Нові дані продукту : \nID : " << product.getId()
					<< WHT << L"\nІм'я: " << product.getName()
					<< WHT << L"\nВартість: " << product.getCost() << L" грн.\n";
				break;

			default:
				std::wcout << RED << L"Уп-с! Сталася помилка. Повторіть спробу, будь-ласка.\n";
				break;
			}
		}
	}
}

// Видалити товар
void Admin::delProduct(Shop& shop, int productID)
{
	this->products = shop.getProducts();

	if (this->products.empty())
	{
		std::wcout << RED << L"Наразі у магазині немає продуктів.\n";
	} 
	else 
	{
		for (auto product = this->products.begin(); product != this->products.end(); ++product)
		{
			if (product->getId() == productID) 
			{
				this->products.erase(product);
				shop.setProducts(this->products);
				std::wcout << GRN << L"Товар з ID " << productID << L" був успішно видалений.\n";
				return;
			}
		}
		std::wcout << RED << L"Товар з ID " << productID << L" не знайдено.\n";
	}
}

// Переглянути всі замовлення на всі товари
void Admin::showAllOrders()
{
	bool isExists = true;
	for (auto customer = customers.begin(); customer != customers.end(); ++customer)
	{
		if (customer->getRole() != CUSTOMER_CODE)
		{
			isExists = false;
		}
	}
	if (!isExists)
	{
		std::wcout << RED << L"Наразі у магазині немає покупців.\n";
	}

	if (customers.empty())
	{
		std::wcout << RED << L"Наразі у магазині немає покупців.\n";
	}
	else 
	{
		for (auto& customer : customers) 
		{
			if (customer.getRole() == CUSTOMER_CODE)
			{
				std::wcout << WHT << L"\nСписок продуктів покупця: " << MAG << customer.getLogin() << "\n";
				if (customer.getOrder().getProducts().empty())
				{
					std::wcout << RED << L"Наразі немає поточних замовлень.\n";
				}
				else
				{
					for (auto& product : customer.getOrder().getProducts())
					{
						std::wcout << WHT << L"ID: " << product.getId()
							<< WHT << L"\nІм'я продукту: " << product.getName()
							<< WHT << L"\nВартість: " << product.getCost()
							<< WHT << L"\nАртикль: " << product.getArticle() << '\n';
					}
					std::wcout << WHT << L"Загальна сума замовлення: " << customer.getOrder().getTotalAmount() << '\n';
					if (customer.getOrder().getActive() == true)
					{
						std::wcout << WHT << L"Статус замовлення: Активне.";
					}
					else if (customer.getOrder().getActive() == false)
					{
						std::wcout << WHT << L"Статус замовлення: Неактивне.";
					}
				}
			}
		}
	}
}

// Видалити обране замовлення
void Admin::delOrderById(int orderID)
{
	bool isExists = true;
	for (auto customer = customers.begin(); customer != customers.end(); ++customer)
	{
		if (customer->getRole() != CUSTOMER_CODE)
		{
			isExists = false;
		}
	}
	if (!isExists)
	{
		std::wcout << RED << L"Наразі у магазині немає покупців.\n";
	}

	if (customers.empty())
	{
		std::wcout << RED << L"Наразі у магазині немає користувачів.\n";
	}
	else
	{
		for (auto& customer : customers)
		{
			if (customer.getRole() == CUSTOMER_CODE)
			{
				if (customer.getOrder().getProducts().empty()) {
					std::wcout << RED << L"Наразі немає поточних замовлень.\n";
				}
				else
				{
					for (auto order = customer.getOrder().getProducts().begin(); order != customer.getOrder().getProducts().end(); order++)
					{
						if (order->getId() == orderID)
						{
							customer.getOrder().getProducts().erase(order);
							std::wcout << GRN << L"Замовлення з ID " << orderID << L" було успішно видалено.\n";
							return;
						}
					}
				}
			} 
		}
	}
}

// Видалити всі замовлення певного товару
void Admin::delAllOrdersProduct(int productID)
{
	bool isExists = true;
	for (auto customer = customers.begin(); customer != customers.end(); ++customer)
	{
		if (customer->getRole() != CUSTOMER_CODE)
		{
			isExists = false;
		}
	}
	if (!isExists)
	{
		std::wcout << RED << L"Наразі у магазині немає покупців.\n";
	}

	if (customers.empty())
	{
		std::wcout << RED << L"Наразі у магазині немає користувачів.\n";
	}
	else
	{
		for (auto& customer : customers)
		{
			if (customer.getRole() == CUSTOMER_CODE)
			{
				if (customer.getOrder().getProducts().empty())
				{
					std::wcout << RED << L"Наразі немає поточних замовлень.\n";
				}
				else
				{
					for (auto order = customer.getOrder().getProducts().begin(); order != customer.getOrder().getProducts().end(); ++order)
					{
						for (auto product = this->orders.begin(); product != this->orders.end(); ++product)
						{
							if (product->getId() == productID)
							{
								customer.getOrder().getProducts().erase(order);
								std::wcout << GRN << L"Продукт з ID " << productID << L" було успішно видалено.\n";
								return;
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
	bool isExists = true;
	for (auto customer = customers.begin(); customer != customers.end(); ++customer)
	{
		if (customer->getRole() != CUSTOMER_CODE)
		{
			isExists = false;
		}
	}
	if (!isExists)
	{
		std::wcout << RED << L"Наразі у магазині немає покупців.\n";
	}

	if (customers.empty())
	{
		std::wcout << RED << L"Наразі у магазині немає користувачів.\n";
	}
	else
	{
		for (auto& customer : customers)
		{
			if (customer.getRole() == CUSTOMER_CODE)
			{
				if (this->orders.empty())
				{
					std::wcout << RED << L"Наразі немає поточних замовлень.\n";
				}
				else
				{
					customer.getOrder().getProducts().clear();
					std::wcout << GRN << L"Усі замовлення на усі продукти успішно видалені.\n";
				}
			}
		}
	}
}

// Переглянути всі товари
void Admin::showAllProducts(Shop& shop)
{
	if (shop.getProducts().empty())
	{
		std::wcout << RED << L"Наразі у магазині немає продуктів.\n";
	}
	else
	{
		std::wcout << WHT << L"Список усіх продуктів у магазині\n";
		for (auto& product : shop.getProducts())
		{
			std::wcout << WHT << L"ID: " << product.getId()
				<< WHT << L"\nНазва продукту: " << product.getName()
				<< WHT << L"\nВартість продукту: " << product.getCost()
				<< WHT << L"\nАртикль: " << product.getArticle() << '\n';
		}
	}
}

// Відкрити інформацію про товар
void Admin::showProductInfoById(Shop& shop, int productID)
{
	if (shop.getProducts().empty())
	{
		std::wcout << RED << L"Наразі у магазині немає продуктів.\n";
	}
	else
	{
		for (auto& product : shop.getProducts())
		{
			if (product.getId() == productID)
			{
				std::wcout << GRN << L"Продукт з ID " << productID << L" успішно зайдено.\n"
					<< WHT << L"Інформація про знайдений продукт:\n"
					<< WHT << L"ID: " << product.getId()
					<< WHT << L"\nНазва продукту: " << product.getName()
					<< WHT << L"\nВартість продукту: " << product.getCost()
					<< WHT << L"\nАртикль: " << product.getArticle() << '\n';
			}
		}
	}
}

// Знайти товар за назвою
void Admin::showInfoProductByName(Shop& shop, std::wstring productName)
{
	if (shop.getProducts().empty())
	{
		std::wcout << RED << L"Наразі у магазині немає продуктів.\n";
	}
	else
	{
		for (auto& product : shop.getProducts())
		{
			if (product.getName() == productName)
			{
				std::wcout << GRN << L"Продукт з іменем " << productName << L" успішно зайдено.\n"
					<< WHT << L"Інформація про знайдений продукт:\n"
					<< WHT << L"ID: " << product.getId()
					<< WHT << L"\nНазва продукту: " << product.getName()
					<< WHT << L"\nВартість продукту: " << product.getCost()
					<< WHT << L"\nАртикль: " << product.getArticle() << '\n';
			}
		}
	}
}

// Знайти товар за артиклем
void Admin::showInfoProductByArticle(Shop& shop, std::wstring article)
{
	if (shop.getProducts().empty())
	{
		std::wcout << RED << L"Наразі у магазині немає продуктів.\n";
	}
	else
	{
		for (auto& product : shop.getProducts())
		{
			if (product.getArticle() == article)
			{
				std::wcout << GRN << L"Продукт з артиклем " << article << L" успішно зайдено.\n"
					<< WHT << L"Інформація про знайдений продукт:\n"
					<< WHT << L"ID: " << product.getId()
					<< WHT << L"\nНазва продукту: " << product.getName()
					<< WHT << L"\nВартість продукту: " << product.getCost()
					<< WHT << L"\nАртикль: " << product.getArticle() << '\n';
			}
		}
	}
}