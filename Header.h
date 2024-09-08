#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void loadArray(ifstream& inFile, int arr[], int size);
int findInteger(int arr[], int arraysize, int findme);
int* addInteger(int arr[], int& arraysize, int addtoend, int& capacity);
int* removeIndex(int arr[], int& arraysize, int indextoremove);
int modifyInteger(int arr[], int index, int newvalue);
