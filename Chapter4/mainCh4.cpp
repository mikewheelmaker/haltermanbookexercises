#include <iostream>

using std::cout;
using std::cin;

int main()
{
	cout << " Exercise 4.12.6\n";
	cout << " Write a C++ program that receives two integer values from the user.\n"
		<< " The program then should print the sum(addition), difference(subtraction),\n"
		<< " product(multiplication), quotient(division), and remainder after division(modulus).\n"
		<< " Your program must use only integers.\n";
	cout << '\n';
	unsigned int firstUnsignedInteger = 0u;
	unsigned int secondUnsignedInteger = 0u;
	cout << "Please enter the first number: ";
	cin >> firstUnsignedInteger;
	cout << "Please enter the second number: ";
	cin >> secondUnsignedInteger;
	cout << firstUnsignedInteger << " + " << secondUnsignedInteger << " = " << firstUnsignedInteger + secondUnsignedInteger << "\n";
	cout << firstUnsignedInteger << " - " << secondUnsignedInteger << " = " << firstUnsignedInteger - secondUnsignedInteger << "\n";
	cout << firstUnsignedInteger << " * " << secondUnsignedInteger << " = " << firstUnsignedInteger * secondUnsignedInteger << "\n";
	cout << firstUnsignedInteger << " / " << secondUnsignedInteger << " = " << firstUnsignedInteger / secondUnsignedInteger << "\n";
	cout << firstUnsignedInteger << " % " << secondUnsignedInteger << " = " << firstUnsignedInteger % secondUnsignedInteger << "\n";
	cout << '\n';

	cout << " Exercise 4.12.7\n";
	cout << " Write a C++ program that receives two double-precision floating-point values from the user.\n"
		<< " The program then should print the sum(addition), difference(subtraction),\n"
		<< " product(multiplication), and quotient(division).\n"
		<< " Your program must use only double-precision floating-point.\n";
	cout << '\n';
	double firstDouble = 0.0;
	double secondDouble = 0.0;
	cout << "Please enter the first number: ";
	cin >> firstDouble;
	cout << "Please enter the second number: ";
	cin >> secondDouble;
	cout << firstDouble << " + " << secondDouble << " = " << firstDouble + secondDouble << "\n";
	cout << firstDouble << " - " << secondDouble << " = " << firstDouble - secondDouble << "\n";
	cout << firstDouble << " * " << secondDouble << " = " << firstDouble * secondDouble << "\n";
	cout << firstDouble << " / " << secondDouble << " = " << firstDouble / secondDouble << "\n";
	cout << '\n';

	cout << " Exercise 4.12.25\n";
	cout << " Write a C++ program that receives two mathematical points from the user and computes and prints their midpoint.\n";
	cout << '\n';
	double x1 = 0.0;
	double x2 = 0.0;
	double y1 = 0.0;
	double y2 = 0.0;
	char leftParenthesis, comma, rightParenthesis;
	cout << "Please enter the first point (x,y): ";
	cin >> leftParenthesis >> x1 >> comma >> y1 >> rightParenthesis;
	cout << "Please enter the second point (x,y): ";
	cin >> leftParenthesis >> x2 >> comma >> y2 >> rightParenthesis;
	cout << "The midpoint of (" << x1 << ',' << y1 << ") and (" << x2 << ',' << y2 << ')'
		<< " is (" << (x1 + x2) / 2.0 << ',' << (y1 + y2) / 2.0 << ")\n";
	cout << '\n';

	cout << " Exercise 4.12.26\n";
	cout << " Table 4.7 lists the Calorie contents of several foods.\n"
		<< " Running or walking burns off about 100 Calories per mile.\n"
		<< " Write a C++ program that requests three values from the user:\n"
		<< " the number of bean burritos, salads, and shakes consumed(in that order).\n"
		<< " The program should then display the number of miles that must be run or walked\n"
		<< " to burn off the Calories represented in that food.\n";
	cout << '\n';
	const unsigned int BEAN_BURRITO_CALORIES = 357;
	const unsigned int SALAD_CALORIES = 185;
	const unsigned int MILKSHAKE_CALORIES = 388;
	unsigned int numberOfBurritos = 0;
	unsigned int numberOfSalads = 0;
	unsigned int numberOfMilkshakes = 0;
	unsigned int totalCalories = 0;
	double numberMiles = 0.0;
	cout << "Number of bean burritos, bowls of salad, and milkshakes eaten? ";
	cin >> numberOfBurritos >> numberOfSalads >> numberOfMilkshakes;
	cout << '\n';
	totalCalories += numberOfBurritos * BEAN_BURRITO_CALORIES;
	totalCalories += numberOfSalads * SALAD_CALORIES;
	totalCalories += numberOfMilkshakes * MILKSHAKE_CALORIES;
	numberMiles = totalCalories / 100.0;
	cout << "You ingested " << totalCalories << " Calories.\n";
	cout << "You will have to run " << numberMiles << " miles to expend that much energy.\n";
	cout << '\n';
	return 0;
}