// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
///////////////////////////////////////////////////
#include <iostream>
#include "SavingsAccount.h"
using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double iAmount, double iRate) : Account(iAmount) {
		if (iRate > 0) {
			this->m_savingRate = iRate;
		}
		else {
			this->m_savingRate = 0.0;
		}
	}

	void SavingsAccount::monthEnd() {
		double earned = this->m_savingRate * this->balance();
		Account::credit(earned);
	}

	void SavingsAccount::display(ostream& os) const {
		os << "Account type: Savings" << endl;
		os.setf(ios::fixed);
		os.precision(2);
		os << "Balance: $" << this->balance() << endl;
		os << "Interest Rate (%): " << this->m_savingRate*100<<endl;
	}

}