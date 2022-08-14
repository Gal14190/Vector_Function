#include "Vector.h"

int main()
{
	double arr_a[] = { 2.1, 3.5, 6.2, 4.8 };
	double arr_b[] = { 4.2, 3.1, 5.2, 9.4 };

	Vector a(arr_a, 4);
	Vector b(arr_b, 4);
	Vector c1, c2;

	cout << "VECTOR FUNCTIONS CHECK:" << endl;

	cout << "a = " << a << endl 
		<< "b = " << b << endl;

	c1 = a + 2;
	c2 = 2 + a;

	cout << "a + 2 = " << c1
		<< ",\t  2 + a = " << c2
		<< endl;

	c1 = a * 3;
	c2 = 3 * a;

	cout << "a * 3 = " << c1
		<< ",\t  3 * a = " << c2
		<< endl;
	
	c1 = a * b;
	c2 = b * a;

	cout << "a * b = " << c1
		<< ", b * a = " << c2
		<< endl;

	cout << "dot product:"
		<< " ab = " << a.dot(b)
		<< ", ba = " << b.dot(a)
		<< endl;

	cout << endl << "CLOUMN CHECK:" << endl;
	for (int i = a.getSize(); i >= 0; i--)
	{
		if (a[i] == ERROR)
			cout << i << ": ERROR CHECK";
		else
			cout << " ," << i << ": " << a[i];
	}
	cout << endl << "a = b? " << ((a == b) ? " True" : " False") << endl;
	cout <<			"a = a? " << ((a == a) ? " True" : " False") << endl;

	return 0;
}