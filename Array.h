#ifndef ARRAY_H
#define ARRAY_H
#include "Exception.h"

/************************************************************************
* Class: Array
*
* Constructors:
*	Array()
*		m_array initialized to nullptr and m_elements initialized to 0
*	
*	Array(int length, int startIndex = 0)
*		m_array initialized to nullptr, m_length to length, and m_startIndex
*		to startIndex
*
*	Array(const Array &copy)
*		Copy constructor
*
* Destructor:
*	~Array()
*		Deletes m_array
*
* Mutators:
*	Array& operator= (const Array& rhs)
*		If the invoking object and rhs are not the same, creates a new
*		Array that is a copy of rhs
*
* Methods:
*	T& operator[](int index)
*		Returns the element at index
*
*	int GetStartIndex() 
*		Returns m_startIndex
*
*	void SetStartIndex(int startIndex)
*		Sets m_startIndex to startIndex
*
*	int GetLength()
*		Returns m_length
*
*	void SetLength(int length)
*		Sets m_length to length
*
*************************************************************************/

template <typename T>
class Array
{
public:
	//Default ctor
	Array();

	//Two arg ctor
	Array(int length, int startIndex = 0);

	//Copy ctor
	Array(const Array &copy);

	//Destructor
	~Array();

	//Operator= function 
	Array& operator=(const Array &rhs);

	//[] operator function
	T& operator[](int index);

	//Returns m_startIndex
	int getStartIndex();

	//Sets m_startIndex to user input
	void setStartIndex(int startIndex);

	//Returns m_length
	int getLength();

	//Sets m_length to length
	void setLength(int length);

private:
	T* m_array;						//Array of type T
	int m_length;					//Length of the array
	int m_startIndex;				//Starting index of the array
};

#include "Array.tpp"

#endif