#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

	struct Population {
		
		char postalCode[5];
		int noPopulation;
		
	};
	void sort();
	bool load();
	bool load(const char* filename);

	void display();

	void deallocateMemory();


}
#endif // SDDS_POPULATION_H_