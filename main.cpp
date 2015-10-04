/*********************************************************************************************
*Author:					Austin Koos
*Date Created:				10/1/2015
*Last Modification Date:	10/3/2015
*Lab Number:				CST 211 Assignment 1
*Filename:					main.cpp
*
*Overview:
*	Tests the functionality of the templated Array class.  Makes use of all the member functions 
*	and constructors.
*
*Input:
*
*
*Output:
*	Start index, array length, array data, and exceptions displayed to console window
*
***********************************************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Array.h"
#include "Exception.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Char array created with default ctor
	Array<char> arrChar;

	//Array of integers of length 0 starting at index 0
	Array<int> arrInt(0, 0);

	//Array of doubles of length 1 starting at index 1
	Array<double> arrDoub(1, 1);

	//getStartIndex and getLength functions
	cout << "Start Index: " << arrInt.getStartIndex() << endl;
	cout << "Length: " << arrInt.getLength() << endl;

	//setStartIndex and setLength functions
	arrInt.setStartIndex(-1);
	arrInt.setLength(2);

	//Copy ctor and operator = function
	Array<int> arrInt2(arrInt);

	try
	{
		//[] operator function and exception handling
		cout << arrInt[-2] << endl;
	}
	catch (Exception &except)
	{
		cout << except;
	}

	try
	{
		//[] operator function and exception handling
		cout << arrDoub[2] << endl;
	}
	catch (Exception &except)
	{
		cout << except;
	}

	try
	{
		//[] operator function and exception handling
		cout << arrInt[-1] << endl;
		cout << arrInt2[-1] << endl;
		cout << arrDoub[1] << endl;
	}
	catch (Exception &except)
	{
		cout << except;
	}

	return 0;
}