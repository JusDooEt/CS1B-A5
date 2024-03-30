# Movie List
## About 
This project was used as practice for reading big files and storing the data on a linked list stack. The program asks the user for a file to read from and will attempt to locate the file and if found it will read and store the data found in the file. The program will then format the data and store it on a separate output file named by the user.

## Input Format
```
Antwone Fisher
Denzel Washington
Derek Luke
Biography
Drama
2002
7
Antwone Fisher, a young navy man, is forced to see a psychiatrist after a violent outburst against a fellow crewman. During the course of treatment a painful past is revealed and a new hope begins.
```
## Output Format
```
***************************************************************************
Movie #: 1        Title: Antwone Fisher
---------------------------------------------------------------------------
Year: 2002        Rating: 7
---------------------------------------------------------------------------
Leading Actor:    Denzel Washington        Genre 1: Biography
Supporting Actor: Derek Luke               Genre 2: Drama
---------------------------------------------------------------------------
PLOT:
Antwone Fisher, a young navy man, is forced to see a psychiatrist after a 
violent outburst against a fellow crewman. During the course of treatment 
a painful past is revealed and a new hope begins. 
***************************************************************************
```

## Classes
- StackList
  - The base class of this program is the StackList class which includes all of the necessary methods for manipulating a stack linked list like Push(), Pop(), IsEmpty(), Peek(), and Size(). This class uses a struct called DVDNode to create the list. 
- MovieList
  - The child class to StackList is MovieList. The MovieList class inherits all of the attributes defined in the StackList class and adds two public methods to create and output the stack of DVDNodes. It also has private methods to format the data read from the input file like WordWrap and FormatCheck.
  - WordWrap Method
    - This method will check the movie description length and determine where to add new line characters to the formatted string. The method will store each word in a string variable that will add to a line variable. If the next word length would cause the line length to be over the max line length the method will add the current line to the overall description string with a new line character. After adding to the main description string the line string will clear and the next word will be added to the cleared line string. 
  - FormatCheck Method
    - This method formats the given string and setw values to format to. It will check if the string is longer than the setw value and add ellipsis to the cut off string if larger than the setw value.
   
