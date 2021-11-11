#include <iostream>

using namespace std;

int main()
{
	cout << " Exercise 7.5.6\n";
	cout << " Rewrite the following code fragment so that a switch is used instead of the if/else statements.\n";
	cout << '\n';
	{
		int value;
		char ch;
		std::cin >> ch;
		switch (ch)
		{
		case 'A':
			value = 10;
			break;
		case 'P':
			value = 20;
			break;
		case 'T':
			value = 30;
			break;
		case 'V':
			value = 40;
			break;
		default:
			value = 50;
			break;
		}
		std::cout << value << '\n';
	}
	cout << '\n';

	cout << " Exercise 7.5.7\n";
	cout << " Rewrite the following code fragment so that a multi-way if/else is used instead of the switch statement.\n";
	cout << '\n';
	{
		int value;
		char ch;
		std::cin >> ch;
		if ('A' == ch)
			value = 10;
		else if ('P' == ch)
			std::cin >> value;
		else if ('T' == ch)
			value = ch;
		else if ('V' == ch)
			value = ch + 1000;
		else
			value = 50;
		std::cout << value << '\n';
	}
	cout << '\n';

	cout << " Exercise 7.5.8\n";
	cout << " Rewrite the following code fragment so that a multi-way if/else is used instead of the switch statement.\n";
	cout << '\n';
	{
		int value = 0;
		char ch;
		std::cin >> ch;
		if ('A' == ch)
		{
			std::cout << ch << '\n';
			value = 10;
		}
		else if('P' == ch || 'E' == ch)
			std::cin >> value;
		else if ('T' == ch)
		{
			std::cin >> ch;
			value = ch;
			std::cout << "value=" << value << ", ch=" << ch << '\n';
		}
		else if ('C' == ch)
		{
			value = ch;
			std::cout << "value=" << value << ", ch=" << ch << '\n';
		}
		else if('V' == ch)
			value = ch + 1000;
		std::cout << value << '\n';
	}
	cout << '\n';

	cout << " Exercise 7.5.9\n";
	cout << " Rewrite the following code fragment so a while loop is used instead of the for statement.\n";
	cout << '\n';
	{
		int i = 100;
		while (i > 0)
		{
			std::cout << i << '\n';
			i--;
		}
	}
	cout << '\n';

	cout << " Exercise 7.5.10\n";
	cout << " Rewrite the following code fragment so that it uses the conditional operator instead of an if statement.\n";
	cout << '\n';
	{
		int value = 0;
		value % 2 != 0 ? value += 1 : value += 0;
	}
	cout << '\n';

	cout << " Exercise 7.5.11\n";
	cout << " Rewrite the following code fragment so that it uses the conditional operator instead of an if/else statement.\n";
	cout << '\n';
	{
		int value = 0;
		value % 2 == 0 ? value = 0 : value += 1;
	}
	cout << '\n';

	return 0;
}