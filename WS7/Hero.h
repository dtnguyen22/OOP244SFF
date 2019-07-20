#ifndef _SICT_HERO_H
#define _SICT_HERO_H

#include <iostream>


namespace sict {
	const int MAX_HEALTH = 99;
	const int MIN_HEALTH = 1;
	const int MAX_ROUNDS = 100;
	const int MAX_LENGTH = 40;
	class Hero {
		char m_name[MAX_LENGTH + 1];
		int m_health;
		int m_atk;
	public:
		Hero();
		Hero(const char* name, int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);

}


#endif // !
