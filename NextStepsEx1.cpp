#include <iostream>
using namespace std;

int perfect_square (int number) {
	int result = 0;
	for (int i = 1; i * i <= number; i++){
		if (i * i == number) {
			result = 1;
			return result;
		}
	}
	return result;
}

int sum_of_integers (int number) {
	int result = 0, sum = 0, count = 1;
	while (sum < number) {
		sum += count;
		if (sum == number) {
			result = 1;
			return result;
		}
		count++;
	}
	return result;
}

int main() {
	int number = 1226;
	while (1) {
		int perfect_s = perfect_square(number);
		int sum_i = sum_of_integers(number);

		if ((perfect_s == 1) && (sum_i)) {
			cout << number << " is perfect square and sum of a series." << endl;
			return 0;
		} 
		number++;
	}
}
