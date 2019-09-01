#include "Card.h"

int Card::GetValue() const
{
	// 如果牌朝下，则值为0
	int value = 0;
	if (m_bIsFaceup) {
		value = m_rank;
		// J,Q,K按照10计算
		if (value > 10) {
			value = 10;
		}
	}

	return value;
}

ostream & operator<<(ostream & os, const Card & card)
{
	const string RANKS[] = { "0","A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	const string SUITS[] = { "梅花","方块","红桃","黑桃" };
	if (card.m_bIsFaceup) {
		os << SUITS[card.m_suit] << RANKS[card.m_rank];
	}
	else {
		os << "XX";
	}
	return os;
}