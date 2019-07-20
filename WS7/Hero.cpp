#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {

	Hero::Hero() {
		this->m_atk = 0;
		this->m_health = 0;
		this->m_name[0] = '\0';
	}

	Hero::Hero(const char* name, int health, int attack) {
		if (name != nullptr && name[0] != '\0' &&
			health < 99 && health > 0 && attack > 0) {
			strncpy(this->m_name, name, MAX_LENGTH);
			this->m_name[MAX_LENGTH] = '\0';
			this->m_health = health;
			this->m_atk = attack;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack) {
		if (attack > 0) {
			if (attack > this->m_health) {
				this->m_health = 0;
			}
			else {
				this->m_health -= attack;
			}
		}
	}

	bool Hero::isAlive() const {
		return (this->m_health > 0);
	}

	int Hero::attackStrength() const {
		return (this->m_atk > 0 ? this->m_atk : 0);
	}



	ostream& operator<<(ostream& os, const Hero& hero) {
		if (hero.m_name == nullptr || hero.m_name[0] == '\0') {
			os << "No hero";
		}
		else {
			os << hero.m_name;
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero tmp1 = first;
		Hero tmp2 = second;
		int round = 0;
		while (tmp1.isAlive() && tmp2.isAlive() && round <= 100) {
			tmp1 -= tmp2.attackStrength();
			tmp2 -= tmp1.attackStrength();
			round++;
		}
		cout << "Ancient Battle! " << tmp1 << " vs "<< tmp2 << " : Winner is ";
		if (tmp1.isAlive() && !tmp2.isAlive()) {
			cout << tmp1;
		}
		else if (!tmp1.isAlive() && tmp2.isAlive()) {
			cout << tmp2;
		}
		else { //draw
			cout << tmp1;
		}
		cout << " in " << round << " rounds." << endl;
		return (tmp1.isAlive() ? first : second);
	}


}