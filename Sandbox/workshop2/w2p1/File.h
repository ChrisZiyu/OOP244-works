/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 1
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name  Christian Ziyu Ukiike          Date:5/27/2023            Reason
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
	
	bool read(char* m_name);

	bool read(int* m_empNo);

	bool read(double* m_salary);

}
#endif // !SDDS_FILE_H_
