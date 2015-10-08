#include <iostream>
#include <string>
using namespace std;

int encode_month(char month) {
	int result = int(month) - 64;
	return result;
}

int encode_digit(char date) {
	int result = int(date) - 81;
	return result;
}

int encode_year(char year) {
	int result = int(year) - 64 + 1995;
	return result;
}

int main() {
	string date;
	cout << "Enter date: ";
	cin >> date;
	char ch = date[0];
	int month = encode_month(ch);
	ch = date[1];
	int date1 = encode_digit(ch);
	ch = date[2];
	int date2 = encode_digit(ch);
	ch = date[3];
	int year = encode_year(ch);
	cout << month << "/" << date1 << date2 << "/" << year << endl;
	return 0;
}
