#include <iostream>
#include "Database.h"
using namespace std;

string mult_str(string letter, int multiple) {
	string result;
	for (int i = 0; i < multiple; i++)
		result += letter;
	return result;
}

void print_menu() {
	cout << "Composer Database" << endl;
	cout << mult_str("-", 45) << endl;
	cout << "1) Add a new composer" << endl;
	cout << "2) Retrieve a composer's data" << endl;
	cout << "3) Promote/demote a composer's rank" << endl;
	cout << "4) List all composers" << endl;
	cout << "5) List all composers by rank" << endl;
	cout << "0) Quit" << endl;
	return;
}

void add_composer(Database &database) {
	string first_name, last_name, composer_genre, fact;
	int composer_yob;
	if (database.no_records() == kMaxComposers) {
		cout << "Database is full." << endl;
		return;
	}
	cout << "First name: ";
	cin >> first_name;
	cout << "Last name: ";
	cin >> last_name;
	cout << "Genre: ";
	cin >> composer_genre;
	cout << "YOB: ";
	cin >> composer_yob;
	cout << "Fact: ";
	cin >> fact;
	database.AddComposer(first_name, last_name, composer_genre, composer_yob, fact);
	return;
}

void retrieve_composer(Database &database) {
	string last_name;
	cout << "Composer's last name: ";
	cin >> last_name;
	Composer& comp = database.GetComposer(last_name);
	if (comp.first_name() == "Not found") {
		cout << "Composer not found." << endl;
		return;
	}
	cout << "First name: " << comp.first_name() << endl;
	cout << "Last name: " << comp.last_name() << endl;
	cout << "YOB: " << comp.composer_yob() << endl;
	cout << "Genre: " << comp.composer_genre() << endl;
	cout << "Fact: " << comp.fact() << endl;
	cout << "Rank: " << comp.ranking() << endl;
	return;
}

void change_rank(Database &database) {
	int option, value;
	string last_name;
	cout << "Promote(1) or demote(2)? ";
	cin >> option;
	if (!(option == 1 || option == 2))
		return;
	cout << "Composer's last name: ";
	cin >> last_name;
	Composer& comp = database.GetComposer(last_name);
	if (comp.first_name() == "Not found")
		return;
	if (option == 1) {
		cout << "Promote by: ";
		cin >> value;
		comp.Promote(value);
	}
	else if (option == 2) {
		cout << "Demote by: ";
		cin >> value;
		comp.Demote(value);
	}
	return;
}

int main() {
	Database my_db;
	while (1) {
		int option;
		print_menu();
		if (!(cin >> option)) {
			cout << "Numbers only" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			if (option == 1)
				add_composer(my_db);
			else if (option == 2)
				retrieve_composer(my_db);
			else if (option == 3)
				change_rank(my_db);
			else if (option == 4)
				my_db.DisplayAll();
			else if (option == 5)
				my_db.DisplayByRank();
			else if (option == 0)
				return 0;
			else
				cout << "Invalid option.";
		}
		cout << endl;
	}
	return 0;
}
