#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float chirps;
	cout << "Number of chirps: ";
	if (!(cin >> chirps)) {
		cout << "Not a number." << endl;
		return 0;
	} else {
		float temp = (chirps + 40) / 4 ;
		cout << "The temperature is: " << fixed << setprecision(1) << temp << " degrees." << endl;
		return 0;
	}
}
