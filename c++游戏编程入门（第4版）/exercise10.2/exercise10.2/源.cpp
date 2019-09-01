#include "Game.h"

ostream & operator<<(ostream &os, const Card &aCard);
ostream & operator<<(ostream &os, const GenericPlayer &aGenericPlayer);

int main()
{
	cout << "\t\tWelcome to Blackjack!" << endl << endl;
	int iNumPlayers = 0;
	while (iNumPlayers < 1 || iNumPlayers > 7) {
		cout << "How many players? (1~7): ";
		cin >> iNumPlayers;
		if (cin.fail()) {
			cin.clear();
			cin.get();
		}
	}
	vector<string> names;
	string name;
	for (int i = 0; i < iNumPlayers; ++i) {
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;
	// 游戏循环
	char again = 'y';
	while (again != 'n' && again != 'N') {
		// 每一轮开始都重置牌堆
		Game game(names);
		game.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
		if (cin.fail()) {
			cin.clear();
			cin.get();
		}
	}

	return 0;
}