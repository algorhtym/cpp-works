#include <iostream>
#include "BigInteger.h"

using namespace std;

int main() {
	BigInteger b1(15, 10);
	BigInteger b2(5, 10);
	BigInteger b3(-2345, 10);

	cout << b1 << endl << b2 << endl;
	cout << b1 + b2 << endl;

	cout << b3 << endl;

	BigInteger b4(18, 2);
	cout << b4 << endl;
	cout << b4 + b1 << endl;
	cout << (b4 + b1).get_number() << endl;

	BigInteger b5(135, 2);
	cout << b5 << endl;
	BigInteger b6;
	cin >> b6;
	cout << "addition of b5 and b6: " << b5 + b6 << endl;
	cout << "base 10 form of this addition: " << (b5 + b6).get_number() << endl;

	return 0;
}