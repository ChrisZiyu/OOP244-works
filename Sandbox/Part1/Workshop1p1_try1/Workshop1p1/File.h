/*
*****************************************************************************
							  shoppingListApp.cpp
Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 18/05/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "ShoppingRec.h"



namespace sdds {
	
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);

}

#endif // !SDDS_FILE_H


