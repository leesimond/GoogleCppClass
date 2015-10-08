#include <iostream>
using namespace std;

int check_odd_and_divide(int a) {
	if (a == 9)
		return a;
	int odd = a % 2;
	if (odd)
		if (a >= 13)
			a -= 11;
		else if (a >= 0)
			a += 11;
	a /= 2;
	return a;
}

int join_digits(int a, int b, int c) {
	int result = a * 100 + b * 10 + c;
	return result;
}

int main() {
	int three_digit;
	cout << "Enter three digit number: ";
	cin >> three_digit;
	int a = three_digit / 100;
	int b = (three_digit - a * 100) / 10;
	int c = three_digit - a * 100 - b * 10;
	int x = three_digit % 11;
	int y = join_digits(b, c, a) % 11;
	int z = join_digits(c, a, b) % 11;

	int xy = x + y, yz = y + z, zx = z + x;

	a = check_odd_and_divide(xy);
	b = check_odd_and_divide(yz);
	c = check_odd_and_divide(zx);
	cout << a << " " << b << " " << c << endl;

	return 0;
}
