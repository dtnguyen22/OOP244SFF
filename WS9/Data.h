// Workshop 9 - Function Templates
// File: Data.h
// DucTai Nguyen - dtnguyen22@myseneca.ca - 147942171
///////////////////////////////////////////////////
#ifndef _SICT_DATA_H
#define _SICT_DATA_H
#include <iostream>
#include <cstring>
using namespace std;

namespace sict {

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;


	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		bool success = true;
		for (int i = 0;i < n; i++) {
			input.ignore();
			input >> data[i];
			if (cin.fail()) {
				success = false;
			}
		}
		return success;
	}

	// readRow extracts a single record from input and stores n data fields in data
// - includes error checking: checks if the name of the row is valid.
	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	template <typename T>
	void display(const char *name, const T* data, int n) {
		cout.width(COLUMN_WIDTH + 5);
		cout << fixed << right << name;
		for (int i = 0; i < n; i++) {
			cout.width(COLUMN_WIDTH);
			cout.precision(1);
			cout << data[i];
		}
		cout << endl;
	}

	// max returns the largest item in data
	template <typename T>
	const T max(const T* data, int n) {
		T maxx = data[0];
		for (int i = 1; i < n - 1; i++) {
			if (maxx < data[i + 1]) {
				maxx = data[i + 1];
			}
		}
		return maxx;
	}
	// min returns the smallest item in data
	template <typename T>
	T min(const T* data, int n) {
		T minn = data[0];
		for (int i = 1; i < n - 1; i++) {
			if (minn > data[i + 1]) {
				minn = data[i + 1];
			}
		}
		return minn;
	}

	template <typename T>
	T sum(const T* data, int n) {
		T sum = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}
		return sum;
	}

	// average returns the average of n items in data

	template <typename T>
	double average(const T* data, int n) {
		return sum(data, n) / n;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}



#endif // !_SICT_DATA_H

