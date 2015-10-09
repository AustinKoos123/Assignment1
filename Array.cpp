/**************************************************************
*	  Purpose:		Default ctor
*
*     Entry:		Object created using no parameters
*
*     Exit:			m_array initialized to nullptr,
*					m_length to 0, and m_startIndex to 0
*
****************************************************************/
template <typename T>
Array<T>::Array() : m_array(nullptr), m_length(0), m_startIndex(0)
{

}

/**************************************************************
*	  Purpose:		Two arg ctor
*
*     Entry:		Object created using two parameters
*
*     Exit:			m_array is allocated memory, m_length is
*					initialized to length, and m_startIndex
*					is initialized to startIndex
*
****************************************************************/
template <typename T>
Array<T>::Array(int length, int startIndex) : m_array(nullptr), m_length(length), m_startIndex(startIndex)
{
	m_array = new T[length];
}

/**************************************************************
*	  Purpose:		Copy ctor
*
*     Entry:		Object passed or returned by value or
*					object instantiated with another object
*
*     Exit:			this will be a copy of copy
*
****************************************************************/
template <typename T>
Array<T>::Array(const Array &copy) : m_array(nullptr)
{
	*this = copy;
}

/**************************************************************
*	  Purpose:		Destructor
*
*     Entry:		Object to be destroyed
*
*     Exit:			m_array is deleted
*
****************************************************************/
template <typename T>
Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;
	m_length = 0;
	m_startIndex = 0;
}

/**************************************************************
*	  Purpose:		Operator= function
*
*     Entry:		Object assigned to another object
*
*     Exit:			this will be a copy of rhs
*
****************************************************************/
template <typename T>
Array<T>& Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;
		m_array = nullptr;

		if (rhs.m_array != nullptr)
		{
			m_length = rhs.m_length;
			m_startIndex = rhs.m_startIndex;
			m_array = new T[m_length];

			for (int i = 0; i < m_length; i++)
			{
				m_array[i] = rhs.m_array[i];
			}
		}
	}
	return *this;
}

/**************************************************************
*	  Purpose:		Operator[] function
*
*     Entry:		Object indexed using [] operator
*
*     Exit:			Returns the element in m_array at index
*
*	  Exception:	Throws an exception if the index is lower
*					than m_startIndex or higher than the last
*					element in m_array
*
****************************************************************/
template <typename T>
T& Array<T>::operator[](int index)
{
	if (m_array == nullptr)
	{
		throw Exception("m_array is a nullptr");
	}
	else if (index < m_startIndex)
	{
		throw Exception("Index too low");
	}
	else if (index >= (m_startIndex + m_length))
	{
		throw Exception("Index too high");
	}
	else
	{
		int startDiff = abs(abs(index) - abs(m_startIndex));

		return m_array[startDiff];
	}
}

/**************************************************************
*	  Purpose:		Returns m_startIndex
*
*     Entry:		Function called from invoking object
*
*     Exit:			Returns m_startIndex
*
****************************************************************/
template <typename T>
int Array<T>::getStartIndex()
{
	return m_startIndex;
}

/**************************************************************
*	  Purpose:		Sets m_startIndex to startIndex
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_startIndex set to startIndex
*
****************************************************************/
template <typename T>
void Array<T>::setStartIndex(int startIndex)
{
	m_startIndex = startIndex;
}

/**************************************************************
*	  Purpose:		Returns m_length
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_length returned
*
****************************************************************/
template <typename T>
int Array<T>::getLength()
{
	return m_length;
}

/**************************************************************
*	  Purpose:		Sets m_length to length.  If length is
*					less than 0, user is prompted to re-enter
*					until a valid number is entered
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_length set to length
*
****************************************************************/
template <typename T>
void Array<T>::setLength(int length)
{
	if (length <= 0)
	{
		delete[] m_array;
		m_array = nullptr;
		m_length = 0;
	}
	else
	{
		T *tempArray = new T[m_length];
		for (int i = 0; i < length; i++)
		{
			tempArray[i] = m_array[i];
		}

		delete[] m_array;
		m_array = nullptr;

		m_array = new T[length];
		for (int i = 0; i < length; i++)
		{
			m_array[i] = tempArray[i];
		}

		delete[] tempArray;
	}
}