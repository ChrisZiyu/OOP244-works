/*
*****************************************************************************
							  food.h
Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 6/5/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
#include <iostream>

const int MAX_NAME_LENGTH = 30;
namespace sdds {
	
	class Food {
		char name[MAX_NAME_LENGTH+1];
		int calories;
		int timeOfConsumption;

	public:
		Food();
		void setName(const char* foodName);
		void setCalories(int foodCalories);
		void setTimeOfConsumption(int foodTime);
		void display()const;
		int getCalories();
		bool isValid()const;



		



	};
}
#endif // !SDDS_FOOD_H_
