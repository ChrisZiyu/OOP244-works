#include "Population.h"
#include <iostream>
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	Population* pop = nullptr;
	bool ok = false;
	int rec = 0;
	bool load(const char* filename) {
		if (openFile(filename)) {
			 rec = noOfRecords();
			if (rec == 0)
				return false;
			pop = new Population[rec];
			for (int i = 0; i < rec; i++)
			{
				char pCode[128];
				int populationNo;

				if (read(pCode) && read(&populationNo))
				{
					strCpy(pop[i].postalCode, pCode);
					pop[i].noPopulation = populationNo;
					
					
				}


			}
			sort();
			closeFile();
			return true;
		}
		return false;
	
	}

	void display()
	{
		if (pop != nullptr && rec>0) {
			cout << "Postal Code: population" << endl;
			cout << "-------------------------" << endl;
			
			for (int i = 0; i < rec; i++) {
				cout << i + 1 << "- ";
				cout << pop[i].postalCode << ": ";
				cout<< pop[i].noPopulation << endl;
			}


			cout << "-------------------------" << endl;

			int totalPopulation = 0;
			for (int i = 0; i < rec; i++) {
				totalPopulation += pop[i].noPopulation;
			}

			cout << "Population of Canada: " << totalPopulation << endl;
		}
		else {
			cout << "No population data loaded." << endl;
		}
	}
// TODO: Implementation for the deallocateMemory function goes here

	void deallocateMemory() {
		delete[] pop;
		pop = nullptr;
		
			

	}

	void sort()
	{
		int i, j;
		Population temp;
		for (i = rec - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (pop[j].noPopulation > pop[j + 1].noPopulation) {
					temp = pop[j];
					pop[j] = pop[j + 1];
					pop[j + 1] = temp;
				}
			}
		}
    }

	

	bool load() {
		ok = load("PCpopulation.csv");
		if (!ok)
		cout << "Could not open data file." << endl;
		return ok;
	}
}




	

