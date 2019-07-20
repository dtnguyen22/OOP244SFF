// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Account.cpp
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
///////////////////////////////////////////////////


#include <iostream>
#include "Account.h"


namespace sict {
	//if positive -> assign, if not set balance to 0
	Account::Account(double iAmount) {
		if (iAmount > 0) {
			this->m_currentBalance = iAmount;
		}
		else {
			this->m_currentBalance = 0.0;
		}
	}
	//add money
	bool Account::credit(double cAmount) {
		if (cAmount > 0) {
			this->m_currentBalance += cAmount;
		}
		else {
			//if cAmount>0 return true, if not, set cAmount to 0 to return false
			cAmount = 0;
		}
		return cAmount;
	}
	//substract money
	bool Account::debit(double dAmount) {
		if (dAmount > 0) {
			this->m_currentBalance -= dAmount;
		}
		else {
			dAmount = 0;
		}
		return dAmount;
	}
	//return your current money in the bank which is a big zero
	double Account::balance() const {
		return this->m_currentBalance;
	}
}