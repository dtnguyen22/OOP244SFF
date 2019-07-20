// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: iAccount.h
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
///////////////////////////////////////////////////

#ifndef _SICT_IACCOUNT_H
#define _SICT_IACCOUNT_H
namespace sict {
	class iAccount {

	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;

	};
	iAccount* CreateAccount(const char *, double);
	//initialize new account
}


#endif // !_SICT_IACCOUNT_H
