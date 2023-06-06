/*
*****************************************************************************
                              calorieList.h
Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 6/5/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_

#include <iostream>
#include "Food.h"
const int BAD_DIET_THRESHHOLD = 1700;

namespace sdds {
    class CalorieList {
        Food* foods;
        int size;
        int counts;
        bool hasValidFood = false;

    public:
        CalorieList();
        /*~CalorieList();*/
        void init(int listSize);
        int getCalories();
        bool add(const char* itemName, int calories, int when);
        void display() const;
        void deallocate();
       
        
    };
}

#endif // SDDS_CALORIELIST_H_
