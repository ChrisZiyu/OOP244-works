/*
*****************************************************************************
							 food.cpp
Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 6/5/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Food.h"
#include "cstring.h"



using namespace std;

namespace sdds {
	Food::Food() {
		name[0] = '\0';
		calories = 0;
		timeOfConsumption = 0;
	}
	bool Food::isValid()const
	{
	
		return name[0] != '\0' && calories >= 0 && calories <= 3000 &&
			(timeOfConsumption >= 1 && timeOfConsumption <= 4);

	}
	int Food::getCalories()
	{
		return calories;
	}
	void Food::setName(const char* foodName)
	{
		strnCpy(name, foodName,MAX_NAME_LENGTH);
		name[MAX_NAME_LENGTH]='\0';
	}
	void Food::setCalories(int foodCalories){
		calories = foodCalories;
	}
	void Food::setTimeOfConsumption(int foodTime)
	{
		timeOfConsumption = foodTime;
	}
	void Food::display() const
	{
		
		
		if (isValid( )) {
			cout.setf(ios::fixed);
			cout.setf(ios::left);

			cout << "| ";
			cout.width(MAX_NAME_LENGTH);
			cout.fill('.');
			cout << name;
			cout << " |";

			cout.unsetf(ios::left);// Unset the fill character setting


			cout.width(5);
			cout.fill(' ');
			cout<< right<< calories;
			cout << " | ";
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);

			switch (timeOfConsumption) {
			case 1:
				std::cout << "Breakfast";
				cout.width(1);
				cout << " ";
				break;
			case 2:
				std::cout << "Lunch";
				cout.width(5);
				cout << " ";
				break;
			case 3:
				std::cout << "Dinner";
				cout.width(4);
				cout << " ";
				break;
			case 4:
				std::cout << "Snack";
				cout.width(5);
				cout << " ";
				break;
			default:
				std::cout << "Unknown";
				break;
			}
			std::cout << " |" << std::endl;
		}
		
		
	}
	
}
