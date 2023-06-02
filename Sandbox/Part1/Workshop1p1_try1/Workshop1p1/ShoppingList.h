/*
*****************************************************************************
							  ShoppingList.h
Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 18/05/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H


namespace sdds {

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
	int listMenu();

}




#endif // SDDS_SHOPPINGLIST_H
