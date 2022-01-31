#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;

// Exercise 13.6.3
bool palindrome(const string& s)
{
	int sizeOfS = s.length();
	for(size_t i = 0; i < sizeOfS; ++i)
		if(toupper(s[i]) != toupper(s[sizeOfS-i-1]))
			return false;
	return true;
}


int main()
{
	cout << " Exercise 13.6.3\n";
	{
		cout << "See code above main.\n";
		string s1 = "abcBA";
		string s2 = "palindrome";
		cout << "Test result for palindrome on "<< s1 <<" is: " << palindrome(s1) << '\n';
		cout << "Test result for palindrome on "<< s2 <<" is: " << palindrome(s2) << '\n';
	}
	cout << '\n';

	cout << " Exercise 13.6.7.e)\n";
	{
		string w;
		ifstream x("results");
		if (x.good())
			while (x >> w)
				cout << '[' << w << "]\n";
		else
			cout << "Unable to load file!\n";
	}
	cout << '\n';

	return 0;
}