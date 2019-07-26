// Workshop 9 - Function Templates
// File: Data.cpp
// DucTai Nguyen - dtnguyen22@myseneca.ca - 147942171
///////////////////////////////////////////////////
#include <iostream>
#include "Data.h"
using namespace std;
namespace sict {


	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		cout << "Population change from 2000 to 2004 is ";
		cout.precision(2);
		cout<< static_cast<double>(population[n - 1] - population[0]) / 1000000;
		cout << " million"<<endl;
		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		cout << "Violent Crime trend is ";
		double rate = violentCrimeRate[n - 1] - violentCrimeRate[0];
		if (rate > 0) {
			cout << "up";
		}
		else if (rate < 0) {
			cout << "down";
		}
		else {
			cout << "unchange";
		}
		cout << endl;
		// Q3 print the GTA number accurate to 0 decimal places
		cout << "There are " << average(grandTheftAuto, n)/1000000 << " million Grand Theft Auto incidents on average a year" << endl;
		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, 5)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, 5)) << endl;
	}

}

