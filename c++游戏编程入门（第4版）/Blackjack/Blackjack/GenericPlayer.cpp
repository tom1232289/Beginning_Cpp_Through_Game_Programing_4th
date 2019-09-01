#include "GenericPlayer.h"

ostream & operator<<(ostream & os, const GenericPlayer & gp)
{
	os << gp.m_sName << ":\t";
	if (!gp.m_cards.empty()) {
		for (auto p : gp.m_cards) {
			os << *p << "\t";
		}
		if (gp.GetTotal() != 0) {
			cout << "(" << gp.GetTotal() << ")";
		}
	}
	else {
		os << "<empty>";
	}

	return os;
}