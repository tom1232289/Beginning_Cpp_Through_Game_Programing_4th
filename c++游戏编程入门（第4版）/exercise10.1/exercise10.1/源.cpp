#include "Enemy.h"

int main()
{
	cout << "Creatint an enemy" << endl;
	Enemy enemy1;
	enemy1.Attack();
	cout << endl;

	cout << "Creating a boss." << endl;
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();
	cout << endl;

	cout << "Creating a final boss." << endl;
	FinalBoss finalBoss1;
	finalBoss1.Attack();
	finalBoss1.SpecialAttack();
	finalBoss1.MegaAttack();

	return 0;
}