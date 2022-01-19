#include <iostream>
#include "counter.h"

using namespace std;

// Exercise 10.11.10
/*
* (Faulty function)
*
* get_range
* Establishes a range of integers. The lower value must
* be greater than or equal to min, and the upper value
* must be less than or equal to max.
* min is the lowest acceptable lower value.
* max is the highest acceptable upper value.
* lower is assigned the lower limit of the range
* upper is assigned the upper limit of the range
*/
// a)
void get_range_references(int min, int max, int& lower, int& upper)
{
	cout << "Please enter a data range within the bounds " << min << "..." << max << ": ";
	do { // Loop until acceptable values are provided
		std::cin >> lower >> upper;
		if (lower < min)
			std::cout << lower << " is too low, please try again.\n";
		if (upper > max)
			std::cout << upper << " is too high, please try again.\n";
	} while (lower < min || upper > max);
}
// b)
void get_range_pointers(int min, int max, int* lower, int* upper)
{
	cout << "Please enter a data range within the bounds " << min << "..." << max << ": ";
	do { // Loop until acceptable values are provided
		std::cin >> *lower >> *upper;
		if (*lower < min)
			std::cout << *lower << " is too low, please try again.\n";
		if (*upper > max)
			std::cout << *upper << " is too high, please try again.\n";
	} while (*lower < min || *upper > max);
}

// Exercise 10.11.12
// Computes the midpoint of the points (x1, y1) and (x2, y2).
// The point (mx, my) represents the midpint.
void midpoint(double x1, double y1, double x2, double y2, double& mx, double& my)
{
	mx = (x1 + x2) / 2;
	my = (y1 + y2) / 2;
}

// Exercise 10.11.13
// Computes the point of intersection of two lines.
// The first line passes through the points (x1, y1) and (x2, y2).
// The second line passes through the points (x3, y3) and (x4, y4).
// The function assigns (ix, iy) as the intersection point.
// If the two lines do not intersect in a single point, the function computes (INFINITY, INFINITY).
void intersection(double x1, double y1, double x2, double y2,
	double x3, double y3, double x4, double y4,
	double& ix, double& iy)
{
	double m1 = 0.0;
	double m2 = 0.0;
	double a = 0.0;
	double b = 0.0;

	m1 = (y2 - y1) / (x2 - x1);
	m2 = (y4 - y3) / (x4 - x3);
	a = y1 - m1 * x1;
	b = y3 - m2 * x3;
	if (m1 == m2)
	{
		ix = INFINITY;
		iy = INFINITY;
	}
	else
	{
		ix = (a - b) / (m2 - m1);
		iy = (m1 * (a - b)) / (m2 - m1) + a;
	}
}

// Exercise 10.11.14
int gcd_iterative_using_Euclid(int m, int n)
{	
	while (n > 0)
	{
		int remainder = m % n;
		m = n;
		n = remainder;
	}
	return m;
}

int main()
{
	cout << " Exercise 10.11.3\n";
	{
		cout << "a)\n";
		increment();
		increment();
		increment();
		cout << read() << '\n';
		decrement();
		cout << read() << '\n';
		increment();
		increment();
		cout << read() << '\n';

		cout << "b)\n";
		cout << "The desired output is impossible due to \n"
			<< "count being limited to a value of maximum 5 in the increment function.\n";
	}
	cout << '\n';

	cout << " Exercise 10.11.10\n";
	{
		cout << "See code above main.\n";
	}
	cout << '\n';

	cout << " Exercise 10.11.12\n";
	{
		cout << "See code above main.\n";
		double midX = 0.0;
		double midY = 0.0;
		midpoint(1, 1, 2, 2, midX, midY);
		cout << "The midpoint between (1,1) and (2,2) is: (" << midX << ',' << midY << ")\n";
	}
	cout << '\n';

	cout << " Exercise 10.11.13\n";
	{
		cout << "See code above main.\n";
		double ix = 0.0;
		double iy = 0.0;
		intersection(-1, -1, 1, 1, -1, 1, 1, -1, ix, iy);
		cout << "Intersection of lines defined by points (-1,-1), (1,1), (-1,1) and (1,-1) is: (" << ix << ',' << iy << ")\n";
	}
	cout << '\n';

	cout << " Exercise 10.11.14\n";
	{
		cout << "See code above main.\n";
		cout << "GCD of 1024 and 144 is: " << gcd_iterative_using_Euclid(1024, 144) << '\n';
	}
	cout << '\n';

	return 0;
}