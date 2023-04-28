#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <deque>
#include <Windows.h>
#include <limits>
#include "defines.h"
#include "Admin.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Shop shop;
	Order newOrder;
	Admin admin(ADMIN_ID, ADMIN_CODE, ADMIN_LOGIN, ADMIN_PASSWORD);
	deque<Product> products;
	deque<User> users;
	deque<Customer> customers;

	int autoincrementID;
	string login, password;
	int option;

	string newCustomerLogin, newCustomerPassword, productName, productArticle;
	int customerID = 0, productID = 0, orderID = 0;
	double productCost = 0;

	users.push_back(admin);
	if (!customers.empty()) admin.setCustomers(customers);
	shop.setProducts(products);

	cin.exceptions(cin.failbit);

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
			<< L" Оберіть опцію (1 - 2): ";
		try
		{
			cin >> option;
		}
		catch (istream::failure e) {
			system("cls");
			wcout << RED << L" Введіть коректні дані!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (option)
		{
			case(1):
			{
				system("cls");
				wcout << L"Логін: ";
				cin >> login;
				wcout << L"Пароль: ";
				cin >> password;
				for (auto& user : users) {
					if (user.getLogin() == login && user.getPassword() == password) {
						if (user.getRole() == ADMIN_CODE) {
							option = 0;
							cout << "Ви увійшли, як " << user.getLogin() << "\nРоль: Адміністратор.";
							wcout << L"\nОберіть пункт меню:"
								<< L"\n1. Додати клієнта."
								<< L"\n2. Редагувати інформацію про клієнта."
								<< L"\n3. Видалити клієнта."
								<< L"\n4. Переглянути всі товари."
								<< L"\n5. Знайти товар за назвою."
								<< L"\n6. Знайти товар за артиклем."
								<< L"\n7. Відкрити інформацію про товар."
								<< L"\n8. Додати товар."
								<< L"\n9. Редагувати інформацію про товар."
								<< L"\n10. Видалити товар."
								<< L"\n11. Переглянути всі замовлення на всі товари."
								<< L"\n12. Видалити обране замовлення."
								<< L"\n13. Переглянути всі замовлення певного товару."
								<< L"\n14. Видалити абсолютно всі замовлення на всі товари."
								<< L"\n0. До попереднього меню."
								<< L"\nВаш вибір (0 - 14): ";
							cin >> option;
							switch (option) {
							// 1. Додати клієнта
							case(1): 
								wcout << L"\nВведіть логін нового покупця: ";
								cin >> newCustomerLogin;
								wcout << L"\nВведіть пароль нового покупця: ";
								cin >> newCustomerPassword;
								admin.addCustomer(Customer(1, CUSTOMER_CODE, newCustomerLogin, newCustomerPassword));
								break;
							// 2. Редагувати інформацію про клієнта
							case(2):
								customerID = 0;
								wcout << L"\nВведіть ідентифікатор клієнта: ";
								cin >> customerID;
								admin.editCustomer(customerID);
								break;
							// 3. Видалити клієнта
							case(3):
								customerID = 0;
								wcout << L"\nВведіть ідентифікатор клієнта: ";
								cin >> customerID;
								admin.delCustomer(customerID);
								break;
							// 4. Переглянути всі товари
							case(4):
								admin.showAllProducts();
								break;
							// 5. Знайти товар за назвою
							case(5):
								productName = "";
								wcout << L"\nВведіть назву товару: ";
								cin >> productName;
								admin.showInfoProductByName(productName);
								break;
							// 6. Знайти товар за артиклем
							case(6):
								productArticle = "";
								wcout << L"\nВведіть артикль: ";
								cin >> productArticle;
								admin.showInfoProductByArticle(productArticle);
								break;
							// 7. Відкрити інформацію про товар
							case(7):
								productID = 0;
								wcout << L"Введіть ідентифікатор товару: ";
								cin >> productID;
								admin.showProductInfoById(productID);
								break;
							// 8. Додати товар.
							case(8):
								productName = "";
								productArticle = "";
								productCost = 0;
								wcout << L"\nВведіть назву товару: ";
								cin >> productName;
								wcout << L"\nВведіть артикль для товару: ";
								cin >> productArticle;
								wcout << L"\nВведіть вартість товару: ";
								cin >> productCost;
								admin.addProduct(Product(1, productName, productArticle, productCost));
								break;
							// 9. Редагувати інформацію про товар
							case(9):
								productID = 0;
								wcout << L"Введіть ідентифікатор товару: ";
								cin >> productID;
								admin.editProduct(productID);
								break;
							// 10. Видалити товар.
							case(10):
								productID = 0;
								wcout << L"Введіть ідентифікатор товару: ";
								cin >> productID;
								admin.delProduct(productID);
								break;
							// 11. Переглянути всі замовлення на всі товари.
							case(11):
								admin.showAllOrdersAllProducts();
								break;
							// 12. Видалити обране замовлення
							case(12):
								productID = 0;
								wcout << L"Введіть ідентифікатор товару: ";
								cin >> productID;
								admin.delOrderProduct(productID);
								break;
							// 13. Видалити всі замовлення певного товару
							case(13):
								productID = 0;
								wcout << L"Введіть ідентифікатор товару: ";
								cin >> productID;
								admin.delAllOrdersProduct(productID);
								break;
							// 14. Видалити абсолютно всі замовлення на всі товари
							case(14):
								admin.delAllOrdersAllProducts();
								break;
							// 0. До попереднього меню
							case(0):
								return;
								break;
							default:
								wcout << L"Опцію не знайдено. Повторіть спробу, будь-ласка.\n";
								break;
							}
						} else if (user.getRole() == CUSTOMER_CODE) {
							for (auto& customer : customers) {
								if (user.getLogin() == customer.getLogin() && user.getPassword() == customer.getPassword()) {
									option = 0;
									cout << "Ви увійшли, як " << customer.getLogin() << ".\nРоль: Покупець.";
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
									cin >> option;
									switch (option) {
									// 1. Переглянути всі товари
									case(1):
										customer.showAllProducts();
										break;
									// 2. Знайти товар за назвою
									case(2):
										productName = "";
										wcout << L"\nВведіть назву товару: ";
										cin >> productName;
										customer.showInfoProductByName(productName);
										break;
									// 3. Знайти товар за артиклем
									case(3):
										productArticle = "";
										wcout << L"\nВведіть артикль: ";
										cin >> productArticle;
										customer.showInfoProductByArticle(productArticle);
										break;
									// 4. Відкрити інформацію про товар
									case(4):
										productID = 0;
										wcout << L"Введіть ідентифікатор товару: ";
										cin >> productID;
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
										cin >> orderID;
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
				wcout << L"Вихід...\n";
				return 0;
				break;
			default:
				system("cls");
				wcout << RED << L" Введіть коректні дані!\n";
				break;
			}
		}
	}

	system("pause");
	return 0;
}