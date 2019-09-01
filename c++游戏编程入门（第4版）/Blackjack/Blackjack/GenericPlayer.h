#pragma once

#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "Hand.h"
#include <string>

class GenericPlayer : public Hand
{
	friend ostream & operator<<(ostream &os, const GenericPlayer & gp);
public:
	GenericPlayer(const string &name = "") :
		m_sName(name) {}
	virtual ~GenericPlayer() {}
public:
	virtual bool IsHitting() const = 0;
	bool IsBusted() const { return GetTotal() > 21; }
	void Bust() const { cout << m_sName << " busts." << endl; }
protected:
	string m_sName;
};

#endif // !GENERICPLAYER_H
