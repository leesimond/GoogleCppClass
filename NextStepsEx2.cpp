#include <iostream>
using namespace std;

void user_input(string &bookcode, float &price, int &on_hand, int &enrollment, 
		bool &required, bool &new_book) {
	cout << "Please enter the book code: ";
	cin >> bookcode;
	cout << " single copy price: ";
	cin >> price;
	cout << " number on hand: ";
	cin >> on_hand;
	cout << " prospective enrollment: ";
	cin >> enrollment;
	cout << " 1 for reqd/0 for optional: ";
	cin >> required;
	cout << " 1 for new/0 for used: ";
	cin >> new_book;
}

string mult_str(string letter, int multiple) {
	string result;
	for (int i = 0; i < multiple; i++)
		result += letter;
	return result;
}

void print_input(string bookcode, float price, int on_hand, int enrollment, 
		bool required, bool new_book) {
	cout << mult_str("*", 51) << endl;
	cout << "Book: " << bookcode << endl;
	cout << "Price: $" << price << endl;
	cout << "Inventory: "  << on_hand << endl;
	cout << "Enrollment: " << enrollment << endl << endl;

	if (required)
		cout << "This book is required ";
	else
		cout << "This book is optional ";
	if (new_book)
		cout << "and new.";
	else
		cout << "and used.";
	cout << endl << mult_str("*", 51) << endl;
}

int order_required(int enrollment, int on_hand, bool required, bool new_book) {
	if (required)
		if (new_book)
			return enrollment * 0.9 - on_hand;
		else
			return enrollment * 0.65 - on_hand;
	else
		if (new_book)
			return enrollment * 0.4 - on_hand;
		else
			return enrollment * 0.2 - on_hand;
}

float total_cost(int quantity, float price) {
	return quantity * price;
}

int main() {
	string bookcode;
	float price;
	int on_hand, enrollment;
	bool required, new_book, exit;
	float total_all_orders = 0;
	while (1) {
		user_input(bookcode, price, on_hand, enrollment, required, new_book);
		print_input(bookcode, price, on_hand, enrollment, required, new_book);

		int no_required = order_required(enrollment, on_hand, required, new_book);
		cout << "Need to order: " << no_required << endl;
		float cost = total_cost(no_required, price);
		total_all_orders += cost;
		cout << "Total Cost: " << cost << endl;
		cout << mult_str("*", 51) << endl << endl;
		
		cout << "Enter 1 to do another book, 0 to stop. ";
		cin >> exit;
		if (!exit) {
			cout << mult_str("*", 51) << endl;
			cout << "Total for all orders: $" << total_all_orders << endl;
			cout << "Profit: $" << total_all_orders * 0.2 << endl;
			cout << mult_str("*", 51) << endl;
			return 0;
		}
	}
}
