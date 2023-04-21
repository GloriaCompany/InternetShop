#include <iostream>
#include <io.h>
#include <fcntl.h>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define WHT "\033[0;37m"

using namespace std;

int main()
{
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
			wcout << RED << L" Введіть коректні дані!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			break;
		}
		case(2):
		{
			break;
		}
		case(3):
		{
			system("pause");
			return 0;
			break;
		}
		default:
			wcout << RED << L" Введіть коректні дані!\n";
			break;
		}
    }

    return 0;
}