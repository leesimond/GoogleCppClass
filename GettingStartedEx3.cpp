#include <iostream>
using namespace std;

int main() {
	int seconds;
	cout << "Number of seconds: ";
	cin >> seconds;
	int hours = seconds / 3600, minutes = (seconds - hours * 3600) / 60;
	seconds -= hours * 3600 + minutes * 60;
	cout << "Hours: " << hours << endl;
	cout << "Minutes: " << minutes << endl;
	cout << "Seconds: " << seconds << endl;
	return 0;
}
