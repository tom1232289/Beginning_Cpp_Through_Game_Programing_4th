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
	//  �����һ����Ϊ����Ϊ0�������ǳ��µģ�ֱ�ӷ���0
	if (m_cards.at(0)->GetValue() == 0)
		return 0;
	// �����Ƶĵ�������ACE�ĵ�����Ϊ1
	int iTotal = 0;
	for (auto iter = m_cards.begin(); iter != m_cards.end(); ++iter) {
		iTotal += (*iter)->GetValue();
	}
	// ȷ�������Ƿ����ACE
	bool bIsContainAce = false;
	for (auto iter = m_cards.begin(); iter != m_cards.end(); ++iter) {
		if ((*iter)->GetValue() == Card::ACE) {
			bIsContainAce = true;
		}
	}
	// ���������ACE���ҵ����㹻С����ACE�ĵ�����Ϊ11
	if (bIsContainAce && iTotal <= 11) {
		// ����ֻ��Ҫ�ټ���10�ͺ��ˣ���Ϊǰ�����ACE��ʱ���Ѿ�����1��
		iTotal += 10;
	}

	return iTotal;
}