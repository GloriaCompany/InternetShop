﻿#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "defines.h"
using namespace std;

int main()
{
	string login, password;
	int option;
	cin.exceptions(cin.failbit);

	while (true)
	{
		_setmode(_fileno(stdout), _O_WTEXT);
		wcout
			<< WHT
			<< L"╭──────────────────────────────────╮\n"
			<< L"│" << RED << L"              Меню                " << WHT << L"│\n"
			<< L"├──────────────────────────────────┤\n"
			<< L"│" << GRN << L" 1. Реєстрація                    " << WHT << L"│\n"
			<< L"│" << GRN << L" 2. Вхід                          " << WHT << L"│\n"
			<< L"│" << GRN << L" 3. Вихід                         " << WHT << L"│\n"
			<< L"╰──────────────────────────────────╯\n"
			<< L" Оберіть опцію(1 - 3): ";
		try
		{
			cin >> option;
		}
		catch (istream::failure e) {
			system("cls");
			wcout << RED << L" Введіть коректні дані!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		//Красиво, но не функционально, conio.h
		/*option = _getche();
		wcout
			<< L"          │\n"
			<< L"╰──────────────────────────────────╯\n";*/

		switch (option)
		{
		case(1):
		{
			system("cls");
			wcout << "case1\n";
			break;
		}
		case(2):
		{
			// Меню авторизації
			system("cls");
			wcout << L"╭──────────────────────────────────╮\n";
			wcout << L"│" << RED << L"	 Вхід в систему " << WHT << L"	   │\n";
			wcout << L"├──────────────────────────────────┤\n";
			wcout << L"│" << GRN << L" 1. Вхід як адміністратор" << WHT << L"	   │\n";
			wcout << L"│" << GRN << L" 2. Вхід як клієнт" << WHT << L"		   │\n";
			wcout << L"╰──────────────────────────────────╯\n";
			int option;
			wcout << L"Введіть номер опції: ";
			cin >> option;

			// Авторизація адміна 
			if (option == 1) {
				string loginAdmin = "admin";
				string passwordAdmin = "adminadmin";

				string login;
				string password;

				system("cls");
				wcout << L"╭──────────────────────────────────╮\n";
				wcout << L"│" << RED << L"           Вхід в систему         " << WHT << L"│\n";
				wcout << L"├──────────────────────────────────┤\n";
				wcout << L"│" << GRN << L" Login:";
				cin >> login;
				wcout << WHT;
				wcout << L"│" << GRN << L" Password:";
				cin >> password;
				wcout << WHT;
				wcout << L"╰──────────────────────────────────╯\n";

				if (login == loginAdmin && password == passwordAdmin) {
					wcout << GRN << L" Успішний вхід в систему!\n" << WHT;
				}
				else {
					wcout << RED << L" Невірний логін або пароль!\n" << WHT;
				}
			}

			// Авторизація клієнта
			else if (option == 2) {
				string loginCustomer = "customer";
				string passwordCustomer = "customercustomer";

				string login;
				string password;

				system("cls");
				wcout << L"╭──────────────────────────────────╮\n";
				wcout << L"│" << RED << L"           Вхід в систему         " << WHT << L"│\n";
				wcout << L"├──────────────────────────────────┤\n";
				wcout << L"│" << GRN << L" Login:";
				cin >> login;
				wcout << WHT;
				wcout << L"│" << GRN << L" Password:";
				cin >> password;
				wcout << WHT;
				wcout << L"╰──────────────────────────────────╯\n";

				if (login == loginCustomer && password == passwordCustomer) {
					wcout << GRN << L" Успішний вхід в систему!\n" << WHT;
				}
				else {
					wcout << RED << L" Невірний логін або пароль!\n" << WHT;
				}
			}
		case(3):
		{
			system("pause");
			return 0;
			break;
		}
		default:
			system("cls");
			wcout << RED << L" Введіть коректні дані!\n";
			break;
		}
		}

		
	}
	return 0;
}