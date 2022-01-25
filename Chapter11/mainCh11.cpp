#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// Exercise 11.5.10
int sum_positive(const vector<int>& v)
{
	int sum = 0;
	if(v.size() != 0)
		for (auto number : v)
			if (number >= 0)
				sum += number;
	return sum;
}

// Exercise 11.5.11
int count_evens(const vector<int>& v)
{
	int evenNumbers = 0;
	if (v.size() != 0)
		for (auto number : v)
			if (number % 2 == 0)
				++evenNumbers;
	return evenNumbers;
}

// Exercise 11.5.12
int count_evens(const vector<vector<int>>& v)
{
	int evenNumbers = 0;
	if (v.size() != 0)
		for (auto row : v)
			if (row.size() != 0)
				for (auto number : row)
					if (number % 2 == 0)
						++evenNumbers;
	return evenNumbers;
}

// Exercise 11.5.13
bool equals(const vector<int>& v1, const vector<int>& v2)
{
	bool result = false;
	int numberOfEqualElements = 0;
	if (v1.size() == v2.size())
	{
		for (int i = 0; i < static_cast<int>(v1.size()); ++i)
			if (v1.at(i) == v2.at(i))
				++numberOfEqualElements;
		if (numberOfEqualElements == v1.size())
			result = true;
	}
	return result;
}

// Exercise 11.5.14
bool contains(const vector<int>& v1, const vector<int>& v2)
{
	if (v2.empty() || v1.empty() || v2.size() > v1.size())
		return false;
	else
	{
		vector<bool> usedVector(v1.size(), false);
		vector<bool> foundVector(v2.size(), false);
		for (size_t i = 0; i < v2.size(); ++i)
		{
			for (size_t j = 0; j < v1.size(); ++j)
			{
				if (v2.at(i) == v1.at(j))
				{
					if (usedVector.at(j) == false)
					{
						foundVector[i] = true;
						usedVector[j] = true;
						break;
					}
				}
			}
		}
		for (auto item : foundVector)
			if (item == false)
				return false;
	}

	return true;
}

// Exercise 11.5.32
int sum_positive(const int* a, int n)
{
	if (n < 1)
		return 0;

	int result = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] >= 0)
			result += a[i];
	return result;
}

// Exercise 11.5.33
int sum_evens(const int* a, int n)
{
	if (n < 1)
		return 0;
	
	int result = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] % 2 == 0)
			result += a[i];
	return result;
}

// Exercise 11.5.49
int count_negatives(int a[10][10])
{
	int result = 0;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			if (a[i][j] < 0)
				++result;
	return result;
}

int main()
{
	cout << " Exercise 11.5.10\n";
	{
		cout << "See code above main.\n";
		vector<int> v{ 2, -3, 4, -5, 6, -7 };
		cout << "Test result for sum_positive on {2, -3, 4, -5, 6, -7} is: " << sum_positive(v) << '\n';
	}
	cout << '\n';

	cout << " Exercise 11.5.11\n";
	{
		cout << "See code above main.\n";
		vector<int> v{ 2, -3, 4, -5, 6, -7 };
		cout << "Test result for count_evens on {2, -3, 4, -5, 6, -7} is: " << count_evens(v) << '\n';
	}
	cout << '\n';

	cout << " Exercise 11.5.12\n";
	{
		cout << "See code above main.\n";
		vector<vector<int>> v{ {2, -3, 4}, {-5, 6, -7} };
		cout << "Test result for count_evens on { {2, -3, 4}, {-5, 6, -7} } is: " << count_evens(v) << '\n';
	}
	cout << '\n';

	cout << " Exercise 11.5.13\n";
	{
		cout << "See code above main.\n";
		vector<int> v1{ 2, -3, 4 };
		vector<int> v2{ -5, 6, -7 };
		vector<int> v3{ 2, -3 };
		vector<int> v4, v5;
		cout << "Test result for equals on {2, -3, 4} and {-5, 6, -7} is: " << equals(v1, v2) << '\n';
		cout << "Test result for equals on {2, -3, 4} and {2, -3, 4} is: " << equals(v1, v1) << '\n';
		cout << "Test result for equals on {2, -3, 4} and {2, -3} is: " << equals(v1, v3) << '\n';
		cout << "Test result for equals on {2, -3} and {} is: " << equals(v3, v4) << '\n';
		cout << "Test result for equals on {} and {} is: " << equals(v4, v5) << '\n';
	}
	cout << '\n';

	cout << " Exercise 11.5.14\n";
	{
		cout << "See code above main.\n";
		vector<int> v1{ 2, -3, 4 };
		vector<int> v2{ -5, 6, -7 };
		vector<int> v3{ 2, -3 };
		vector<int> v4{ 4, -3, 4 };
		vector<int> v5{ 4, 4 };
		cout << "Test result for contains on {2, -3, 4} and {-5, 6, -7} is: " << contains(v1, v2) << '\n';
		cout << "Test result for contains on {2, -3, 4} and {2, -3, 4} is: " << contains(v1, v1) << '\n';
		cout << "Test result for contains on {2, -3, 4} and {2, -3} is: " << contains(v1, v3) << '\n';
		cout << "Test result for contains on {4, -3, 4} and {4, 4} is: " << contains(v4, v5) << '\n';
		cout << "Test result for contains on {2, -3, 4} and {4, 4} is: " << contains(v1, v5) << '\n';
	}
	cout << '\n';

	cout << " Exercise 11.5.32\n";
	{
		cout << "See code above main.\n";
		int* a = new int[10];
		srand(0);
		for (int i = 0; i < 10; ++i)
		{
			a[i] = rand() % 10 - 5;
			cout << "a[" << i << "]=" << a[i] << '\n';
		}
		cout << "Test result for sum_positive a with 10 random elements is: " << sum_positive(a, 10) << '\n';
	}
	cout << '\n';
	
	cout << " Exercise 11.5.33\n";
	{
		cout << "See code above main.\n";
		int* a = new int[10];
		srand(0);
		for (int i = 0; i < 10; ++i)
		{
			a[i] = rand()%10;
			cout << "a[" << i << "]=" << a[i] << '\n';
		}
		cout << "Test result for sum_evens a with 10 random elements is: " << sum_evens(a, 10) << '\n';
		delete[] a;
	}
	cout << '\n';

	cout << " Exercise 11.5.37\n";
	{
		cout << " Write the C++ code that prints all the elements in collection.\n"
			<< " All the elements in the same row should appear on the same line,\n"
			<< " but each successive row should appear on its own line.\n";
		int** collection = new int* [100];
		srand(0);
		for (int i = 0; i < 100; ++i)
		{
			collection[i] = new int[200];
			for (int j = 0; j < 200; ++j)
			{
				collection[i][j] = rand() % 10;
				cout << collection[i][j] << ' ';
			}
			cout << '\n';
		}
		delete[] collection;
	}
	cout << '\n';

	cout << " Exercise 11.5.49\n";
	{
		cout << "See code above main.\n";
		int a[10][10];
		srand(0);
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				a[i][j] = rand() % 10 - 1;
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "Test result for count_negatives with 10x10 random elements is: " << count_negatives(a) << '\n';
	}
	cout << '\n';

	return 0;
}