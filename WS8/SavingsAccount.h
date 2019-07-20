// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: SavingsAccount.h
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
///////////////////////////////////////////////////

#ifndef _SICT_SAVINGSACCOUNT_H
#define _SICT_SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {

	private:
		double m_savingRate;

	public:
		SavingsAccount(double, double);
		//base + interest earned at the end of the month
		void monthEnd();
		//
		void display(std::ostream&) const;
	};
}





#endif // !
