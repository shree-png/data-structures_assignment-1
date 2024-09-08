#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void loadArray(ifstream& inFile, int arr[], int arraysize) {
	for (int i = 0; i < arraysize; i++) {
		inFile >> arr[i];
	}
}

//function no.1 (per the instructions)
int findInteger(int arr[], int arraysize, int findme) {
	for (int i = 0; i < arraysize; i++) {
		if (arr[i] == findme) {
			return i;
		}
	}
	return -1;
}

//function no.2
int modifyInteger(int arr[], int index, int newvalue) {
	//Error checking done in main()
	int oldvalue = arr[index];
	arr[index] = newvalue;
	return oldvalue;
}

//function no.3
int* addInteger(int arr[], int& arraysize, int addtoend, int& capacity) {
	int* newarray;
	//^^I had to dynamically allocate newarray, in order to assign it using a function parameter (capacity)
	if (arraysize == capacity) {
		capacity *= 2;
		cout << endl;
		cout << "Doubled the array size!" << endl;
		newarray = new int[capacity];

		for (int i = 0; i < arraysize; i++) {
			newarray[i] = arr[i]; //copy over existing values to newarray
		}
		delete[] arr; //avoid memory leaks
	}
	else {
		newarray = arr;
	}

	//throwing exception:
	if (arraysize >= capacity) {
		cout << endl;
		throw runtime_error("Error: Array size exceeds capacity.");
		cout << endl;
	}
	else {
		newarray[arraysize] = addtoend; //adding the new integer to the end
		arraysize += 1;
	}
	return newarray;
}

//function no.4
int* removeIndex(int arr[], int& arraysize, int indextoremove) {
	int* newarray = new int[arraysize - 1]; //realized last minute that this should be resized to capacity, not arraysize - 1
	for (int i = 0,j = 0; i < arraysize; i++) {
		if (i != indextoremove) {
			newarray[j] = arr[i]; //without j, a weird filler number fills the skipped index
			j++;
		}
	}
	arraysize -= 1;
	return newarray;
}
