//==========================================================================
// cs12xcm                         Homework 9	           Matt Roth 
//
// March 15 2019	
//--------------------------------------------------------------------------
// File: Driver.c
//
// Description:		The Driver will implement and test the functionality of the
//				Tree data structure in the Tree.c file. The driver allows
//				for user input and output. The read and write from and to 
//				file has been added as a function of the driver. The driver
//				will shift between taking user inout and reading input from
//				a commands file. The intermediary between the user and the
//				Tree manipulations will be performed on the driver. 
// 
//==========================================================================

#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <getopt.h>
#include "Driver.h"
#include "SymTab.h"

using namespace std;

/* DO NOT CHANGE:  This file is used in evaluation */

#ifdef NULL
#undef NULL
#define NULL 0
#endif

ostream & operator << (ostream & stream, const UCSDStudent & stu) {
        return stream << "name:  " << stu.name
                << " with studentnum:  " << stu.studentnum;
}

int main (int argc, char * const * argv) {
        char buffer[BUFSIZ];
        char command;
        long number;
        char option;
		istream * is = &cin;	//pointer to accept input from a user
		ostream * os = &cout;	//pointer to output 
        

        SymTab<UCSDStudent>::Set_Debug_Off ();

        while ((option = getopt (argc, argv, "x")) != EOF){ 

        switch (option) {
                case 'x': SymTab<UCSDStudent>::Set_Debug_On ();
                        break;
                }      
        }
        
		//take the Driver.datafile as a parameter to allow for file manipulation
        SymTab<UCSDStudent> ST ("Driver.datafile");
        ST.Write (cout << "Initial Symbol Table:\n" );

        while (cin) {
				
				//if done reading input from file
				if (!*is && *is != cin) {

					//delete the pointer to cin
					delete is;

					//reset the pointer to cin
					is = &cin;

					//reset the point to cout 
					delete os;
					os = &cout;
				}

                command = NULL;         // reset command each time in loop
                *os << "Please enter a command ((f)ile, (i)nsert, "
                        << "(l)ookup, (r)emove, (w)rite):  ";
                *is >> command;

                switch (command) {
	
				//when using a file of commands to perform operations 
				case 'f': {
					
					//output to console requesting a file 
					*os << "Please enter a file name: ";

					//request the user input 
					*is >> buffer;	
					
					//if the pointer istream isnt set to cin delete is
					if (*is != cin) {

						delete is;
					}
					//set the istream pointer to a new buffer stream 
					is = new ifstream(buffer);
					
					//if the outstream pointer isnt set to cout 
					if (*os == cout) {

						//make sure not to output during reading a file 
						os = new ofstream("/dev/null");
					}

					break;					

				
				}

				case 'i': {
                        *os << "Please enter UCSD student name to insert:  ";
                        *is >> buffer;  // formatted input

                        *os << "Please enter UCSD student number:  ";
                        *is >> number;

                        UCSDStudent stu (buffer, number);

                        // create student and place in symbol table
                        ST.Insert (stu);
                        break;
                }
                case 'l': { 
                        unsigned long found;    // whether found or not

                        *os << "Please enter UCSD student name to lookup:  ";
                        *is >> buffer;  // formatted input

                        UCSDStudent stu (buffer, 0);
                        found = ST.Lookup (stu);
                        
                        if (found)
                                cout << "Student found!!!\n" << stu << "\n";
                        else
                                cout << "student " << buffer << " not there!\n";
                        break;
                        }
                case 'r': { 
                        unsigned long removed;

                        *os << "Please enter UCSD student name to remove:  ";
                        *is >> buffer;  // formatted input

                        UCSDStudent stu (buffer, 0);
                        removed = ST.Remove(stu);

                        if (removed)
                                cout << "Student removed!!!\n" << stu << "\n";
                        else
                                cout << "student " << buffer << " not there!\n";
                        break;
                }
                case 'w':
                        ST.Write (cout << "The Symbol Table contains:\n");
                }
        }

        ST.Write (cout << "\nFinal Symbol Table:\n");
		
		//output the final data associated with the Tree
		if (ST.GetOperation() != 0) {
		
			cout << "\nCost of operations: ";
			cout << ST.GetCost();
			cout << " tree accesses";
			cout << "\nNumber of operations: ";
			cout << ST.GetOperation();
			cout << "\nAverage cost: ";
			cout << (((float)(ST.GetCost()))/(ST.GetOperation()));
			cout << " tree accesses/operation\n";
		}

		else
			cout << "\nNo cost information available.\n";
		

}
