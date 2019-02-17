// Menu Chooser

#include<iostream>

using namespace std;

int main()
{
	cout << "Difficulty levels" << endl << endl;
	enum difficulty {
		EASY = 1,
		NORMAL= 2,
		HARD = 3
	};
	cout << "1 - Easy" << endl;
	cout << "2 - Normal" << endl;
	cout << "3-Hard" << endl << endl;
	int choice;
	cout << "Choies: ";
	cin >> choice;
	cout << endl;
	switch (choice) {
	case EASY:
		cout << "You picked Easy." << endl;
		break;
	case NORMAL:
		cout << "You picked Normal." << endl;
		break;
	case HARD:
		cout << "You picked Hard" << endl;
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}