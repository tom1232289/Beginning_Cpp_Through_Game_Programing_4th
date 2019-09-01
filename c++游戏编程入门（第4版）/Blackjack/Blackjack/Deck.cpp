#include "Deck.h"

Deck::Deck()
{
	m_cards.reserve(52);
	Populate();
}

void Deck::Populate()
{
	Clear();
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
		for (int r = Card::ACE; r <= Card::KING; ++r) {
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Deal(Hand &aHand)
{
	if (!m_cards.empty()) {
		aHand.Add(m_cards.back());
		m_cards.pop_back();
	}
	else
		cout << "Out of cards. Unable to deal.";
}

void Deck::AdditionalCards(GenericPlayer & aGenericPlayer)
{
	cout << endl;
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()) {
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;
		if (aGenericPlayer.IsBusted()) {
			aGenericPlayer.Bust();
		}
	}
}