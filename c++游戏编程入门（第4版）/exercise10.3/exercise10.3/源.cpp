#include "AbstractCreature.h"

int main()
{
	Creature *pCreature = new OrcBoss();
	pCreature->Greet();
	pCreature->DisplayHealth();

	return 0;
}