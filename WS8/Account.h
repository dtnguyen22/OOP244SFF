// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Account.h
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
///////////////////////////////////////////////////
#ifndef _SICT_ACCOUNT_H
#define _SICT_ACCOUNT_H
#include "iAccount.h"
namespace sict {
	class Account : public iAccount {

	private:
		double m_currentBalance;

	protected:
		//return current balance
		double balance() const;

	public:
		Account(double);
		//add money
		bool credit(double);
		//subtract money
		bool debit(double);
	};

}




#endif // !_SICT_ACCOUNT_H
