// database.h, Simond Lee
// Description: Class for a database of Composer records.
#include <iostream>
#include "Composer.h"

const int kMaxComposers = 3;

class Database {
	public:
		Database() {
			next_slot_ = 0;
		}
		~Database() {
		}

		Composer& AddComposer(string in_first_name, string in_last_name,
				string in_genre, int in_yob, string in_fact);
		Composer& GetComposer(string in_last_name);
		void DisplayAll();
		void DisplayByRank();
		int no_records();

	private:
		Composer composers_[kMaxComposers];
		Composer foo_composers_[1];
		int next_slot_;
};

Composer& Database::AddComposer(string in_first_name, string in_last_name,
				string in_genre, int in_yob, string in_fact) {
	Composer composer;
	composer.set_first_name(in_first_name);
	composer.set_last_name(in_last_name);
	composer.set_composer_genre(in_genre);
	composer.set_composer_yob(in_yob);
	composer.set_fact(in_fact);
	composers_[next_slot_] = composer;
	next_slot_++;
	return composers_[next_slot_ - 1];
}

Composer& Database::GetComposer(string in_last_name) {
	for (int i = 0; i < next_slot_; i++) {
		if (composers_[i].last_name() == in_last_name)
			return composers_[i];
	}
	// If composer is not found, place a dummy composer so we can retrieve
	// "Not found" message.
	// Need to find a better solution
	Composer composer;
	composer.set_first_name("Not found");
	foo_composers_[0] = composer;
	return foo_composers_[0];
}

void Database::DisplayAll() {
	for (int i = 0; i < next_slot_; i++)
		cout << composers_[i].first_name() << " " << composers_[i].last_name() << " "
		   << composers_[i].ranking() << endl;
	return;
}

void Database::DisplayByRank() {
	for (int rank = 1; rank != 11; rank++) {
		for (int i = 0; i < next_slot_; i++) {
			if (composers_[i].ranking() == rank)
				cout << composers_[i].first_name() << " " << composers_[i].last_name()
					<< " " << composers_[i].ranking() << endl;
		}
	}
	return;
}

int Database::no_records() {
	return next_slot_;
}
