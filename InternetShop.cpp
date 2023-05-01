#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <deque>
#include <array>
#include <string>
#include <limits>
#include <algorithm>
#include "defines.h"
#include "Admin.h"

using namespace std;

// Масив символів, що повинні валідуватися
const std::array<wchar_t, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','№','?' };

int main()
{
	srand((unsigned int)time(nullptr));

	Shop shop;
	Order newOrder;
	Admin admin(ADMIN_ID, ADMIN_CODE, ADMIN_LOGIN, ADMIN_PASSWORD);
	Customer customer;
	deque<Product> products;
	deque<User> users;

	wstring login, password;
	int option;

	wstring newCustomerLogin, newCustomerPassword, productName, productArticle;
	int customerID = 0, productID = 0, orderID = 0, startID = 1;
	double productCost = 0;
	bool isExists = false;

	users.push_back(admin);
	if (!shop.getProducts().empty()) shop.setProducts(products);

	wcin.exceptions(cin.failbit);

	while (true)
	{
		_setmode(_fileno(stdout), _O_WTEXT);

		wcout
			<< WHT
			<< L"╭──────────────────────────────────╮\n"
			<< L"│" << RED << L"              Меню                " << WHT << L"│\n"
			<< L"├──────────────────────────────────┤\n"
			<< L"│" << CYN << L" 1. " << GRN << L"Авторизація                   " << WHT << L"│\n"
			<< L"│" << CYN << L" 2. " << GRN << L"Вихід                         " << WHT << L"│\n"
			<< L"╰──────────────────────────────────╯\n"
			<< L" Оберіть опцію (1 - 2): " << CYN;
		try
		{
			wcin >> option;
		}
		catch (istream::failure e) {
			std::system("cls");
			wcout << RED << L" Введіть коректні дані.\n";
			wcin.clear();
			wcin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (option)
		{
			case(1):
			{
				std::system("cls");
				wcout << WHT << L"Логін: " << CYN;
				wcin >> login;
				wcout << WHT << L"Пароль: " << CYN;
				wcin >> password;
				std::system("cls");

				for (auto& user : users)
				{
					if (user.getLogin() == login && user.getPassword() == password)
					{
						isExists = true;
						if (user.getRole() == ADMIN_CODE && isExists)
						{
							while (true)
							{
								wcout
									<< WHT
									<< L"╭──────────────────────────────────────────────────────────╮\n"
									<< L"│" << RED << L"                 Адміністратор: " << MAG << user.getLogin() << "                     " << WHT << L"│\n"
									<< L"├──────────────────────────────────────────────────────────┤\n"
									<< L"│" << CYN << L" 1. " << GRN << L" Додати клієнта.										" << WHT << L"│\n"
									<< L"│" << CYN << L" 2. " << GRN << L" Редагувати інформацію про клієнта.					" << WHT << L"│\n"
									<< L"│" << CYN << L" 3. " << GRN << L" Видалити клієнта.									" << WHT << L"│\n"
									<< L"│" << CYN << L" 4. " << GRN << L" Переглянути всі товари.								" << WHT << L"│\n"
									<< L"│" << CYN << L" 5. " << GRN << L" Знайти товар за назвою.								" << WHT << L"│\n"
									<< L"│" << CYN << L" 6. " << GRN << L" Знайти товар за артиклем.							" << WHT << L"│\n"
									<< L"│" << CYN << L" 7. " << GRN << L" Відкрити інформацію про товар.						" << WHT << L"│\n"
									<< L"│" << CYN << L" 8. " << GRN << L" Додати товар.										" << WHT << L"│\n"
									<< L"│" << CYN << L" 9. " << GRN << L" Редагувати інформацію про товар.						" << WHT << L"│\n"
									<< L"│" << CYN << L" 10." << GRN << L" Видалити товар.										" << WHT << L"│\n"
									<< L"│" << CYN << L" 11." << GRN << L" Переглянути всі замовлення на всі товари.			" << WHT << L"│\n"
									<< L"│" << CYN << L" 12." << GRN << L" Видалити обране замовлення.							" << WHT << L"│\n"
									<< L"│" << CYN << L" 13." << GRN << L" Переглянути всі замовлення певного товару.			" << WHT << L"│\n"
									<< L"│" << CYN << L" 14." << GRN << L" Видалити абсолютно всі замовлення на всі товари.		" << WHT << L"│\n"
									<< L"│" << CYN << L" 0. " << GRN << L" До попереднього меню.								" << WHT << L"│\n"
									<< L"╰──────────────────────────────────────────────────────────╯\n"
									<< L" Оберіть опцію (0 - 14): " << CYN;

								try
								{
									wcin >> option;
								}
								catch (istream::failure e)
								{
									std::system("cls");
									wcout << RED << L" Введіть коректні дані.\n";
									wcin.clear();
									wcin.ignore(numeric_limits<streamsize>::max(), '\n');
									continue;
								}

								switch (option) {
									// 1. Додати клієнта
								case(1):
									std::system("cls");

									wcout << WHT << L"Введіть логін нового покупця: " << CYN;
									wcin >> newCustomerLogin;
									wcout << WHT << L"Введіть пароль нового покупця: " << CYN;
									wcin >> newCustomerPassword;

									admin.addCustomer(User(admin.getUsers().back().getId() + 1, CUSTOMER_CODE, newCustomerLogin, newCustomerPassword));

									///////////////////////////////
									wcout << L"USERS\n";
									for (auto& c : admin.getUsers()){
										wcout << L"id: " << c.getId() << '\n';
										wcout << L"login: " << c.getLogin() << '\n';
										wcout << L"pass: " << c.getPassword() << '\n';
										wcout << L"role: " << c.getRole() << '\n';
									}
									//////////////////////////////

									std::system("pause");
									std::system("cls");

									break;
									// 2. Редагувати інформацію про клієнта
								case(2):
									std::system("cls");

									customerID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор клієнта: " << CYN;
										wcin >> customerID;
										if (customerID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (customerID < 0);

									admin.editCustomer(customerID);

									std::system("pause");
									std::system("cls");
									break;
									// 3. Видалити клієнта
								case(3):
									std::system("cls");

									customerID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор клієнта: " << CYN;
										wcin >> customerID;
										if (customerID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (customerID < 0);

									admin.delCustomer(customerID);

									std::system("pause");
									std::system("cls");
									break;
									// 4. Переглянути всі товари
								case(4):
									std::system("cls");

									admin.showAllProducts();

									std::system("pause");
									std::system("cls");
									break;
									// 5. Знайти товар за назвою
								case(5):
									std::system("cls");

									productName = L"";
									wcout << WHT << L"Введіть назву товару: " << CYN;
									wcin >> productName;

									admin.showInfoProductByName(productName);

									std::system("pause");
									std::system("cls");
									break;
									// 6. Знайти товар за артиклем
								case(6):
									std::system("cls");

									productArticle = L"";
									wcout << WHT << L"Введіть артикль: " << CYN;
									wcin >> productArticle;

									admin.showInfoProductByArticle(productArticle);

									std::system("pause");
									std::system("cls");
									break;
									// 7. Відкрити інформацію про товар
								case(7):
									std::system("cls");

									productID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
										wcin >> productID;
										if (productID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (productID < 0);

									admin.showProductInfoById(productID);

									std::system("pause");
									std::system("cls");
									break;
									// 8. Додати товар.
								case(8):
									std::system("cls");

									productName = L"";
									productArticle = L"";
									productCost = 0;
									wcout << WHT << L"Введіть назву товару: " << CYN;
									wcin >> productName;
									wcout << WHT << L"Введіть артикль для товару: " << CYN;
									wcin >> productArticle;

									do
									{
										wcout << WHT << L"Введіть вартість товару: " << CYN;
										wcin >> productCost;
										if (productCost < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (productCost < 0);

									if (shop.getProducts().empty()) {
										admin.addProduct(Product(startID, productName, productArticle, productCost));
									}
									else {
										admin.addProduct(Product(shop.getProducts().back().getId() + 1, productName, productArticle, productCost));
									}

									std::system("pause");
									std::system("cls");
									break;
									// 9. Редагувати інформацію про товар
								case(9):
									std::system("cls");

									productID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
										wcin >> productID;
										if (productID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (productID < 0);

									admin.editProduct(productID);

									std::system("pause");
									std::system("cls");
									break;
									// 10. Видалити товар.
								case(10):
									std::system("cls");

									productID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
										wcin >> productID;
										if (productID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (productID < 0);

									admin.delProduct(productID);

									std::system("pause");
									std::system("cls");
									break;
									// 11. Переглянути всі замовлення на всі товари.
								case(11):
									std::system("cls");

									admin.showAllOrdersAllProducts();

									std::system("pause");
									std::system("cls");
									break;
									// 12. Видалити обране замовлення
								case(12):
									std::system("cls");

									productID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
										wcin >> productID;
										if (productID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (productID < 0);

									admin.delOrderProduct(productID);

									std::system("pause");
									std::system("cls");
									break;
									// 13. Видалити всі замовлення певного товару
								case(13):
									std::system("cls");

									productID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
										wcin >> productID;
										if (productID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (productID < 0);

									admin.delAllOrdersProduct(productID);

									std::system("pause");
									std::system("cls");
									break;
									// 14. Видалити абсолютно всі замовлення на всі товари
								case(14):
									std::system("cls");

									admin.delAllOrdersAllProducts();

									std::system("pause");
									std::system("cls");
									break;
									// 0. До попереднього меню
								case(0):
									system("cls");
									break;
								default:
									std::system("cls");
									wcout << RED << L" Опцію не знайдено. Повторіть спробу, будь-ласка.\n";
									break;
								}

								if (option == 0) {
									break;
								}
							}
						}
						else if (user.getRole() == CUSTOMER_CODE)
						{
							while (true)
							{
								option = 0;
								wcout
									<< WHT
									<< L"╭──────────────────────────────────────────────────────────╮\n"
									<< L"│" << RED << L"                 Покупець: " << MAG << user.getLogin() << "							" << WHT << L"│\n"
									<< L"├──────────────────────────────────────────────────────────┤\n"
									<< L"│" << CYN << L" 1. " << GRN << L" Переглянути всі товари.										" << WHT << L"│\n"
									<< L"│" << CYN << L" 2. " << GRN << L" Знайти товар за назвою.										" << WHT << L"│\n"
									<< L"│" << CYN << L" 3. " << GRN << L" Знайти товар за артиклем.									" << WHT << L"│\n"
									<< L"│" << CYN << L" 4. " << GRN << L" Відкрити інформацію про товар.								" << WHT << L"│\n"
									<< L"│" << CYN << L" 5. " << GRN << L" Купити товар.												" << WHT << L"│\n"
									<< L"│" << CYN << L" 6. " << GRN << L" Переглянути свої замовлення.									" << WHT << L"│\n"
									<< L"│" << CYN << L" 7. " << GRN << L" Відмовитися від замовлення.									" << WHT << L"│\n"
									<< L"│" << CYN << L" 0. " << GRN << L" До попереднього меню.										" << WHT << L"│\n"
									<< L"╰──────────────────────────────────────────────────────────╯\n"
									<< L" Оберіть опцію (0 - 7): " << CYN;

								try
								{
									wcin >> option;
								}
								catch (istream::failure e)
								{
									std::system("cls");
									wcout << RED << L" Введіть коректні дані.\n";
									wcin.clear();
									wcin.ignore(numeric_limits<streamsize>::max(), '\n');
									continue;
								}

								switch (option) {
									// 1. Переглянути всі товари
								case(1):
									std::system("cls");

									customer.showAllProducts();

									std::system("pause");
									std::system("cls");
									break;
									// 2. Знайти товар за назвою
								case(2):
									std::system("cls");

									productName = L"";
									wcout << WHT << L"Введіть назву товару: ";
									wcin >> productName;

									customer.showInfoProductByName(productName);

									std::system("pause");
									std::system("cls");
									break;
									// 3. Знайти товар за артиклем
								case(3):
									std::system("cls");

									productArticle = L"";
									wcout << WHT << L"Введіть артикль: ";
									wcin >> productArticle;

									customer.showInfoProductByArticle(productArticle);

									std::system("pause");
									std::system("cls");
									break;
									// 4. Відкрити інформацію про товар
								case(4):
									std::system("cls");

									productID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
										wcin >> productID;
										if (productID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (productID < 0);

									customer.showInfoProduct(productID);

									std::system("pause");
									std::system("cls");
									break;
									// 5. Купити товар
								case(5):
									// ДОПИЛИТЬ НОРМАЛЬНУЮ ПОКУПКУ
									break;
									// 6. Переглянути свої замовлення
								case(6):
									std::system("cls");

									customer.getOrders();

									std::system("pause");
									std::system("cls");
									break;
									// 7. Відмовитися від замовлення
								case(7):
									std::system("cls");

									orderID = 0;
									do
									{
										wcout << WHT << L"Введіть ідентифікатор замовлення: " << CYN;
										wcin >> orderID;
										if (orderID < 0)
										{
											wcout << RED << L" Введіть коректні дані.\n";
										}
									} while (orderID < 0);

									customer.cancelOrder(orderID);

									std::system("pause");
									std::system("cls");
									break;
									// 0. До попереднього меню
								case(0):
									system("cls");
									break;
								}

								if (option == 0) {
									break;
								}
							}
						}
					}
					else 
					{
						wcout << RED << L"Користувача з такими даними не знайдено. Повторіть спробу, будь-ласка.\n";
					}
				}
			}
			break;
			case(2):
			{
				std::system("cls");
				wcout << CYN << L"Вихід...\n" << WHT;
				break;
			default:
				std::system("cls");
				wcout << RED << L" Опцію не знайдено. Повторіть спробу, будь-ласка.\n";
				break;
			}
		}
	}

	std::system("pause");
	return 0;
}