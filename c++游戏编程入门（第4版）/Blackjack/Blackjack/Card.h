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
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };	// ��÷�������飬���ң����ң�
public:
	Card(rank r = ACE, suit s = SPADES, bool ifu = true) :
		m_rank(r),
		m_suit(s),
		m_bIsFaceup(ifu) {}
public:
	// ����һ��1~11���Ƶĵ���
	int GetValue() const;
	// ���ƣ�����Ƴ��ϣ����Ƴ��£���֮��Ȼ
	void Flip() { m_bIsFaceup = !(m_bIsFaceup); }
private:
	rank m_rank;
	suit m_suit;
	bool m_bIsFaceup;
};

#endif // !CARD_H
