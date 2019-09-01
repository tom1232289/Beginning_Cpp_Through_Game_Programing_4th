#include "Player.h"

bool Player::IsHitting() const
{
	cout << m_sName << ", do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	if (cin.fail()) {
		cin.clear();
		cin.get();
	}
	return (response == 'y' || response == 'Y');
}