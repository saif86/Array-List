/*
* The ArrayList class implements the list
* through a dynamic array
*
* @author  Saif Ullah Ijaz
* @version 1.0
* @since   26/09/2016
*/
#ifndef ARRAY_LIST 
#define ARRAY_LIST

#include<iostream>

using namespace std;

class ArrayList
{
	int maxSize;		// Maximum allowable size of the list
	int size;			// current size of the list
	int current;		// current marker (pointer)
	int *A;				// dynamic array to create list

public:
	/* default constructor*/
	ArrayList() :maxSize(100), size(0), current(0)
	{
		A = new int[maxSize];
		for (int i = 0; i < maxSize; i++)
			A[i] = 0;
		cout << "Empty list created." << endl;
	}
	/* Overloaded constructor*/
	ArrayList(int aSize) :maxSize(aSize), size(0), current(0)
	{
		A = new int[aSize];
		for (int i = 0; i < aSize; i++)
			A[i] = 0;
		cout << "Empty list created." << endl;
	}
	/* Copy constructor*/
	ArrayList(const ArrayList &obj) :maxSize(obj.maxSize), size(obj.size), current(obj.current)
	{
		A = new int[obj.maxSize];
		for (int i = 0; i < obj.maxSize; i++)
			A[i] = obj.A[i];
	}

	/* Copy Assignment*/
	void operator = (const ArrayList & rhs) {
		maxSize = rhs.maxSize;
		size = rhs.size;
		current = rhs.current;
		delete[] A;
		if (rhs.maxSize != 0) {
			A = new int[rhs.maxSize];
			for (int i = 0; i < rhs.maxSize; i++)
				A[i] = rhs.A[i];
		}
		else
			A = NULL;
	}

	void copy(const ArrayList &obj)
	{
		maxSize = obj.maxSize;
		size = obj.size;
		current = obj.current;
		delete[] A;
		if (obj.maxSize != 0) {
			A = new int[obj.maxSize];
			for (int i = 0; i < obj.maxSize; i++)
				A[i] = obj.A[i];
		}
		else
			A = NULL;
	}

	/* destructor*/
	~ArrayList()
	{
		if (A)		// if list is not empty then delete it
			delete[] A;
	}

	bool add(int newData)
	{
		if (size < maxSize)
		{
			for (int i = size; i > current; i--)
				A[i] = A[i - 1];
			A[current++] = newData;
			size++;
			return true;
		}
		cout << "Can't add more items. List is full." << endl;
		return false;
	}
	void show()
	{
		cout << "Size: " << length() << endl;
		if (size != 0)
		{
			cout << "(";
			for (int i = 0; i < size; i++)
			{
				cout << A[i];
				if (i < size - 1)
					cout << ", ";
			}
			cout << ")" << endl;

		}
		else
		{
			cout << "Empty list." << endl;
		}
		cout << "Current: " << current << endl << endl;
	}
	bool start()
	{
		if (size != 0)
		{
			current = 1;
			return true;
		}
		return false;

	}
	void tail()
	{
		current = size;
	}
	bool next()
	{
		if (current < size)
		{
			current++;
			return true;
		}
		cout << "Current marker can't be moved forward. Already at the maximum." << endl;
		return false;

	}
	bool back()
	{
		if (current > 0)
		{
			current--;
			return true;
		}
		cout << "Current marker can't be moved backward. Already at the beginning." << endl;
		return false;
	}
	int remove()
	{
		if (size != 0)
		{
			for (int i = current - 1; i < size - 1; i++)
				A[i] = A[i + 1];
			A[size - 1] = 0;
			size--;
			if (current > size)
				back();
			return true;
		}
		cout << "Can't remove item from empty list." << endl;
		return false;

	}
	bool find(int X) {
		int j;
		for (j = 0; j < size; j++)
			if (A[j] == X)
				break;
		if (j < size) {	// found X	    
			current = j + 1;        // current points to where X found
			return true;   // 1 for true	
		}
		return false;  // 0 (false) indicates not found
	}
	int get()
	{
		if (size != 0 && current != 0)
			return A[current - 1];
		else
			return 0;
	}
	bool update(int x)
	{
		if (current != 0)
		{
			A[current - 1] = x;
			return true;
		}
		else
			return false;
	}
	int length()
	{
		return size;
	}
	void clear()
	{
		if (size != 0)
		{
			size = current = 0;
			for (int i = 0; i < maxSize; i++)
				A[i] = 0;
		}
	}
};

#endif