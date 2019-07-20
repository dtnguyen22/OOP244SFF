#include <iostream>
#include <cstring>
#include "SuperHero.h"
#include "Hero.h"


using namespace std;

namespace sict {

	SuperHero::SuperHero() { //auto call to base class constructor first, then derived 
		this->m_def = 0;
		this->m_power = 0;
	}
	//same here
	//atk must be positive it means > 0
	SuperHero::SuperHero(const char* name, int health, int attack, int power, int defend) : Hero(name, health, attack) {
		if (name != nullptr && name[0] != '\0' &&
			health < 99 && health > 0 && attack > 0 && defend > 0) {
			this->m_power = power;
			this->m_def = defend;
		}
		else {
			*this = SuperHero();
		}
	}
	//atk have to > 0, it is already validated by constructor.
	int SuperHero::attackStrength() const {
		return (Hero::attackStrength() > 0 ? this->m_power + Hero::attackStrength() : 0 );
	}

	int SuperHero::defend() const {
		return (Hero::attackStrength() > 0 ? this->m_def : 0);
	}

	void SuperHero::operator-=(int atk) {
		Hero::operator-=(atk);
	}



	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero tmp1 = first;
		SuperHero tmp2 = second;
		int round = 0;
		int dam1 = 0, dam2 = 0;
		while (tmp1.isAlive() && tmp2.isAlive() && round <= 100) {
			dam1 = tmp2.attackStrength() - tmp1.defend();
			dam2 = tmp1.attackStrength() - tmp2.defend();
			tmp1 -= dam1;
			tmp2 -= dam2;
			round++;
		}
		cout << "Super Fight! " << tmp1 << " vs " << tmp2 << " : Winner is ";
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
		//if both are dead, get the left one
		return (tmp1.isAlive() ? first : second);
	}
}