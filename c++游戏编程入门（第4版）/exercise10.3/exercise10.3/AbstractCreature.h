#pragma once

#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <iostream>

using namespace std;

class Creature
{
public:
	Creature(int health = 100) :
		m_iHealth(health) {}
public:
	virtual void Greet() const = 0;
	virtual void DisplayHealth() const { cout << "Health: " << m_iHealth << endl; }
protected:
	int m_iHealth = 100;
};

class Orc : public Creature
{
public:
	Orc(int health = 120) :
		Creature(health) {}
	virtual void Greet() const override { cout << "The orc grunts hello" << endl; }
};

class OrcBoss : public Orc
{
public:
	OrcBoss(int health = 180):
		Orc(health){}
	virtual void Greet() const override { cout << "The orc boss growls hello." << endl; }
};

#endif // !ABSTRACTCREATURE_H
