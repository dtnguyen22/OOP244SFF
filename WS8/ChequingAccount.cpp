// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
///////////////////////////////////////////////////

#include <iostream>
#include "ChequingAccount.h"
using namespace std;


namespace sict {
	ChequingAccount::ChequingAccount(double iAmount, double tFee, double meFee): Account(iAmount){
		if (tFee > 0) {
			this->m_tFee = tFee;
		}
		else {
			this->m_tFee = 0;
		}
		if (meFee > 0) {
			this->m_meFee = meFee;
		}
		else {
			this->m_meFee = 0;
		}
	}
	////only debits tFee if credits successfully
	bool ChequingAccount::credit(double cAmount) {
		if (Account::credit(cAmount)) {
			Account::debit(this->m_tFee); 
		}
		else {
			cAmount = 0;
		}
		return cAmount;
	}
	//only debits tFee if debits successfully
	bool ChequingAccount::debit(double dAmount) {
		if (Account::debit(dAmount)) {
			Account::debit(this->m_tFee);
		}
		else {
			dAmount = 0;
		}
		return dAmount;
	}

	//this one does not charge tFee so I use debit() of Account, if it does charge tFee, then use Chequing::debit()
	void ChequingAccount::monthEnd() {
		Account::debit(this->m_meFee);
	}

	void ChequingAccount::display(ostream& os) const {
		os << "Account type: Chequing" << endl;
		os.setf(ios::fixed);
		os.precision(2);
		os << "Balance: $" << this->balance() << endl;
		os << "Per Transaction Fee: " << this->m_tFee << endl;
		os << "Monthly Fee: " << this->m_meFee << endl;

	}
}

