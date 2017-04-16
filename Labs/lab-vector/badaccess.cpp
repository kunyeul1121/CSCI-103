#include <iostream>
#include "bigint.h"

using namespace std;

int main()
{
	BigInt ya("1738");
	BigInt bb("1050");
	ya.add(bb);
	cout << ya.number[1] << endl;
	return 0;
}