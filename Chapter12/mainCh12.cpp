#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;

// Helper function(s)
void print(const vector<int> v)
{
	for (auto element : v)
		cout << element << ' ';
	cout << '\n';
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void orderAscending(vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
		for (size_t j = 0; j < v.size() - i - 1; ++j)
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
}

// Exercise 12.6.1
void reverse(vector<int>& v)
{
	vector<int> temp;
	while (!v.empty())
	{
		temp.push_back(v.back());
		v.pop_back();
	}
	v = temp;
}

// Exercise 12.6.2
void special_sort(vector<int>& v)
{
	vector<int> tempEvens;
	vector<int> tempOdds;
	while (!v.empty())
	{
		int x = v.back();
		if (x % 2 == 0)
			tempEvens.push_back(x);
		else
			tempOdds.push_back(x);
		v.pop_back();
	}
	orderAscending(tempEvens);
	for (auto element : tempEvens)
		v.push_back(element);
	orderAscending(tempOdds);
	for (auto element : tempOdds)
		v.push_back(element);
}

// Exercise 12.6.3
void rotate(vector<int>& v)
{
	if (!v.empty())
	{
		vector<int> temp;
		temp.push_back(v.back());
		v.pop_back();
		for (size_t i = 0; i < v.size(); ++i)
			temp.push_back(v[i]);
		v = temp;
	}
}


// Exercise 12.6.4
bool balanced(const vector<int>& v)
{
	if (v.empty())
		return true;

	int numberOfEvens = 0;
	for (auto element : v)
		if (element % 2 == 0)
			++numberOfEvens;
	if (numberOfEvens != v.size() - numberOfEvens)
		return false;

	return true;
}

// Exercise 12.6.5
bool has_duplicates(const vector<int>& v)
{
	if (v.empty())
		return false;

	for (size_t i = 0; i < v.size(); ++i)
		for (size_t j = 0; j < v.size(); ++j)
			if (v.at(i) == v.at(j) && i != j)
				return true;

	return false;
}

// Exercise 12.6.8
bool is_ascending(vector<int>& v)
{
	if (v.empty())
		return true;

	for (size_t i = 0; i < v.size() - 1; ++i)
		if (v.at(i) > v.at(i + 1))
			return false;

	return true;
}


int main()
{
	cout << " Exercise 12.6.1\n";
	{
		cout << "See code above main.\n";
		vector<int> v{ 2, 6, 2, 5, 0, 1, 2, 3 };
		reverse(v);
		cout << "Test result for reverse on { 2, 6, 2, 5, 0, 1, 2, 3 } is: ";
		print(v);
	}
	cout << '\n';

	cout << " Exercise 12.6.2\n";
	{
		cout << "See code above main.\n";
		vector<int> v{ 2, 6, 2, 5, 0, 1, 2, 3 };
		special_sort(v);
		cout << "Test result for special_sort on { 2, 6, 2, 5, 0, 1, 2, 3 } is: ";
		print(v);
	}
	cout << '\n';

	cout << " Exercise 12.6.3\n";
	{
		cout << "See code above main.\n";
		vector<int> v{ 2, 6, 2, 5, 0, 1, 2, 3 };
		rotate(v);
		cout << "Test result for rotate on { 2, 6, 2, 5, 0, 1, 2, 3 } is: ";
		print(v);
	}
	cout << '\n';

	cout << " Exercise 12.6.4\n";
	{
		cout << "See code above main.\n";
		vector<int> v1{ 2, 6, 2, 5, 0, 1, 2, 3 };
		vector<int> v2{ 2, 1, 2, 1 };
		vector<int> v3;
		cout << "Test result for balanced on { 2, 6, 2, 5, 0, 1, 2, 3 } is: " << balanced(v1) << '\n';
		cout << "Test result for balanced on { 2, 1, 2, 1 } is: " << balanced(v2) << '\n';
		cout << "Test result for balanced on { } is: " << balanced(v3) << '\n';
	}
	cout << '\n';

	cout << " Exercise 12.6.5\n";
	{
		cout << "See code above main.\n";
		vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8 };
		vector<int> v2{ 1, 2, 3, 1 };
		vector<int> v3;
		cout << "Test result for has_duplicates on { 1, 2, 3, 4, 5, 6, 7, 8 } is: " << has_duplicates(v1) << '\n';
		cout << "Test result for has_duplicates on { 1, 2, 3, 1 } is: " << has_duplicates(v2) << '\n';
		cout << "Test result for has_duplicates on { } is: " << has_duplicates(v3) << '\n';
	}
	cout << '\n';

	cout << " Exercise 12.6.8\n";
	{
		cout << "See code above main.\n";
		vector<int> v1{ 1, 4, 5, 16, 47, 81 };
		vector<int> v2{ 1, 2, 3, 1 };
		vector<int> v3;
		cout << "Test result for is_ascending on { 1, 4, 5, 16, 47, 81 } is: " << is_ascending(v1) << '\n';
		cout << "Test result for is_ascending on { 1, 2, 3, 1 } is: " << is_ascending(v2) << '\n';
		cout << "Test result for is_ascending on { } is: " << is_ascending(v3) << '\n';
	}
	cout << '\n';

	return 0;
}