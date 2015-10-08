// composer.h, Simond Lee
// Description: The class for a Composer record.
// The default ranking is 10 which is the lowest possible.
#include <iostream>
using namespace std;

const int kDefaultRanking = 10;

class Composer {
	public:
		Composer() {
			ranking_ = kDefaultRanking;
		}
		~Composer() {
		}
		
		void set_first_name(string in_first_name);
		string first_name();
		void set_last_name(string in_last_name);
		string last_name();
		void set_composer_yob(int in_composer_yob);
		int composer_yob();
		void set_composer_genre(string in_composer_genre);
		string composer_genre();
		void set_ranking(int in_ranking);
		int ranking();
		void set_fact(string in_fact);
		string fact();
		
		void Promote(int increment);
		void Demote(int decrement);
		void Display();

	private:
		string first_name_;
		string last_name_;
		int composer_yob_;
		string composer_genre_;
		string fact_;
		int ranking_;
};

void Composer::set_first_name(string in_first_name) {
	first_name_ = in_first_name;
}

string Composer::first_name() {
	return first_name_;
}

void Composer::set_last_name(string in_last_name) {
	last_name_ = in_last_name;
}

string Composer::last_name() {
	return last_name_;
}

void Composer::set_composer_yob(int in_composer_yob) {
	composer_yob_ = in_composer_yob;
}

int Composer::composer_yob() {
	return composer_yob_;
}

void Composer::set_composer_genre(string in_composer_genre) {
	composer_genre_ = in_composer_genre;
}

string Composer::composer_genre() {
	return composer_genre_;
}

void Composer::set_ranking(int in_ranking) {
	ranking_ = in_ranking;
}

int Composer::ranking() {
	return ranking_;
}

void Composer::set_fact(string in_fact) {
	fact_ = in_fact;
}

string Composer::fact() {
	return fact_;
}

void Composer::Promote(int increment) {
	if (ranking_ > 1) {
		ranking_ -= increment;
		if (ranking_ < 1)
			ranking_ = 1;
	}
	return;
}

void Composer::Demote(int decrement) {
	if (ranking_ < 10) {
		ranking_ += decrement;
		if (ranking_ > 10)
			ranking_ = 10;
	}
	return;
}

void Composer::Display() {
	cout << "First name: " << first_name_ << endl;
	cout << "Last name: " << last_name_ << endl;
	cout << "YOB: " << composer_yob_ << endl;
	cout << "Genre: " << composer_genre_ << endl;
	cout << "Fact: " << fact_ << endl;
	cout << "Rank: " << ranking_ << endl;
	return;
}
