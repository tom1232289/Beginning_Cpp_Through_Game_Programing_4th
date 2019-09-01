#pragma once

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

using namespace std;

class Hand
{
public:
	Hand() { m_cards.reserve(7); }
	virtual ~Hand() { Clear(); }
public:
	void Add(Card *pCard) { m_cards.push_back(pCard); }
	void Clear();
	int GetTotal() const;
protected:
	vector<Card*> m_cards;
};

#endif // !HAND_H
