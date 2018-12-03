#include<iostream>
#include "ArrayList.cpp"

using namespace std;

void main() {
	cout << "Creating a list with a max size 8" << endl;
	ArrayList l1(8);

	l1.show();

	cout << "Adding list elements: 2, 6, 8, 7, 1" << endl;
	l1.add(2);
	l1.add(6);
	l1.add(8);
	l1.add(7);
	l1.add(1);
	
	cout << "Moving current (pointer) to first element" << endl;
	l1.start();
	cout << "Now moving current position forward by 2 elements" << endl;
	l1.next();
	l1.next();
	l1.show();

	cout << "Adding 9 to current position" << endl;
	l1.add(9);
	l1.show();

	cout << "Moving current position forward by 1 element" << endl;
	l1.next();
	l1.show();

	cout << "Removing element at current position" << endl;
	l1.remove();
	l1.show();


	system("pause");
}