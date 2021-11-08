#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	cout << " Exercise 6.6.3\n";
	cout << " Use a loop to rewrite the following code fragment so that it uses just one std::cout and one '\\n'.\n";
	cout << '\n';
	{
		int number = 1;
		while (number <= 8)
			cout << setw(2) << number++ * 2 << '\n';
	}
	cout << '\n';

	cout << " Exercise 6.6.14\n";
	cout << " Rewrite the following code fragment using a break statement and eliminating the done variable.\n";
	cout << '\n';
	{
		int n = 0, m = 100;
		while (n != m)
		{
			std::cin >> n;
			std::cout << "n = " << n << '\n';
			if (n < 0)
				break;
		}
	}
	cout << '\n';

	cout << " Exercise 6.6.15\n";
	cout << " Rewrite the following code fragment so it eliminates the continue statement.\n";
	cout << '\n';
	{
		int x = 100, y;
		while (x > 0)
		{
			std::cin >> y;
			if (y == 25)
			{
				x--;
			}
			else
			{
				std::cin >> x;
				std::cout << "x = " << x << '\n'; 
			}
		}
	}
	cout << '\n';

	cout << " Exercise 6.6.16\n";
	cout << " Suppose you were given some code from the 1960s in a language that did not support\n"
		<< " structured statements like while. Your task is to modernize it and adapt it to C++.\n"
		<< " The following code fragment has been adapted to C++ already, but you must now\n"
		<< " structure it with a while statement to replace the gotos.\n"
		<< " Your code should be goto free and still behave identically to this code fragment.\n";
	cout << '\n';
	{
		int i = 0;
		while (i < 10)
		{
			cout << i << '\n';
			i++;
		}
	}
	cout << '\n';
	
	cout << " Exercise 6.6.18\n";
	cout << " Write a C++ program that accepts a single integer value entered by the user.\n"
		<< " If the value entered is less than one, the program prints nothing.\n"
		<< " If the user enters a positive integer, n, the program prints an n×n box drawn with * characters.\n";
	cout << '\n';
	{
		int n = 0;
		cout << "Enter size of box: ";
		cin >> n;
		if (n >= 1)
		{
			int i = 1, j = 1;
			while (i <= n)
			{
				while (j <= n)
				{
					cout << '*';
					++j;
				}
				++i;
				j = 1;
				cout << '\n';
			}
		}

	}
	cout << '\n';
	
	cout << " Exercise 6.6.19\n";
	cout << " Write a C++ program that allows the user to enter exactly twenty double-precision\n"
		<< " floating - point values. The program then prints the sum,\n"
		<< " average(arithmetic mean), maximum, and minimum of the values entered.\n";
	cout << '\n';
	{
		double n = 0.0;
		double sum = 0.0;
		double average = 0.0;
		double max = 0.0;
		double min = 0.0;
		int i = 1;
		while (i <= 20)
		{
			cout << "Give the " << i;
			if (1 == i)
				cout << "st ";
			else if (2 == i)
				cout << "nd ";
			else
				cout << "th ";
			cout << "number: ";
			cin >> n;
			sum += n;
			if (min > n)
				min = n;
			if (max < n)
				max = n;
			++i;
		}
		average = sum / 20.0;
		cout << "The sum is: " << sum << '\n';
		cout << "The average is: " << average << '\n';
		cout << "The maximum is: " << max << '\n';
		cout << "The minimum is: " << min << '\n';
	}
	cout << '\n';
	
	cout << " Exercise 6.6.20\n";
	cout << " Write a C++ program that allows the user to enter any number of nonnegative double-precision\n"
		<< " floating - point values. The user terminates the input list with any negative value.\n"
		<< " The program then prints the sum, average(arithmetic mean), maximum, and minimum\n"
		<< " of the values entered. The terminating negative value is not used in the computations.\n";
	cout << '\n';
	{
		double n = 0.0;
		double sum = 0.0;
		double average = 0.0;
		double max = 0.0;
		double min = LLONG_MAX;
		int i = 1;
		while (n >= 0.0)
		{
			cout << "Give the " << i;
			if (1 == i)
				cout << "st ";
			else if (2 == i)
				cout << "nd ";
			else
				cout << "th ";
			cout << "number: ";
			cin >> n;
			if (n < 0.0)
				break;
			sum += n;
			if (min > n)
				min = n;
			if (max < n)
				max = n;
			++i;
		}
		average = sum / --i;
		cout << "The sum is: " << sum << '\n';
		cout << "The average is: " << average << '\n';
		cout << "The maximum is: " << max << '\n';
		cout << "The minimum is: " << min << '\n';
	}
	cout << '\n';
	
	cout << " Exercise 6.6.21\n";
	cout << " Redesign Listing 6.21 (startree.cpp) so that it draws a sideways tree pointing right.\n";
	cout << '\n';
	{
		int height;
		cout << "Enter height of tree: ";
		cin >> height;
		int row = 1;
		int column = 1;
		while (row <= 2 * height)
		{
			if (row <= height)
			{
				column = 1;
				while (column <= row)
				{
					cout << '*';
					++column;
				}
				cout << '\n';
			}
			else
			{
				column = 2 * height - row;
				while (column >= 1)
				{
					cout << '*';
					--column;
				}
				cout << '\n';
			}
			++row;
		}
	}
	cout << '\n';
	
	cout << " Exercise 6.6.22\n";
	cout << " Redesign Listing 6.21 (startree.cpp) so that it draws a sideways tree pointing left.\n";
	cout << '\n';
	{
		int height;
		cout << "Enter height of tree: ";
		cin >> height;
		int row = 1;
		int starNumber = 1;
		int spaceNumber = 1;
		while (row < 2 * height)
		{
			if (row <= height)
			{
				spaceNumber = height - row;
				while (spaceNumber >= 1)
				{
					cout << ' ';
					--spaceNumber;
				}
				spaceNumber = 1;
				
				starNumber = 1;
				while (starNumber <= row)
				{
					cout << '*';
					++starNumber;
				}
				cout << '\n';
				starNumber = 1;
			}
			else
			{
				starNumber = 2 * height - row;
				spaceNumber = height - starNumber;
				while (spaceNumber >= 1)
				{
					cout << ' ';
					--spaceNumber;
				}
				
				while (starNumber >= 1)
				{
					cout << '*';
					--starNumber;
				}
				cout << '\n';
			}
			++row;
		}
	}
	cout << '\n';

	return 0;
}