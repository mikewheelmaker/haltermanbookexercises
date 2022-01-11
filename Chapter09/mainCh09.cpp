#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
	cout << " Exercise 9.7.12\n";
	cout << " Complete the distance function started in Section 9.5.\n"
		<< " Test it with several point coordinates to convince yourself\n"
		<< " that your implementation is correct.\n";
	cout << '\n';
	{
		cout << "Distance between (1,1) and (2,2) is: " << distance(1, 1, 2, 2) << '\n';
		cout << "Distance between (3,3) and (2,2) is: " << distance(3, 3, 2, 2) << '\n';
		cout << "Distance between (0.5, 0.5) and (1.5, 1.5) is: " << distance(0.5, 0.5, 1.5, 1.5) << '\n';
		cout << "Distance between (-1,-1) and (-2,-2) is: " << distance(-1, -1, -2, -2) << '\n';
		cout << "Distance between (-1,-1) and (1,1) is: " << distance(-1, -1, 1, 1) << '\n';
	}
	cout << '\n';

	return 0;
}