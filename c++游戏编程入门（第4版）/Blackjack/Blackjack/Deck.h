#pragma once

#ifndef DECK_H
#define DECK_H

#include "Hand.h"
#include "GenericPlayer.h"
#include <algorithm>

class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck() {}
public:
	// ����һ��52���Ƶı�׼�ƶ�
	void Populate();
	// ϴ��
	void Shuffle() { random_shuffle(m_cards.begin(), m_cards.end()); }
	// ����
	void Deal(Hand &aHand);
	// ֻҪ��Ҹ��ƣ�������Ҷ��ⷢ��
	void AdditionalCards(GenericPlayer &aGenericPlayer);
};

#endif // !DECK_H
