/*
*****************************************************************************
                              calorielist.cpp
Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 6/5/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "CalorieList.h"


using namespace std;

namespace sdds {
    CalorieList::CalorieList() {
        foods = nullptr;
        size = 0;
        counts = 0;
    }

    void CalorieList::init(int listSize) {
        deallocate();
        foods = new Food[listSize];
        size = listSize;
        counts = 0;
    }

    bool CalorieList::add(const char* itemName, int calories, int when) {
        if (counts >= size)
        {
            return false;
        }
        if (itemName == nullptr) {
            foods[counts].setName(nullptr); // Set the name to nullptr
            foods[counts].setCalories(calories);
            foods[counts].setTimeOfConsumption(when);
            hasValidFood = false; // Set the flag in

        }
        else {
            foods[counts].setName(itemName);
            foods[counts].setCalories(calories);
            foods[counts].setTimeOfConsumption(when);
            
        }
        counts++;
        return true;
    




    }
    void CalorieList::display() const
    {
        bool hasValidFood = false;
        int totalCalories = 0;
        int badDiet=totalCalories;
     
        cout << "+----------------------------------------------------+" << endl;
        for (int i = 0; i < size; i++)
        {
            if (foods[i].isValid()) {
              
                hasValidFood = true;
                totalCalories += foods[i].getCalories();
                badDiet = totalCalories;
                
            }
            
            
        }
        
        if (badDiet>BAD_DIET_THRESHHOLD) {
            cout << "|  Daily Calorie Consumption                         |" << endl;
            cout << "+--------------------------------+------+------------+" << endl;
            cout << "| Food name                      | Cals | When       |" << endl;
            cout << "+--------------------------------+------+------------+" << endl;
        }
        

        if (hasValidFood && badDiet>0 && badDiet<BAD_DIET_THRESHHOLD)
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
            cout << "+--------------------------------+------+------------+" << endl;
            cout << "| Food name                      | Cals | When       |" << endl;
            cout << "+--------------------------------+------+------------+" << endl;
            
        }
        
        for (int i = 0; i < size; i++) {

            if (foods[i].isValid()) {
        
                hasValidFood = true;
                foods[i].display();
            }
            else {
                hasValidFood = false;
                cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
            }

        }
        if (totalCalories>100 && totalCalories<=BAD_DIET_THRESHHOLD ){
            cout << "+--------------------------------+------+------------+" << endl;
            cout << "|    Invalid Calorie Consumption list                |" << endl;
            cout << "+----------------------------------------------------+" << endl;
        }
        if (totalCalories>BAD_DIET_THRESHHOLD) {
            

            cout << "+--------------------------------+------+------------+" << endl;
            cout << "|    Total Calories for today:   ";

            cout.unsetf(ios::left); // Unset the fill character setting
            cout.width(6);
            cout << totalCalories;
            cout << " |            |" << endl;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
            cout << "+----------------------------------------------------+" << endl;


        }
    }
    void CalorieList::deallocate() {
        delete[] foods;
        foods = nullptr;
        size = 0;
        counts = 0;
    }
}

                
           
            



        


           


        

