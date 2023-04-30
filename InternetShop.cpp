#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <deque>
#include <string>
//#include <Windows.h>
#include <limits>
#include "defines.h"
#include "Admin.h"

using namespace std;

int main()
{
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	Shop shop;
	Order newOrder;
	Admin admin(ADMIN_ID, ADMIN_CODE, ADMIN_LOGIN, ADMIN_PASSWORD);
	deque<Product> products;
	deque<User> users;
	deque<Customer> customers;

	int autoincrementID;
	wstring login, password;
	int option;

	wstring newCustomerLogin, newCustomerPassword, productName, productArticle;
	int customerID = 0, productID = 0, orderID = 0;
	double productCost = 0;

	users.push_back(admin);
	if (!customers.empty()) admin.setCustomers(customers);
	shop.setProducts(products);

	wcin.exceptions(cin.failbit);

	while (true)
	{
		_setmode(_fileno(stdout), _O_WTEXT);

		wcout
			<< WHT
			<< L"╭──────────────────────────────────╮\n"
			<< L"│" << RED << L"              Меню                " << WHT << L"│\n"
			<< L"├──────────────────────────────────┤\n"
			<< L"│" << GRN << L" 1. Авторизація                   " << WHT << L"│\n"
			<< L"│" << GRN << L" 2. Вихід                         " << WHT << L"│\n"
			<< L"╰──────────────────────────────────╯\n"
			<< L" Оберіть опцію (1 - 2): " << CYN;
		try
		{
			wcin >> option;
		}
		catch (istream::failure e) {
			system("cls");
			wcout << RED << L" Введіть коректні дані.\n";
			wcin.clear();
			wcin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (option)
		{
			case(1):
			{
				system("cls");
				wcout << WHT << L"Логін: " << CYN;
				wcin >> login;
				wcout << WHT << L"Пароль: " << CYN;
				wcin >> password;
				system("cls");
				for (auto& user : users) {
					if (user.getLogin() == login /*&& user.getPassword() == password*/) {
						if (user.getRole() == ADMIN_CODE) {
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
								catch (istream::failure e) {
									system("cls");
									wcout << RED << L" Введіть коректні дані.\n";
									wcin.clear();
									wcin.ignore(numeric_limits<streamsize>::max(), '\n');
									continue;
								}

								switch (option) {
									// 1. Додати клієнта
								case(1):
									wcout << WHT << L"\nВведіть логін нового покупця: " << CYN;
									wcin >> newCustomerLogin;
									wcout << WHT << L"\nВведіть пароль нового покупця: " << CYN;
									wcin >> newCustomerPassword;
									admin.addCustomer(Customer(1, CUSTOMER_CODE, newCustomerLogin, newCustomerPassword));
									system("cls");
									wcout << GRN << L"\nПокупця " << MAG << newCustomerLogin << WHT << L" додано!\n";
									break;
									// 2. Редагувати інформацію про клієнта
								case(2):
									customerID = 0;
									wcout << WHT << L"\nВведіть ідентифікатор клієнта: " << CYN;
									wcin >> customerID;
									admin.editCustomer(customerID);
									break;
									// 3. Видалити клієнта
								case(3):
									customerID = 0;
									wcout << WHT << L"\nВведіть ідентифікатор клієнта: " << CYN;
									wcin >> customerID;
									admin.delCustomer(customerID);
									break;
									// 4. Переглянути всі товари
								case(4):
									admin.showAllProducts();
									break;
									// 5. Знайти товар за назвою
								case(5):
									productName = L"";
									wcout << WHT << L"\nВведіть назву товару: " << CYN;
									wcin >> productName;
									admin.showInfoProductByName(productName);
									break;
									// 6. Знайти товар за артиклем
								case(6):
									productArticle = L"";
									wcout << WHT << L"\nВведіть артикль: " << CYN;
									wcin >> productArticle;
									admin.showInfoProductByArticle(productArticle);
									break;
									// 7. Відкрити інформацію про товар
								case(7):
									productID = 0;
									wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
									wcin >> productID;
									admin.showProductInfoById(productID);
									break;
									// 8. Додати товар.
								case(8):
									productName = L"";
									productArticle = L"";
									productCost = 0;
									wcout << WHT << L"\nВведіть назву товару: " << CYN;
									wcin >> productName;
									wcout << WHT << L"\nВведіть артикль для товару: " << CYN;
									wcin >> productArticle;
									wcout << WHT << L"\nВведіть вартість товару: " << CYN;
									wcin >> productCost;
									admin.addProduct(Product(1, productName, productArticle, productCost));
									break;
									// 9. Редагувати інформацію про товар
								case(9):
									productID = 0;
									wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
									wcin >> productID;
									admin.editProduct(productID);
									break;
									// 10. Видалити товар.
								case(10):
									productID = 0;
									wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
									wcin >> productID;
									admin.delProduct(productID);
									break;
									// 11. Переглянути всі замовлення на всі товари.
								case(11):
									admin.showAllOrdersAllProducts();
									break;
									// 12. Видалити обране замовлення
								case(12):
									productID = 0;
									wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
									wcin >> productID;
									admin.delOrderProduct(productID);
									break;
									// 13. Видалити всі замовлення певного товару
								case(13):
									productID = 0;
									wcout << WHT << L"Введіть ідентифікатор товару: " << CYN;
									wcin >> productID;
									admin.delAllOrdersProduct(productID);
									break;
									// 14. Видалити абсолютно всі замовлення на всі товари
								case(14):
									admin.delAllOrdersAllProducts();
									break;
									// 0. До попереднього меню
								case(0):
									break;
								default:
									system("cls");
									wcout << RED << L" Опцію не знайдено. Повторіть спробу, будь-ласка.\n";
									break;
								}
							}
						} else if (user.getRole() == CUSTOMER_CODE) {
							for (auto& customer : customers) {
								if (user.getLogin() == customer.getLogin() && user.getPassword() == customer.getPassword()) {
									option = 0;
									wcout << "Ви увійшли, як " << customer.getLogin() << L".\nРоль: Покупець.";
									wcout << L"Оберіть дію:"
										<< L"\n1. Переглянути всі товари."
										<< L"\n2. Знайти товар за назвою."
										<< L"\n3. Знайти товар за артиклем."
										<< L"\n4. Відкрити інформацію про товар."
										<< L"\n5. Купити товар."
										<< L"\n6. Переглянути свої замовлення."
										<< L"\n7. Відмовитися від замовлення."
										<< L"\n0. До попереднього меню."
										<< L"\nВаш вибір (0 - 7): ";
									wcin >> option;
									switch (option) {
									// 1. Переглянути всі товари
									case(1):
										customer.showAllProducts();
										break;
									// 2. Знайти товар за назвою
									case(2):
										productName = L"";
										wcout << L"\nВведіть назву товару: ";
										wcin >> productName;
										customer.showInfoProductByName(productName);
										break;
									// 3. Знайти товар за артиклем
									case(3):
										productArticle = L"";
										wcout << L"\nВведіть артикль: ";
										wcin >> productArticle;
										customer.showInfoProductByArticle(productArticle);
										break;
									// 4. Відкрити інформацію про товар
									case(4):
										productID = 0;
										wcout << L"Введіть ідентифікатор товару: ";
										wcin >> productID;
										customer.showInfoProduct(productID);
										break;
									// 5. Купити товар
									case(5):
										// ДОПИЛИТЬ НОРМАЛЬНУЮ ПОКУПКУ
										break;
									// 6. Переглянути свої замовлення
									case(6):
										customer.getOrders();
										break;
									// 7. Відмовитися від замовлення
									case(7):
										orderID = 0;
										wcout << L"Введіть ідентифікатор замовлення: ";
										wcin >> orderID;
										customer.cancelOrder(orderID);
										break;
									// 0. До попереднього меню
									case(0):
										break;
									}
								}
							}
						}
					}
				}
				break;
			}
			case(2):
			{
				system("cls");
				wcout << CYN << L"Вихід...\n";
				return 0;
				break;
			default:
				system("cls");
				wcout << RED << L" Опцію не знайдено. Повторіть спробу, будь-ласка.\n";
				break;
			}
		}
	}

	system("pause");
	return 0;
}