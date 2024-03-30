/*******************************************************************************
 * AUTHOR        : Cameron Abo
 * STUDENT ID    : 387130
 * Assignment #5 : DVD Movie List Intro to OOP
 * CLASS         : CS1B
 * SECTION       : MW: 7:30p
 * DUE DATE      : 5/19/23
 ******************************************************************************/
#include "MovieList.h"
 /*********************************
 *** CONSTRUCTOR / DESTRUCTOR ****
 *********************************/
/*******************************************************************************
* METHOD MovieList: Class MovieList
* ______________________________________________________________________________
*
* This method initializes a new object of class MovieList
*
* RETURNS:
*	--> nothing
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		maxLength : Must be previously declared in MovieList
*
*	POST-CONDTIONS:
*		a new object of class MovieList will be created.
*		maxLength: will be set to 0
*******************************************************************************/
MovieList::MovieList()
{
	maxLength = 75;
}

/*******************************************************************************
* METHOD ~MovieList: Class MovieList
* ______________________________________________________________________________
*
* This method uninitializes a MovieList object.
*
* RETURNS:
*	--> nothing
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		An object of MovieList must be declared.
*
*	POST-CONDTIONS:
*		This method uninitializes a MovieList object.
*******************************************************************************/
MovieList::~MovieList(){}

/******************
 **** MUTATORS ****
 ******************/

/*******************************************************************************
* METHOD CreateList: Class MovieList
* ______________________________________________________________________________
*
* This method initializes a stack of DVDNodes from an input files given in the
* 	parameters and calls on the Push method from inherited StackList class.
*
* RETURNS:
*	--> nothing
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		inputFileName		: Must be previously defined and represent and
*								present file
*		Push(DVDNode newDVD): Must be previously defined.
*
*	POST-CONDTIONS:
*		This method creates a new stack of DVDNodes read in from an input file
*******************************************************************************/
void MovieList::CreateList(string inputFileName)
{
	ifstream fin;			//CALC - ifstream variable
	DVDNode  *newDVD;  		//CALC - pointer to new node
	newDVD = new DVDNode;
	fin.open(inputFileName);

	while(fin)
	{

		getline(fin, newDVD->title);
		getline(fin, newDVD->leadingActor);
		getline(fin, newDVD->supportingActor);
		getline(fin, newDVD->genre);
		getline(fin, newDVD->alternateGenre);
		fin >> newDVD->year;
		fin >> newDVD->rating;
		fin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(fin, newDVD->synopsis);
		fin.ignore(numeric_limits<streamsize>::max(), '\n');
//		cout << "Title: " << newDVD->title << endl;
		Push(*newDVD);
	}
	delete newDVD;
	newDVD = NULL;
	fin.close();
}

/******************
 **** ACCESSORS ***
 ******************/

/*******************************************************************************
* METHOD OutputList: Class MovieList
* ______________________________________________________________________________
*
* This method outputs all the contents of the stack in a formatted table to a
* 	file.
*
* RETURNS:
*	--> nothing
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		outputFileName	  : Must be previously defined
*		OutputClassHeader : Must be previously defined.
*
*	POST-CONDTIONS:
*		Output the entire stack to a file given in the parameters
*******************************************************************************/
void MovieList::OutputList (string outputFileName) const
{
	DVDNode *dvdPtr;	//CALC - pointer to new node
	ofstream fout;		//CALC - File output variable
	int count;			//OUT  - DVD output counter

	fout.open(outputFileName);
	dvdPtr = head;
	count = 1;

	OutputClassHeader(fout);

	cout << "\nWriting output file " << outputFileName << endl;

	while(dvdPtr != NULL)
	{
		fout << setfill('*') << setw(maxLength) << '*' << setfill(' ') << endl;
		fout << "Movie #:"  << setw(2) << count;
		fout << setw(15) << "Title: "    << FormatCheck(dvdPtr -> title, 49)
			 << endl;
		fout << setfill('-') << setw(maxLength) << '-' << endl;
		fout << setfill(' ') << "Year: "   		<< dvdPtr -> year
			 << setw(16)     << "Rating: " 		<< dvdPtr -> rating
			 << endl;
		fout << setfill('-') << setw(maxLength)   << '-' 	<< endl;
		fout << setfill(' ') << left;
		fout << setw(18) 	 << "Leading Actor: "
			 << setw(25) 	 << dvdPtr -> leadingActor;
		fout << "Genre 1: "  << dvdPtr -> genre   			<< endl;
		fout << setw(18) 	 << "Supporting Actor: "
			 << setw(25) 	 << dvdPtr -> supportingActor;
		fout << "Genre 2: "  << dvdPtr -> alternateGenre    << endl;
		fout << setfill('-') << setw(maxLength)   << '-'    << endl;
		fout << setfill(' ');
		fout << "PLOT:\n";
		fout << WordWrap(dvdPtr -> synopsis);
		fout << setfill('*') << setw(maxLength)	  << '*' << endl << endl
			 << endl << right << setfill(' ');

//		cout << "Outputing: " << dvdPtr -> title << endl;
		count++;
		dvdPtr = dvdPtr -> next;
	}
	fout.close();
}

/*******************************************************************************
* METHOD WordWrap: Class MovieList
* ______________________________________________________________________________
*
* This method formats the given movie synopsis with a word wrap
*
* RETURNS:
*	--> The formatted movie synopsis
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		plot	  : Must be previously defined
*
*	POST-CONDTIONS:
*		none
*******************************************************************************/
string MovieList::WordWrap(string plot) const
{
	ostringstream output;	//OUT  - Stores the formatted word wrap
	string wordStr;			//CALC - Word string for word wrap
	string lineStr;			//CALC - Line string for word wrap

	output.str("");
	wordStr.clear();
	lineStr.clear();

	for(int index = 0; index <= plot.length(); index++)
	{
		if(plot[index] != ' ')
		{
			wordStr += plot[index];
		}
		else
		{
			if(lineStr.length() + wordStr.length() > maxLength - 1)
			{
				output << lineStr << endl;
				lineStr.clear();
			}
			lineStr += wordStr + ' ';
			wordStr.clear();
		}
	}
	if(lineStr.size() != 0)
	{
		output << lineStr << wordStr << endl;
		lineStr.clear();
	}
	return output.str();
}

/*******************************************************************************
* METHOD FormatCheck: Class MovieList
* ______________________________________________________________________________
*
* This method formats the given string and setw values to format to. It will
* 	check if the string is longer than the setw value and add ellipsis to the
* 	cut off string if larger than the setw value.
*
* RETURNS:
*	--> The formatted string
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		checkString: Must be previously defined
*		setwNum	   : Must be an integer.
*
*	POST-CONDTIONS:
*		none
*******************************************************************************/
string MovieList::FormatCheck(string checkString, int setwNum) const
{
	if(checkString.length() > setwNum)
	{
		checkString = checkString.substr(0, setwNum - 4) + "... ";
	}

	return checkString;
}

/*******************************************************************************
* METHOD OutputClassHeader: Class MovieList
* ______________________________________________________________________________
*
* This method receives an cout or file output variable assignment name, type,
 * 		and number and outputs a student header with the student's information.
*
* RETURNS:
*	--> nothing
*______________________________________________________________________________
*	PRE-CONDITIONS:
*		fout << Must be previously declared
*
*	POST-CONDTIONS:
*		Outputs the class heading to file
*******************************************************************************/
void MovieList::OutputClassHeader(ostream &fout) const
{
	fout << left;
	fout << "***************************************************************\n";
	fout << "*   PROGRAMMED BY : Cameron Abo\n";
	fout << "*   " << setw(14) << "STUDENT ID" << ": 387130\n";
	fout << "*   " << setw(14) << "CLASS"      << ": CS1B - MW - 7:30p\n";
	fout << "*   " ;
	fout << "ASSIGNMENT #" << setw(2);
	fout << 5 << ": " << "DVD Movie List Intro to OOP" << endl;
	fout << "***************************************************************\n";
	fout << endl << right;
}
