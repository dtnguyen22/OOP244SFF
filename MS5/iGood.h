// Final Project - Milestone 4
// iGood.h
// Duc Tai Nguyen - 147942171
// dtnguyen22@myseneca.ca
/////////////////////////////////////////////////////////////////
#ifndef _AID_IGOOD_H
#define _AID_IGOOD_H
#include <fstream>
#include <iostream>
namespace aid{
	class iGood{
    	public:
    	virtual std::fstream& store(std::fstream& file, bool newline = true) const = 0;
        virtual std::fstream& load(std::fstream& file) = 0;
        virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool operator==(const char*) const = 0;
        virtual double total_cost() const = 0;
        virtual const char* name() const = 0;
        virtual void quantity(int) = 0;
        virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
        virtual int operator+=(int) = 0;
        virtual bool operator>(const iGood&) const = 0;
        virtual ~iGood() {};
	};
    std::ostream& operator<<(std::ostream&, const iGood &);
    std::istream& operator>>(std::istream&, iGood&);
    double operator+=(double&, const iGood&);
    iGood* CreateProduct(char tag);
}

#endif
