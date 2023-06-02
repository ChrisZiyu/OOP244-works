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
#include <iostream>
#include "ShoppingList.h"
#include "Utils.h"
using namespace std;
using namespace sdds;

const bool APP_OS_WINDOWS = true;



    

    int main() {
        bool done = false;
        loadList();
       
        while (!done) {
            system(APP_OS_WINDOWS ? "cls" : "clear");
            switch (listMenu()) {
            case 1:
                toggleBought();
                break;
            case 2:
                addItemToList();
                break;
            case 3:
                removeItemfromList();
                break;
            case 4:
                removeBoughtItems();
                break;
            case 5:
                clearList();
                break;
            default:

                done = true;
            }
        }
        saveList();
        return 0;
    }

