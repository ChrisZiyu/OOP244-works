/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 1
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name  Christian Ziyu Ukiike          Date:5/26/2023            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	 
	 
	/* TODO: Declare read prototypes*/
	
	bool read(char* postalCode);

	bool read(int* noPopulation);

	

}
#endif // !SDDS_FILE_H_
