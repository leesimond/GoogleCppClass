#include <iostream>
using namespace std;

int reverse(int number) {
	int reverse_num, temp_num, result = 0, count = 1;
	// get number of digits n in the form 10^(n-1)
	temp_num = number;
	while (number > 10) {
		number /= 10;
		count *= 10;
	}
	number = temp_num;
	while (number > 0) {
		temp_num = number % 10;
		number /= 10;
		result += temp_num * count;
		count /= 10;
	}
	return result;
}

int main() {
	cout << "input number: ";
	int number;
	cin >> number;
	int reverse_number = reverse(number);
	cout << "reverse it: " << reverse_number << endl;
	int subtract_reverse = number - reverse_number;
	cout << "subtract it: " << number << " - " << reverse_number << " = " << subtract_reverse << endl;
	int reverse_subtract_reverse = reverse(subtract_reverse);
	cout << "reverse it: " << reverse_subtract_reverse << endl;
	int addition_numbers = reverse_subtract_reverse + subtract_reverse;
	cout << "add: " << reverse_subtract_reverse << " + " << subtract_reverse << " = " << addition_numbers
		<< endl;
	return 0;
}
