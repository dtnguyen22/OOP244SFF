// Final Project Milestone 2 - Error Class
// Error.h
// DucTai Nguyen - 147942171 - dtnguyen22@myseneca.ca
/////////////////////////////////////////////////////////////////
#ifndef _SICT_ERROR_H
#define _SICT_ERROR_H
#include <iostream>
namespace aid {
	class Error {
		char* m_errorMessage;
	public:
		explicit Error(const char * errorMessage = nullptr);
		~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream& os, const Error& rhs);
}

#endif