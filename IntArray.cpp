#include "IntArray.h"
#include "BadLength.h"
#include "BadRange.h"
#include <iostream>

using namespace std;

IntArray::~IntArray()
{
	delete[] m_data;
}

IntArray::IntArray(const IntArray& a) : IntArray(a.getLength()) // use normal constructor to set size of array appropriately
{
	std::copy_n(a.m_data, m_length, m_data); // copy the elements
}

IntArray::IntArray(int length) : m_length{ length }
{
	/*Previous version was:
	assert(length >= 0);
	if (length > 0)*/

	// Changed to C++ exceptoion 
	if (length < 0)
	{
		throw BadLength(length);
	}
			m_data = new int[length] {};
}

IntArray& IntArray::operator=(const IntArray& a)
{
	// Self-assignment check
	if (&a == this)
		return *this;

	// Set the size of the new array appropriately
	reallocate(a.getLength());
	std::copy_n(a.m_data, m_length, m_data); // copy the elements

	return *this;
}

void IntArray::erase()
{
	delete[] m_data;

	m_data = nullptr; // ??????????????????????
	m_length = 0;
}

int& IntArray::operator[](int index)
{
	/*Previous version was:
	// assert(index >= 0 && index < m_length);*/
	
	// Changed to C++ exceptoion 
		if (index < 0 || index >= m_length)
		{
			throw BadRange(index);
		}
		return m_data[index];
}

void IntArray::reallocate(int newLength)
{
	// First we delete any existing elements
	erase();

	// If our array is going to be empty now, return here
	if (newLength <= 0)
		return;

	// Then we have to allocate new elements
	m_data = new int[newLength];
	m_length = newLength;
}

void IntArray::resize(int newLength)
{
	// if the array is alrady the right length we're done
	if (newLength == m_length)
		return;

	// if we are resizing to an empty array, do that and return
	if (newLength <= 0)
	{
		erase();
		return;

	}

	// Now we can assume newLength is at least 1 element.  This algorithm
	// works as follows: First we are going to allocate a new array.  Then we
	// are going to copy elements from the existing array to the new array.
	// Once that is done, we can destroy the old array, and make m_data
	// point to the new array.

	// First we have to allocate a new array
	int* data
	{
		new int[newLength]
	};

	// Then we have to figure out how many elements to copy from the existing
   // array to the new array.  We want to copy as many elements as there are
   // in the smaller of the two arrays.

	if (m_length > 0)
	{
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength }; ///?????????



		std::copy_n(m_data, elementsToCopy, data); // copy the elements
	}

	// Now we can delete the old array because we don't need it any more
	delete[] m_data;


	// And use the new array instead!  Note that this simply makes m_data point
	// to the same address as the new array we dynamically allocated.  Because
	// data was dynamically allocated, it won't be destroyed when it goes out of scope.
	m_data = data;
	m_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{

	// Sanity check our index value
	/*Previous version was:
	assert(index >= 0 && index <= m_length);*/
	// Changed to C++ exceptoion 
	if (index < 0 || index > m_length)
	{
		throw BadRange(index);
	}

	// First crate a new array one element larger than the old array
	int* data{ new int[m_length + 1] };

	// Copy all of the elements up to the index
	std::copy_n(m_data, index, data);

	// Insert our new element into the new array
	data[index] = value;

	// Copy all of the values after the inserted element
	std::copy_n(m_data + index, m_length - index, data + index + 1);

	// Finaly, delete the old array, and use the new array instead
	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntArray::remove(int index)
{
	// Sanity check our index value
	/*Previous version was:
	assert(index >= 0 && index < m_length)*/
	// Changed to C++ exceptoion 
	if (index < 0 || index > m_length)
	{
		throw BadRange(index);
	}

	// If this is the last remaining element in the array, set the array to empty and bail out
	if (m_length == 1)
	{
		erase();
		return;
	}

	// First create a new array one element smaller than the old array
	int* data{ new int[m_length - 1] };

	// Copy all of the elements up to the index
	std::copy_n(m_data, index, data);

	// Copy all of the values after the removed element
	std::copy_n(m_data + index + 1, m_length - index - 1, data + index);

	// Finally, delete the old array, and use the new array instead
	delete[] m_data;
	m_data = data;
	--m_length;
}

// A couple of additional functions just for convenience
void IntArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}
void IntArray::insertAtEnd(int value)
{
	insertBefore(value, m_length);
}

int IntArray::getLength() const // Print out all the numbers
{
	return m_length;
}