#include <iostream>
#include "windows.h"	//needed to identify Sleep()

using std::cout;

int main()
{
	cout << " Exercise 3.11.23\n";
	cout << " Write a program that prints the ASCII chart for all the values from 0 to 127.\n";
	cout << '\n';
	cout << "ASCII Table\n";
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << static_cast<char>(16 * j + i) << '\t';
		}
		cout << '\n';
	}
	cout << '\n';

	Sleep(1000);	// just so we can hear the alert sound from the ASCII table and from the next exercise

	cout << " Exercise 3.11.30\n";
	cout << " Write a C++ program that simply emits a beep sound when run.\n";
	cout << "\a\n";

	cout << " Exercise 3.11.31\n";
	cout << " Create an unscoped enumeration type that represents the days of the week.\n";
	enum DaysOfTheWeekUnscoped {
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday
	};
	cout << '\n';

	cout << " Exercise 3.11.32\n";
	cout << " Create a scoped enumeration type that represents the days of the week.\n";
	enum class DaysOfTheWeekScoped {
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday
	};
	cout << '\n';

	cout << " Exercise 3.11.33\n";
	cout << " Create an unscoped enumeration type that represents the months of the year.\n";
	enum MonthsOfTheYearUnscoped {
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};
	cout << '\n';

	cout << " Exercise 3.11.34\n";
	cout << " Create a scoped enumeration type that represents the months of the year.\n";
	enum class MonthsOfTheYearScoped {
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};
	cout << '\n';

	return 0;
}