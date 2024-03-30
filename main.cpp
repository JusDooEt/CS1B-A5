/*******************************************************************************
 * AUTHOR        : Cameron Abo
 * STUDENT ID    : 387130
 * Assignment #5 : DVD Movie List Intro to OOP
 * CLASS         : CS1B
 * SECTION       : MW: 7:30p
 * DUE DATE      : 5/19/23
 ******************************************************************************/
#include "HeaderA5.h"
#include "StackList.h"
#include "MovieList.h"

/*******************************************************************************
 * DVD Movie List Intro to OOP:
 * ----------------------------------------------------------------------------
 * 	This program ask for an input and output file name. It will then read
 * 		in a list of movies and their information from the input file and store
 * 		it on a linked list stack. It will then output the contents of the stack
 * 		to the specified output.
 * ----------------------------------------------------------------------------
 * INPUT:
 * 		inFileName: The name of the input file
 * 		iFileName : The name of the output file
 *
 * 	OUTPUT:
 * 		None
 ******************************************************************************/
int main()
{
	PrintHeaderOstream(cout, "DVD Movie List Intro to OOP", 5, 'A');

	MovieList movie;	//CALC & CALC - MovieList class object
	string inFileName;	//IN   & CALC - Name of the input file
	string oFileName;	//IN   & CALC - Name of the output file

	cout << "What input file would you like to use?: ";
	getline(cin, inFileName);

	cout << "What output file would you like to use?: ";
	getline(cin, oFileName);

	cout << endl;

	movie.CreateList(inFileName);
	movie.OutputList(oFileName);

	return 0;
}

