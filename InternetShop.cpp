#include <iostream>
#include <io.h>
#include <fcntl.h>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

using namespace std;

int main()
{
    int option;
    while (true)
    {
		_setmode(_fileno(stdout), _O_WTEXT);
		wcout
			<< L"╭──────────────────────────────────╮\n"
			<< L"│\033[0;31m              Меню                \033[0;37m│\n"
			<< L"├──────────────────────────────────┤\n"
			<< L"│\033[0;32m 1. Реєстрація                    \033[0;37m│\n"
			<< L"│\033[0;32m 2. Вхід                          \033[0;37m│\n"
			<< L"│\033[0;32m 3. Вихід                         \033[0;37m│\n"
			<< L"╰──────────────────────────────────╯\n"
			<< L" Оберіть опцію(1 - 3): ";
		/*wcout
			<< L"╭──────────────────────────────────╮\n"
			<< L"│" 
			<< "\033[0;31m"
			 << L"               Меню               "
			<< L"\033[0;37m"					<< "│\n"
			<< L"├──────────────────────────────────┤\n"
			<< L"│ 1. Реєстрація                    │\n"
			<< L"│ 2. Вхід                          │\n"
			<< L"│ 3. Вихід                         │\n"
			<< L"╰──────────────────────────────────╯\n"
			<< L" Оберіть опцію(1 - 3): ";*/
		cin >> option;

		switch (option)
		{
		case(1):
		{
			cout << "a";
			break;
		}
		case(2):
		{

			break;
		}
		case(3):
		{

			break;
		}
		case(4):
		{

			break;
		}
		default:
			break;
		}
    }

	system("pause");
    return 0;
}