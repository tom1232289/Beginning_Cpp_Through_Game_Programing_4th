#pragma once

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card
{
	friend ostream & operator<<(ostream &os, const Card &card);
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };	// （梅花，方块，红桃，黑桃）
public:
	Card(rank r = ACE, suit s = SPADES, bool ifu = true) :
		m_rank(r),
		m_suit(s),
		m_bIsFaceup(ifu) {}
public:
	// 返回一个1~11的牌的点数
	int GetValue() const;
	// 翻牌，如果牌朝上，则将牌朝下，反之亦然
	void Flip() { m_bIsFaceup = !(m_bIsFaceup); }
private:
	rank m_rank;
	suit m_suit;
	bool m_bIsFaceup;
};

#endif // !CARD_H
