#include <iostream>
#include "bigint.h"

using namespace std;

BigInt::BigInt(string s)
{
	length = s.length() - 1;

	for (int i = length; i >= 0; i--)
	{
		digit = ((int)s[i]) - 48;

		number.push_back(digit);
	}
}

string BigInt::to_string()
{
	size = number.size() - 1;

	string_number = "";

	for (int i = size; i >= 0; i--)
	{
		string_number += (char)(number[i] + 48);
	}

	return string_number;
}

void BigInt::add(BigInt b)
{
	sum = 0;
	carry_on = 0;

	if(number.size() != b.number.size())
	{
		while(number.size() != b.number.size())
		{
			if(number.size() > b.number.size())
			{
				b.number.push_back(0);
			}
			else
			{
				number.push_back(0);
			}
		}
	}

	for (int i = 0; i < number.size(); i++)
	{
		sum = number[i] + b.number[i] + carry_on;
		carry_on = 0;
		carry_on = sum / 10;
		number[i] = (sum % 10);
	}
	if(carry_on > 0)
	{
		number.push_back(carry_on);
	}
}