#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
	Player(const string &name = "") :
		GenericPlayer(name) {}
	virtual ~Player() {}
	virtual bool IsHitting() const override;
	void Win() const { cout << m_sName << " wins." << endl; }
	void Lose() const { cout << m_sName << " loses." << endl; }
	void Push() const { cout << m_sName << " pushes." << endl; }
};

#endif // !PLAYER_H
