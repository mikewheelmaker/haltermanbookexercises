#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << " Exercise 8.7.9\n";
	cout << " From geometry: Write a computer program that given the lengths \n"
		<< " of the two sides of a right triangle adjacent to the right angle \n"
		<< " computes the length of the hypotenuse of the triangle.\n";
	cout << '\n';
	{
		double side1 = 0.0;
		double side2 = 0.0;
		double hypotenuse = 0.0;
		cout << "Please give the lengths of the two sides of the triangle: ";
		cin >> side1 >> side2;
		hypotenuse = sqrt(pow(side1, 2.0) + pow(side2, 2.0));
		cout << "The hypotenuse is of length: " << hypotenuse << '\n';
	}
	cout << '\n';

	return 0;
}