#pragma once
#include <algorithm> // for std::copy_n

class IntArray
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;

	IntArray(int length);

	~IntArray();
	
	IntArray(const IntArray& a);

	IntArray& operator=(const IntArray& a);

	void erase();
	int& operator[](int index);
	void reallocate(int newLength); // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly. 
	void resize(int newLength); // resize the array. Any existing elements will be kept. This function operates slowly. 
	void insertBefore(int value, int index); // insert new element instead of existing in the array before choosen element 
	void remove(int index); // remove element of array
	void insertAtBeginning(int value); // A couple of additional functions just for convenience
	void insertAtEnd(int value); // insert new element instead of existingat the end of the array 
	int getLength() const;
	
};


