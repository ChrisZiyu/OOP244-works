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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "File.h"
#include "ShoppingRec.h"
#include "Utils.h"


using namespace std;

const int MAX_QUANTITY_VALUE = 50;

namespace sdds {

    ShoppingRec getShoppingRec() {
        ShoppingRec R = {};
        cout << "Item name: ";
        readCstr(R.m_title, MAX_TITLE_LENGTH);
        cout << "Quantity: ";
        R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
        return R;
    }
    void displayShoppingRec(const ShoppingRec* shp) {
        cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
            " qty:(" << shp->m_quantity << ")" << endl;
    }
    void toggleBoughtFlag(ShoppingRec* rec) {
        rec->m_bought = !rec->m_bought;

    }
    bool isShoppingRecEmpty(const ShoppingRec* shp) {
        return shp->m_title[0] == 0;
    }
}