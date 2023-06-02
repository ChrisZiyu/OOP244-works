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
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees=nullptr;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }


    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee* emp_) {
        bool ok = false;
        char name[128];
        int emp_no = 0;
        double salary = 0;
        /* if reading of employee number, salay and name are successful
                allocate memory to the size of the name + 1
                and keep its address in the name of the Employee Reference

                copy the name into the newly allocated memroy

                make sure the "ok" flag is set to true
           end if
        */
        if ( read(&emp_no)&& read(&salary) && read(name))
        {
            
            int len = strLen(name);
            
            emp_->m_name= new char[len+1];
            strCpy(emp_->m_name, name);
            
            emp_->m_salary = salary;
            emp_->m_empNo = emp_no;

            ok = true;
        }

        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
    
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            while (i<noOfEmployees)
            {
                load(&employees[i]);
                i++;
            }
               
            if (i !=noOfEmployees)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted";
            }
            else
            {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }
    // TODO: Implementation for the display functions go here


    void display() {
        cout << "Employee Salary report, sorted by employee number" << std::endl;
        cout << "no- Empno, Name, Salary" << std::endl;
        cout << "------------------------------------------------" << std::endl;

        sort();
        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 <<"- ";
            display(&employees[i]);
           
        }
    }
    void display(const Employee* emp_) {
        cout << emp_->m_empNo << ": "
                    << emp_->m_name << ", "
                        << emp_->m_salary << endl;
    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        for (int i = noOfEmployees -1;i>=0; i--)
        {
            deleteBufferName(employees[i].m_name);

        }
        delete[] employees;
        employees = nullptr;
    }

    void deleteBufferName(char* name) {
        if (name) {
            delete[] name;
        }
        name = nullptr;
    }


}