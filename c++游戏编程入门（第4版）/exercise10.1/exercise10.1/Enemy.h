#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

using namespace std;

class Enemy
{
public:
	Enemy() {}
	void Attack() const {
		cout << "Attack inflicts " << m_iDamage << " damage points!" << endl;
	}
protected:
	int m_iDamage = 10;
};

class Boss : public Enemy
{
public:
	Boss() {}
	void SpecialAttack() const {
		cout << "Special Attack inflicts " << (m_iDamageMultiplier*m_iDamage) << " damage points!" << endl;
	}
protected:
	int m_iDamageMultiplier = 3;
};

class FinalBoss : public Boss
{
public:
	void MegaAttack() const {
		cout << "Mega Attack inflicts " << (10 * m_iDamageMultiplier*m_iDamage) << " damage points!" << endl;
	}
private:
	int m_iDamageMega = 10;
};

#endif // !ENEMY_H
