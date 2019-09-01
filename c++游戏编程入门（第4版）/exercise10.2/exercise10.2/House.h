#pragma once

#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const string &name = "House") :
		GenericPlayer(name) {}
	virtual ~House() {}
	virtual bool IsHitting() const override { return (GetTotal() <= 16); }
	void FlipFirstCard();
};

#endif // !HOUSE_H
