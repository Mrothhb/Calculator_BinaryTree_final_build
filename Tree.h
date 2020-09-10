#ifndef TREE_H
#define TREE_H

/* DO NOT ADD CODE: This file is used in evaluation
 * Changing function signatures will result in a 25% deduction.
 * adding comments is ok.
 */

#include <fstream>
#include <iostream>
using namespace std;

typedef long offset;

template <class Whatever>
struct TNode;

template <class Whatever>
class Tree {	
//=========================================================================
// class Tree
//
// Description:	The Tree class will implement all the methods that pertain 
//				to the Tree data structure. The Tree will have methods that
//				will insert data, remove data and find specific data in the
//				Tree, and each method will also delegate out its functionality
//				to the respective TNode methods. The Tree will use templates
//				functionality to accept "Whatever" data type to perform 
//				polymorphic like behavior. The Tree is based on a specific
//				Binary Tree data structure using nodes to hold the data.
//				
//  
// Data Fields:
//		
//	   friend struct TNode<Whatever> - the TNode container in Tree	
//     cost - the cost of oprerations 
//     debug_on -  the debug status
//     fio -  the file stream
//     occupancy - how many Nodes in the tree
//     operation - the amount of operations 
//     root - the root node offset
//     tree_count - the number of tree structures
//
//     
//
// Public functions:
//
//					Tree - the Tree constructor 
//					~Tree - the Tree destructor 
//					GetCost - return the cost 
//					GetOperation - return the operation count
//					IncrementCost - increment the cost variable
//					IncrementOperation - increment the operation variable 
//					Set_Debug_On - turn on debug mode
//					Set_Debug_Off - turn off debug mode
//					Insert - insert a new TNode 
//					Lookup - find a TNode with specific data 
//					Remove - remove a TNode and its data
//					ostream & Write - toString function 
//==========================================================================
        friend struct TNode<Whatever>;
        static long cost;
        static int debug_on;
        fstream * fio;
        long occupancy;
        static long operation;
        offset root;
        unsigned long tree_count;
        void ResetRoot (void);

public:
        Tree (const char *);
        ~Tree (void);

        static long GetCost ();
        static long GetOperation ();
        static void IncrementCost ();
        static void IncrementOperation ();
        static void Set_Debug_On (void);
        static void Set_Debug_Off (void);

        unsigned long Insert (Whatever &);
        unsigned long Lookup (Whatever &) const;
        unsigned long Remove (Whatever &);
        ostream & Write (ostream &) const;
};

#include "Tree.c"

#endif
