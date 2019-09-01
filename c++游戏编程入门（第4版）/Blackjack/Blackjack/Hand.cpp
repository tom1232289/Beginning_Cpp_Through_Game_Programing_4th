#include "Hand.h"

void Hand::Clear()
{
	for (auto iter = m_cards.begin(); iter != m_cards.end(); ++iter) {
		delete *iter;
		*iter = nullptr;
	}
	m_cards.clear();
}

int Hand::GetTotal() const
{
	if (m_cards.empty())
		return 0;
	//  如果第一张牌为点数为0，则牌是朝下的，直接返回0
	if (m_cards.at(0)->GetValue() == 0)
		return 0;
	// 加上牌的点数，将ACE的点数视为1
	int iTotal = 0;
	for (auto iter = m_cards.begin(); iter != m_cards.end(); ++iter) {
		iTotal += (*iter)->GetValue();
	}
	// 确定牌中是否包含ACE
	bool bIsContainAce = false;
	for (auto iter = m_cards.begin(); iter != m_cards.end(); ++iter) {
		if ((*iter)->GetValue() == Card::ACE) {
			bIsContainAce = true;
		}
	}
	// 如果牌中有ACE并且点数足够小，则将ACE的点数视为11
	if (bIsContainAce && iTotal <= 11) {
		// 这里只需要再加上10就好了，因为前面计算ACE的时候已经加上1了
		iTotal += 10;
	}

	return iTotal;
}