#include <iostream>
#include <iomanip>
using namespace std;

int GetInput() {
	int score;
	while (1) {
		if (!(cin >> score)) {
			cout << "Numbers only" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
			return score;
	}
}

int main() {
	cout << "Enter the score for the first assignment. ";
	float ass1 = GetInput();
	cout << "Enter the score for the second assignment. ";
	float ass2 = GetInput();
	cout << "Enter the score for the third assignment. ";
	float ass3 = GetInput();
	cout << "Enter the score for the fourth assignment. ";
	float ass4 = GetInput();
	cout << "Enter the score for the midterm. ";
	float mid_term = GetInput();
	cout << "Enter the score for the final. ";
	float final_exam = GetInput();
	cout << "Enter the score for the section grade. ";
	float section_grade = GetInput();

	float ass_total = ass1 / 10 + ass2 / 10 + ass3 / 10 + ass4 / 10;
	mid_term *= 0.15;
	final_exam *= 0.35;
	section_grade *= 0.1;
	float final_grade = ass_total + mid_term + final_exam + section_grade;
	cout << "The final grade is: " << final_grade << endl;
	return 0;
}
