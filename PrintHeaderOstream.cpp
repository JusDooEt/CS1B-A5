/*******************************************************************************
 * AUTHOR        : Cameron Abo
 * STUDENT ID    : 387130
 * Assignment #3 : Searching Linked Lists
 * CLASS         : CS1B
 * SECTION       : MW: 7:30p
 * DUE DATE      : 4/7/23
 ******************************************************************************/
#include "HeaderA5.h"

/*******************************************************************************
 * FUNCTION PrintHeaderOstream
 * _____________________________________________________________________________
 * This function receives an cout or file output variable assignment name, type,
 * 		and number and outputs a student header with the student's information.
 *
 * 		==> returns nothing
 * _____________________________________________________________________________
 * 	PRE-CONDITIONS
 * 		output: Output needs to be previously defined
 * 		asName: Assignment name needs to be previously defined
 * 		asNum : Assignment number has to be previously defined
 * 		asType: Assignment type has to be previously defined
 *
 * 	POST-CONDITIONS
 * 		This function will output a class heading
 *
 ******************************************************************************/
void PrintHeaderOstream(ostream &output,  //IN  - outputs using cout or ofstream
						string asName,	  //IN  - Programmer name
						int    asNum,  	  //IN  - Assignment Number
						char   asType)	  //IN  - Assignment type
{
	output << left;
	output << "***************************************************************\n";
	output << "*   PROGRAMMED BY : Cameron Abo\n";
	output << "*   " << setw(14) << "STUDENT ID" << ": 387130\n";
	output << "*   " << setw(14) << "CLASS"      << ": CS1B - MW - 7:30p\n";
	output << "*   " ;

	//	PROCESSING - This will adjust setws and format appropriately based on
	//				 if this is a lab 'L' or assignment
	if (toupper(asType) == 'L')
	{
		output << "LAB #" << setw(9);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(2);
	}
	output << asNum << ": " << asName << endl;
	output << "***************************************************************\n";
	output << right;
}

