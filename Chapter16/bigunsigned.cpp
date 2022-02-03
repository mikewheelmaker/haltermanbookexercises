#include "bigunsigned.h"

using std::string;

BigUnsigned::BigUnsigned()
{
	this->digits.push_back(0);
}

BigUnsigned::BigUnsigned(unsigned int n)
{
	std::string digitsN = std::to_string(n);
	for (auto digit : digitsN)
		this->digits.push_back(digit-'0');
}

BigUnsigned::BigUnsigned(const BigUnsigned& other)
{
	for (auto digit : other.digits)
		this->digits.push_back(digit);
}

BigUnsigned::BigUnsigned(const string& other)
{
	for (auto digit : other)
		this->digits.push_back(digit - '0');
}

BigUnsigned operator+(const BigUnsigned& left, const BigUnsigned& right)
{
	BigUnsigned result;
	vector<int> digitsLeft;
	vector<int> digitsRight;
	int precisionOfLeft = left.digits.size();
	int precisionOfRight = right.digits.size();
	int differenceInPrecision = precisionOfLeft - precisionOfRight;
	if (differenceInPrecision >= 0)
	{
		digitsLeft = left.digits;
		for (int i = 0; i < differenceInPrecision; ++i)
			digitsRight.push_back(0);
		for (auto digit : right.digits)
			digitsRight.push_back(digit);
		for (int i = 0; i < precisionOfLeft; ++i)
			result.digits.push_back(0);

		for (int i = precisionOfLeft - 1; i >= 0; --i)
		{
			int tempSum = digitsLeft.at(i) + digitsRight.at(i);
			if (tempSum > 9)
			{
				result.digits[i + 1] += tempSum % 10;
				result.digits[i] += tempSum / 10;
			}
			else
				result.digits[i + 1] += tempSum;
		}
	}
	else
	{
		result = right + left;
	}

	if (result.digits.front() == 0)
	{
		int resultPrecision = result.digits.size();
		for (int i = 0; i < resultPrecision - 1; ++i)
			result.digits[i] = result.digits[i + 1];
		result.digits.pop_back();
	}

	return result;
}

std::ostream& operator<<(std::ostream& os, const BigUnsigned& bu)
{
	for (auto digit : bu.digits)
		os << digit;
	return os;
}
