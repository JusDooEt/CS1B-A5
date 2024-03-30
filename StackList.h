/*******************************************************************************
 * AUTHOR        : Cameron Abo
 * STUDENT ID    : 387130
 * Assignment #5 : DVD Movie List Intro to OOP
 * CLASS         : CS1B
 * SECTION       : MW: 7:30p
 * DUE DATE      : 5/19/23
 ******************************************************************************/

#ifndef STACKLIST_H_
#define STACKLIST_H_
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

struct DVDNode
 {
	 string title; 				// store movie's title
	 string leadingActor; 		// store leading actor/actress
	 string supportingActor;	// store supporting actor/actress
	 string genre; 				// store movie’s genre
	 string alternateGenre; 	// store movie’s alternate genre
	 int year; 					// store movie’s release year
	 int rating; 				// store movie’s rating
	 string synopsis; 			// store movie’s synopsis
	 DVDNode *next; 			// linked list next pointer
 };

class StackList // Base Class - Using linked list implementation
{
	public:
		 /*********************************
		 *** CONSTRUCTOR / DESTRUCTOR ****
		 *********************************/
		 StackList ();
		 ~StackList ();

		 /******************
		 **** MUTATORS ****
		 ******************/
		 void Push(DVDNode newDVD); // create a DVDNode, add a
		 	 	 	 	 	 	 	// DVDNode in the stack, by adding
		 	 	 	 	 	 	 	// to the front of the linked List
		 DVDNode Pop(); 			// return the DVDNode in the top of
									// the stack, remove the DVDNode
									// from the stack, delete the DVDNode
		 /******************
		 **** ACCESSORS ****
		 ******************/
		 bool IsEmpty() const; 		// check if stack is empty
		 DVDNode Peek() const; 		// return the DVDNode at the top of the stack
		 int Size() const; 			// return the number of people in the stack

	protected:
		 DVDNode *head; 			// head pointer for stack
		 int stackCount; 			// total number of persons in the stack
};

/*********************************
 *** CONSTRUCTOR / DESTRUCTOR ****
 *********************************/
/*******************************************************************************
* StackList();
*
* 	CONSTRUCTOR; This method initializes a new object of class StackList
* -----------------------------------------------------------------------------
* 	Parameters: none
* -----------------------------------------------------------------------------
* 	Return: none
*******************************************************************************/

/*******************************************************************************
* ~StackList();
*
* 	DESTRUCTOR; This method uninitializes and deletes nodes of linked list of
* 					class StackList
* -----------------------------------------------------------------------------
* 	Parameters: none
* -----------------------------------------------------------------------------
* 	Return: none
*******************************************************************************/

/******************
**** MUTATORS ****
******************/

/*******************************************************************************
* void Push(DVDNode newDVD);
*
* 	MUTATOR; This method creates a new DVDNode pointer and adds it to the
* 					head of the linked list and reassigns head to the newly
* 					added node.
* -----------------------------------------------------------------------------
* 	Parameters:
* 		newDVD: New node being added to the stack
* -----------------------------------------------------------------------------
* 	Return: none
*******************************************************************************/

/*******************************************************************************
* DVDNode Pop();
*
* 	MUTATOR; This method removes a node from the linked list and returns the
* 				node that is now at the top of the list.
* -----------------------------------------------------------------------------
* 	Parameters: none
* -----------------------------------------------------------------------------
* 	Return:
* 		The new head of the stack.
*******************************************************************************/

/******************
 **** ACCESSORS ***
 ******************/
/*******************************************************************************
* bool IsEmpty() const;
*
* 	ACCESSOR; This method checks the stackCount to see if the stack is empty
* -----------------------------------------------------------------------------
* 	Parameters: none
* -----------------------------------------------------------------------------
* 	Return:
* 		True if the stack is empty, false if not
*******************************************************************************/

/*******************************************************************************
* DVDNode Peek() const;
*
* 	ACCESSOR; This method returns the head of the linked list
* -----------------------------------------------------------------------------
* 	Parameters: none
* -----------------------------------------------------------------------------
* 	Return:
* 		The head of the linked list
*******************************************************************************/

/*******************************************************************************
* int Size() const;
*
* 	ACCESSOR; This method returns the size of the stack
* -----------------------------------------------------------------------------
* 	Parameters: none
* -----------------------------------------------------------------------------
* 	Return:
* 		stackCount
*******************************************************************************/
#endif /* STACKLIST_H_ */
