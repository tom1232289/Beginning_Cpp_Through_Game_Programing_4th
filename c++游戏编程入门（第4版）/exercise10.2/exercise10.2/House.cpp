#include "House.h"

void House::FlipFirstCard()
{
	if (!(m_cards.empty()))
		m_cards.at(0)->Flip();
	else
		cout << "No card to flip" << endl;
}