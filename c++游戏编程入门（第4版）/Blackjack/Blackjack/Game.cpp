#include "Game.h"

Game::Game(const vector<string>& name)
{
	// ��name��vector�д�����ҵ�vector
	for (auto iter = name.begin(); iter != name.end(); ++iter) {
		m_players.push_back(Player(*iter));
	}
	// ���������������
	srand((unsigned)time(NULL));
	m_deck.Populate();
	m_deck.Shuffle();
}

void Game::Play()
{
	// �������Ƹ�������
	for (int i = 0; i < 2; ++i) {
		for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
			m_deck.Deal(*iter);
		}
		m_deck.Deal(m_house);
	}
	// ����ׯ�ҵĵ�һ����
	m_house.FlipFirstCard();
	// ��ʾ�����˵���
	for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
		cout << *iter << endl;
	}
	cout << m_house << endl;
	// ����ҷ��������
	for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
		m_deck.AdditionalCards(*iter);
	}
	// ��ʾׯ�ҵĵ�һ����
	m_house.FlipFirstCard();
	cout << endl << m_house;
	// ��ׯ�ҷ��������
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
	// �Ƴ������˵���
	for (auto iter = m_players.begin(); iter != m_players.end(); ++iter) {
		iter->Clear();
	}
	m_house.Clear();
}