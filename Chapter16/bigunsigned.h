#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class BigUnsigned
{
	vector<int> digits;

public:
	BigUnsigned();
	BigUnsigned(unsigned int n);
	BigUnsigned(const BigUnsigned& other);
	BigUnsigned(const string& other);

	friend BigUnsigned operator+(const BigUnsigned& left, const BigUnsigned& right);
	friend std::ostream& operator<<(std::ostream& os, const BigUnsigned& bu);
};