//==========================================================================
// cs12xcm                         Homework 9           Matt Roth 
//
// March 15 2019	
//--------------------------------------------------------------------------
// File: Driver.h
//
// Description:			The definitions for UCSDStudent with the overloaded 
//					operator functions and three argument constructors.
//					This class will define the testing behavior for
//					the Tree program. The main data fields are the name and the 
//					student number. A UCSDStudent will be inseted into the Tree
//					within a TNode, including all of its data, such as name and
//					student number. The overloaded method in the UCSDStudent 
//					class will define specific behavior for the UCSDStudent 
//					as used polymorphically in the Tree.
//==========================================================================

#ifndef DRIVER_H
#define DRIVER_H

#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

//=========================================================================
// class UCSDStudent 
//
// Description:		This class will define the testing behavior for
//				the Tree program. The main data fields are the name and the 
//				student number. A UCSDStudent will be inseted into the Tree
//				within a TNode, including all of its data, such as name and
//				student number. The overloaded method in the UCSDStudent 
//				class will define specific behavior for the UCSDStudent 
//				as used polymorphically in the Tree.
//
//  
// Data Fields:
//
//     name - the name of the student    
//     studentnum - the number of the student 
//     
//
// Public functions:
//
//					UCSDStudent - constructor(s) for initialization
//					ostream & operator - the ostream method 
//					* assign - the assign pointer and long 
//					operator const char * - overrride the char *   
//					operator == - override the == method
//					operator > - override the > method
//==========================================================================
class UCSDStudent {

	//declaring a friend for accesibility to the ostream method 
	friend ostream & operator << (ostream &, const UCSDStudent &);
	friend UCSDStudent * assign (UCSDStudent *, long);	

	char name[16];	//UCSDStudent name
	long studentnum;	//UCSDStudent number 

	public:

	UCSDStudent (char * nm, long stunum = 0) : studentnum (stunum) 
	/***********************************************************************
	% Routine Name : UCSDStudent:: UCSDStudent (public)
	% File :         Driver.h
	% 
	% Description :	Creates a new UCSDStudent initializing the name and
	%				number parameters.
	***********************************************************************/
	{
		memset (name, '\0', sizeof (name));
		strcpy (name, nm);
	}

	UCSDStudent (void) : studentnum (0) 
	/***********************************************************************
	% Routine Name : UCSDStudent:: UCSDStudent (public)
	% File :         Driver.h
	% 
	% Description :	Creates a new UCSDStudent initializing the name and
	%				number parameters.
	***********************************************************************/
	{
		memset (name, '\0', sizeof (name));
	}

	UCSDStudent (const UCSDStudent & ucsdstudent) 
	/***********************************************************************
	% Routine Name : UCSDStudent:: UCSDStudent (public)
	% File :         Driver.h
	% 
	% Description :	Creates a new UCSDStudent initializing the name and
	%				number parameters.
	***********************************************************************/
	{
		memset (name, '\0', sizeof (name));
		strcpy (name, ucsdstudent.name);
		studentnum = ucsdstudent.studentnum;
	}

	operator const char * (void) const
	/***********************************************************************
	% Routine Name : operator const char *  
	% File :         Driver.h
	% 
	% Description :	overloads the char * method to return a name 
	%				for the UCSDStudent
	***********************************************************************/
	{
		return name;
	}

	long operator == (const UCSDStudent & vvv) const 
	/***********************************************************************
	% Routine Name : operator ==  
	% File :         Driver.h
	% 
	% Description :	overloads the == method to check for equality between 
	%				names 
	***********************************************************************/
	{
		return ! strcmp (name, vvv.name);
	}

	long operator > (const UCSDStudent & vvv) const 
	/***********************************************************************
	% Routine Name : operator >  
	% File :         Driver.h
	% 
	% Description :	overloads the > method to check for equality 
	***********************************************************************/
	{
		return (strcmp (name, vvv.name) > 0) ? 1 : 0;
	}
};

#endif
