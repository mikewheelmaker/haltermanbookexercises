#include "bigunsigned.h"

using std::cout;

int main()
{
	cout << " Exercise 16.6.1\n";
	{
		cout << "See code in bigunsigned.cpp and bigunsigned.h\n";
		BigUnsigned bu0;				//             0
		BigUnsigned bu1(1234);			//    1, 2, 3, 4
		BigUnsigned bu2(bu1);			//    1, 2, 3, 4
		BigUnsigned bu3("5678");		//    5, 6, 7, 8
		BigUnsigned bu4 = bu1 + bu2;	//    2, 4, 6, 8
		BigUnsigned bu5 = bu1 + bu3;	//    6, 9, 1, 2
		BigUnsigned bu6(99);			//          9, 9
		BigUnsigned bu7(9999);          //    9, 9, 9, 9
		BigUnsigned bu8 = bu1 + bu6;	//    1, 3, 3, 3
		BigUnsigned bu9 = bu1 + bu7;	// 1, 1, 2, 3, 3
		cout << "bu0: " << bu0 << '\n';
		cout << "bu1: " << bu1 << '\n';
		cout << "bu2: " << bu2 << '\n';
		cout << "bu3: " << bu3 << '\n';
		cout << "bu4: " << bu4 << '\n';
		cout << "bu5: " << bu5 << '\n';
		cout << "bu6: " << bu6 << '\n';
		cout << "bu7: " << bu7 << '\n';
		cout << "bu8: " << bu8 << '\n';
		cout << "bu9: " << bu9 << '\n';
	}
	cout << '\n';

	return 0;
}