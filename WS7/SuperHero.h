#ifndef _SICT_SUPERHERO_H
#define _SICT_SUPERHERO_H

#include <iostream>
#include "Hero.h"


namespace sict {

	class SuperHero: public Hero {
		int m_power;
		int m_def;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int atk, int power, int def);
		int attackStrength() const;
		int defend() const;
		void operator-=(int atk);

	};
	const SuperHero& operator*(const SuperHero&first, const SuperHero&second);

}


#endif // !
