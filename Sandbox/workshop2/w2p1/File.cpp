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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }



    // TODO: read functions go here

    bool read(char* m_name) {

        return fscanf(fptr,"%[^\n]\n", m_name) == 1;
    }

    bool read(int* emp_no) {
        if (fptr == nullptr) {
            return false; // File is not open
        }

        return fscanf(fptr, "%d,", emp_no) == 1;
    }

    bool read(double* salary) {
        if (fptr == nullptr) {
            return false; // File is not open
        }

        return fscanf(fptr, "%lf,", salary) == 1;
    }
    
}