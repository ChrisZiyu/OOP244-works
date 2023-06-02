/*
*****************************************************************************
							 Utils.h
Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 18/05/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
#include <cstdio>


namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
	
}



#endif // SDDS_UTILS_H

