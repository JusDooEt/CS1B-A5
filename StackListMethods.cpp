/*******************************************************************************
 * AUTHOR        : Cameron Abo
 * STUDENT ID    : 387130
 * Assignment #5 : DVD Movie List Intro to OOP
 * CLASS         : CS1B
 * SECTION       : MW: 7:30p
 * DUE DATE      : 5/19/23
 ******************************************************************************/
#include "StackList.h"
 /*********************************
 *** CONSTRUCTOR / DESTRUCTOR ****
 *********************************/
/*******************************************************************************
* METHOD StackList: Class StackList
* ______________________________________________________________________________
*
* This method initializes a new object of class StackList
*
* RETURNS:
*	--> nothing
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		stackCount : Must be previously declared in StackList
*		head	   : Must be previously declared in StackList
*
*	POST-CONDTIONS:
*		a new object of class StackList will be created.
*		stackCount: will be set to 0
*		head	  : Set to NULL
*******************************************************************************/
StackList::StackList()
{
	stackCount = 0;
	head 	   = NULL;
}

/*******************************************************************************
* METHOD ~StackList: Class StackList
* ______________________________________________________________________________
*
* This method uninitializes and deletes nodes of linked list of class StackList
*
* RETURNS:
*	--> nothing
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		An object of StackList must be declared.
*
*	POST-CONDTIONS:
*		Linked List of class StackList will be deleted.
*******************************************************************************/
StackList::~StackList()
{
	DVDNode *dvdPtr;		//CALC - New pointer for a node
	dvdPtr = head;
	while(dvdPtr != NULL)
	{
		head = head -> next;
		delete dvdPtr;

		dvdPtr = head;
	}
}

/******************
 **** MUTATORS ****
 ******************/
/*******************************************************************************
* METHOD Push: Class StackList
* ______________________________________________________________________________
*
* 	This method creates a new DVDNode pointer and adds it to the head of the
* 		linked list and reassigns head to the newly added node.
*
* RETURNS:
*	--> nothing
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		newDVD: Must be previously defined
*		head  : Must be previously defined
*
*	POST-CONDTIONS:
*		A new node will be added to the top of the stack.
*		head  : Will be assigned to a new node
*******************************************************************************/
void StackList::Push(DVDNode newDVD)
{
	DVDNode *dvdPtr;		//CALC - New pointer for a node
	dvdPtr = new DVDNode;

	*dvdPtr = newDVD;
	dvdPtr -> next = head;
	head = dvdPtr;
	dvdPtr = NULL;
}

/*******************************************************************************
* METHOD Pop: Class StackList
* ______________________________________________________________________________
*
* 	This method removes a node from the linked list and returns the node that
* 		is now at the top of the list.
*
* RETURNS:
*	--> The new head of the stack
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		Must check that head is not already equal to NULL
*		head  : Must be previously defined
*
*	POST-CONDTIONS:
*		A new node will be deleted from the top of the stack.
*		head  : Will be assigned to a new node
*******************************************************************************/
DVDNode StackList::Pop()
{
	DVDNode *dvdPtr;		//CALC - New pointer for a node

	dvdPtr = head;
	head   = dvdPtr -> next;
	delete dvdPtr;
	dvdPtr = NULL;

	return *head;
}

/******************
 **** ACCESSORS ***
 ******************/
/*******************************************************************************
* METHOD IsEmpty: Class StackList
* ______________________________________________________________________________
*
* 	This method checks the stackCount to see if the stack is empty
*
* RETURNS:
*	--> True or False if the stack is empty
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		stackCount: Must be previously defined
*
*	POST-CONDTIONS:
*		will return true of false.
*******************************************************************************/
bool StackList::IsEmpty() const
{
	bool valid;		//OUT - True if stack is empty, false if not.

	if(stackCount > 0)
	{
		valid = false;
	}
	else
	{
		valid = true;
	}
	return valid;
}

/*******************************************************************************
* METHOD Peek: Class StackList
* ______________________________________________________________________________
*
* 	This method returns the head of the linked list
*
* RETURNS:
*	--> Head of the linked list
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		head: Must be previously defined
*
*	POST-CONDTIONS:
*		returns the head of the stack
*******************************************************************************/
DVDNode StackList::Peek() const
{
	return *head;
}

/*******************************************************************************
* METHOD Size: Class StackList
* ______________________________________________________________________________
*
* 	This method returns the size of the stack
*
* RETURNS:
*	--> stackCount
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		stackCount: Must be previously defined
*
*	POST-CONDTIONS:
*		returns stackCount
*******************************************************************************/
int StackList::Size() const
{
	return stackCount;
}
