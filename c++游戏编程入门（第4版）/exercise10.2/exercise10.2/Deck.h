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
	// 创建一个52张牌的标准牌堆
	void Populate();
	// 洗牌
	void Shuffle() { random_shuffle(m_cards.begin(), m_cards.end()); }
	// 发牌
	void Deal(Hand &aHand);
	// 只要玩家跟牌，就向玩家额外发牌
	void AdditionalCards(GenericPlayer &aGenericPlayer);
};

#endif // !DECK_H
