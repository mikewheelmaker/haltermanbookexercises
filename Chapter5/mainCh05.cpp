#include <iostream>
#include <stdbool.h>

using std::cout;
using std::cin;

int main()
{
	cout << " Exercise 5.10.12\n";
	cout << " Write a C++ program that requests an integer value from the user.\n"
		<< " If the value is between 1 and 100 inclusive, print \"OK\"\n"
		<< " otherwise, do not print anything.\n";
	cout << '\n';
	{
		int value = -1;
		cout << "Please give a value in the range 1..100: ";
		cin >> value;
		if (1 <= value && 100 >= value)
		{
			cout << "OK\n";
		}
	}
	cout << '\n';

	cout << " Exercise 5.10.13\n";
	cout << " Write a C++ program that requests an integer value from the user.\n"
		<< " If the value is between 1 and 100 inclusive, print \"OK\"\n"
		<< " otherwise, print \"Out of range\".\n";
	cout << '\n';
	{
		int value = -1;
		cout << "Please give a value in the range 1..100: ";
		cin >> value;
		if (1 <= value && 100 >= value)
		{
			cout << "OK\n";
		}
		else
		{
			cout << "Out of range\n";
		}
	}
	cout << '\n';

	cout << " Exercise 5.10.14\n";
	cout << " The following program attempts to print a message containing\n"
		<< " the English word corresponding to a given integer input.\n"
		<< " For example, if the user enters the value 3, the program should print\n"
		<< " \"You entered a three\". In its current state, the program contains logic errors.\n"
		<< " Locate the problems and repair them so the program will work as expected.\n";
	cout << '\n';
	{
		cout << "Please give a value in the range 1...5: ";
		int value = -1;
		cin >> value;
		cout << "You entered a ";
		// Translate number into its English word
		if (value == 1)
		{
			cout << "one";
		}
		else if (value == 2)
		{
			cout << "two";
		}
		else if (value == 3)
		{
			cout << "three";
		}
		else if (value == 4)
		{
			cout << "four";
		}
		else if (value == 5)
		{
			cout << "five";
		}
		else // Value out of range
		{
			cout << "value out of range";
		}
		cout << '\n';
	}
	cout << '\n';

	cout << " Exercise 5.10.18\n";
	cout << " Write a C++ program that requests five integer values from the user.\n"
		<< " It then prints the maximum and	minimum values entered.\n"
		<< " If the user enters the values 3, 2, 5, 0, and 1,\n"
		<< " the program would indicate that 5 is the maximum and 0 is the minimum.\n"
		<< " Your program should handle ties properly; for example,\n"
		<< " if the user enters 2, 4, 2, 3, and 3, the program should report 2 as the minimum and 4 as maximum.\n";
	cout << '\n';
	{
		int n1 = -1, n2 = -1, n3 = -1, n4 = -1, n5 = -1;
		cout << " Please give five integer values: ";
		cin >> n1 >> n2 >> n3 >> n4 >> n5;

		int max = n1;
		if (max < n2)
			max = n2;
		if (max < n3)
			max = n3;
		if (max < n4)
			max = n4;
		if (max < n5)
			max = n5;
		cout << "The maximum value is: " << max << "\n";

		int min = n1;
		if (min > n2)
			min = n2;
		if (min > n3)
			min = n3;
		if (min > n4)
			min = n4;
		if (min > n5)
			min = n5;
		cout << "The minimum value is: " << min << "\n";
	}
	cout << '\n';

	cout << " Exercise 5.10.19\n";
	cout << " Write a C++ program that requests five integer values from the user.\n"
		<< " It then prints one of two things: if any of the values entered are duplicates,\n"
		<< " it prints \"DUPLICATES\"; otherwise, it prints \"ALL UNIQUE\".\n";
	cout << '\n';
	{
		int n1 = -1, n2 = -1, n3 = -1, n4 = -1, n5 = -1;
		cout << " Please give five integer values: ";
		cin >> n1 >> n2 >> n3 >> n4 >> n5;

		bool duplicatesExist = false;
		if (n1 == n2 || n1 == n3 || n1 == n4 || n1 == n5 ||
			n2 == n3 || n2 == n4 || n2 == n5 ||
			n3 == n4 || n3 == n5 ||
			n4 == n5)
			duplicatesExist = true;

		if (duplicatesExist)
			cout << "DUPLICATES\n";
		else
			cout << "ALL UNIQUE\n";
	}
	cout << '\n';

	return 0;
}