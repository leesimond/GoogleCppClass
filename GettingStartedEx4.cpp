#include <iostream>
#include <algorithm>
using namespace std;

string mult_str(string letter, int multiple) {
	string result;
	for (int i = 0; i < multiple; i++)
		result += letter;
	return result;
}

void print_e() {
	cout << mult_str("E", 5) << endl << "E" << endl << mult_str("E", 3) << endl << "E" << endl
		<< mult_str("E", 5) << endl;
}	

void print_f() {
	cout << mult_str("F", 5) << endl << "F" << endl << mult_str("F", 3) << endl << "F" << endl
		<< "F" << endl;
}	

int main() {
	cout << "Enter banner: ";
	string banner;
	cin >> banner;
	transform(banner.begin(), banner.end(), banner.begin(), ::tolower);
	for (int i = 0; i < banner.length(); i++) {
		if (banner[i] == 'e') {
			print_f();
			cout << endl;
		} else if (banner[i] == 'f') {
			print_e();
			cout << endl;
		}
	}
	return 0;
}

