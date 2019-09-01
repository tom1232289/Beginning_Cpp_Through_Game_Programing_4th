#pragma once

#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <ctime>

class Game
{
public:
	Game(const vector<string> &name);
	~Game() {}
public:
	void Play();
private:
	Deck m_deck;
	House m_house;
	vector<Player> m_players;
};

#endif // !GAME_H
