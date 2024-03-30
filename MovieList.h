/*
 * MovieList.h
 *
 *  Created on: May 19, 2023
 *      Author: Cam
 */

#ifndef MOVIELIST_H_
#define MOVIELIST_H_
#include "StackList.h"

class MovieList: public StackList
{
public:
	 /*********************************
	 *** CONSTRUCTOR / DESTRUCTOR ****
	 *********************************/
	MovieList();
	~MovieList();

	/******************
	 **** MUTATORS ****
	 ******************/
	void CreateList(string inputFileName);

	/******************
	 **** ACCESSORS ***
	 ******************/
	void OutputList(string outputFileName) const;

private:

	string WordWrap(string plot) const;
	string FormatCheck(string checkString, int setwNum) const;
	void   OutputClassHeader(ostream &fout) const;

	int maxLength;	//CALC - Max length of the formatted text box

};

/*********************************
 *** CONSTRUCTOR / DESTRUCTOR ****
 *********************************/

/*******************************************************************************
* MovieList();
*
* 	CONSTRUCTOR; This method initializes a new object of class MovieList
* -----------------------------------------------------------------------------
* 	Parameters: none
* -----------------------------------------------------------------------------
* 	Return: none
*******************************************************************************/

/*******************************************************************************
* ~MovieList();
*
* 	DESTRUCTOR; This method uninitializes an object of MovieList
* -----------------------------------------------------------------------------
* 	Parameters: none
* -----------------------------------------------------------------------------
* 	Return: none
*******************************************************************************/


/******************
**** MUTATORS ****
******************/

/*******************************************************************************
* void CreateList(string inputFileName);
*
* 	MUTATOR; This method initializes a stack of DVDNodes from an input files
* 				given in the parameters and calls on the Push method from
* 				inherited StackList class.
* -----------------------------------------------------------------------------
* 	Parameters:
* 		inputFileName: Name of the input file.
* -----------------------------------------------------------------------------
* 	Return: none
*******************************************************************************/


/******************
 **** ACCESSORS ***
 ******************/

/*******************************************************************************
* void OutputList(string outputFileName) const;
*
* 	ACCESSOR; This method outputs all the contents of the stack in a formatted
* 				table to a file.
* -----------------------------------------------------------------------------
* 	Parameters:
* 		outputFileName: Name of the output file.
* -----------------------------------------------------------------------------
* 	Return: none
*******************************************************************************/

/*******************************************************************************
* string WordWrap(string plot) const;
*
* 	ACCESSOR; This method formats the given movie synopsis with a word wrap
* -----------------------------------------------------------------------------
* 	Parameters:
* 		plot: A movie synopsis
* -----------------------------------------------------------------------------
* 	Return:
*		The word wrapped movie synopsis.
*******************************************************************************/

/*******************************************************************************
* string FormatCheck(string checkString, int setwNum) const;
*
* 	ACCESSOR; This method formats the given string and setw values to format to.
* 				It will check if the string is longer than the setw value and
* 				add ellipsis to the cut off string if larger than the setw
* 				value.
* -----------------------------------------------------------------------------
* 	Parameters:
* 		checkString: String of text the method is checking and formatting
* 		setwNum	   : The setw value the method checks the string length against.
* -----------------------------------------------------------------------------
* 	Return:
*		The formatted string.
*******************************************************************************/

/*******************************************************************************
* void OutputClassHeader(ostream &fout) const;
*
* 	ACCESSOR; This method receives an cout or file output variable assignment
* 				name, type, and number and outputs a student header with the
* 				student's information.
* -----------------------------------------------------------------------------
* 	Parameters:
* 		fout: Ostream output variable
* -----------------------------------------------------------------------------
* 	Return:
*		none;
*******************************************************************************/
#endif /* MOVIELIST_H_ */
