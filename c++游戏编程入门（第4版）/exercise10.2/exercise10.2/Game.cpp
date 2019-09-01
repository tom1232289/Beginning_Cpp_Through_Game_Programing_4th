#include "Game.h"

Game::Game(const vector<string>& name)
{
	// 从name的vector中创建玩家的vector
	for (auto iter = name.begin(); iter != name.end(); ++iter) {
		m_players.push_back(Player(*iter));
	}
	// 种子随机数生成器
	srand((unsigned)time(NULL));
	m_deck.Populate();
	m_deck.Shuffle();
}

void Game::Play()
{
	// 发两张牌给所有人
	for (int i = 0; i < 2; ++i) {
		for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
			m_deck.Deal(*iter);
		}
		m_deck.Deal(m_house);
	}
	// 隐藏庄家的第一张牌
	m_house.FlipFirstCard();
	// 显示所有人的牌
	for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
		cout << *iter << endl;
	}
	cout << m_house << endl;
	// 给玩家发额外的牌
	for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
		m_deck.AdditionalCards(*iter);
	}
	// 揭示庄家的第一张牌
	m_house.FlipFirstCard();
	cout << endl << m_house;
	// 给庄家发额外的牌
	m_deck.AdditionalCards(m_house);

	if (m_house.IsBusted()) {
		for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
			if (!(iter->IsBusted())) {
				iter->Win();
			}
		}
	}
	else {
		for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
			if (!(iter->IsBusted())) {
				if (iter->GetTotal() > m_house.GetTotal()) {
					iter->Win();
				}
				else if (iter->GetTotal() < m_house.GetTotal()) {
					iter->Lose();
				}
				else {
					iter->Push();
				}
			}
		}
	}
	// 移除所有人的牌
	for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
		iter->Clear();
	}
	m_house.Clear();
}