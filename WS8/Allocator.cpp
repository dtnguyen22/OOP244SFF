// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Acclocator.cpp
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
///////////////////////////////////////////////////

#include <iostream>
#include "iAccount.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"


namespace sict {
	double interestRate = 0.05; //5 percent
	double tFee = 0.5;
	double meFee = 2.00;
	iAccount* CreateAccount(const char* accountName, double amount) {
		iAccount *acc = nullptr;
		if (accountName != nullptr && accountName[0] != '\0') {
			if (accountName[0] == 'S') {
				acc = new SavingsAccount(amount, interestRate);
			}
			if (accountName[0] == 'C') {
				acc = new ChequingAccount(amount, tFee, meFee);
			}
		}
		return acc;
	}
}