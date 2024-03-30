/*******************************************************************************
 * AUTHOR        : Cameron Abo
 * STUDENT ID    : 387130
 * Assignment #5 : DVD Movie List Intro to OOP
 * CLASS         : CS1B
 * SECTION       : MW: 7:30p
 * DUE DATE      : 5/19/23
 ******************************************************************************/

#ifndef HEADERA5_H_
#define HEADERA5_H_
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*******************************************************************************
 * FUNCTION PrintHeaderOstream
 * _____________________________________________________________________________
 * This function receives an cout or file output variable assignment name, type,
 * 		and number and outputs a student header with the student's information.
 *
 * 		==> returns nothing
 *
 ******************************************************************************/
void PrintHeaderOstream(ostream &output,  //IN  - outputs using cout or ofstream
						string asName,	  //IN  - Programmer name
						int    asNum,  	  //IN  - Assignment Number
						char   asType);	  //IN  - Assignment type
#endif /* HEADERA5_H_ */
