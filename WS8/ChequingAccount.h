// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
///////////////////////////////////////////////////


#ifndef _SICT_CHEQUINGACCOUNT_H
#define _SICT_CHEQUINGACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {
	private:
		double m_tFee;
		double m_meFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}



#endif // !_SICT_CHEQUINGACCOUNT_H
