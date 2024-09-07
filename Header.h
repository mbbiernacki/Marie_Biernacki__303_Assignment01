#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

using namespace std;


//FUNCTION DECLARATIONS

bool isDigits(string str1);
//PRE: pass user input as a string parameter
//POST: returns true if input is all integer values, false if not

void readFile(int*& arr, int& arrSize);
//PRE: pass temporary array and temporary size parameter
//POST: data from file is placed into a 1-D array

void operations(int arr[], int arrSize);
//PRE: data from given file has been loaded into a 1-D array, passing the array and array size as parameters
//POST: displays menu options to the user, calls the appropriate function, loops until user exits the program

bool doesExist(int arr1[], int arrSize);
//PRE: data from given file has been loaded into a 1-D array, passing the array and array size as parameters
//POST: if the number is in the array, returns the index value of the number

void modifyValue(int arr[], int arrSize);
//PRE: data from given file has been loaded into a 1-D array, passing the array and array size as parameters
//POST: changes the value at idx to newNum, returns the newNum and the old value to the user

void addInteger(int*& arr, int& arrSize);
//PRE: data from given file has been loaded into a 1-D array, passing the array and array size as parameters
//POST: adds newNum to the end of the array

void removeIdx(int*& arr, int& arrSize);
//PRE: data from given file has been loaded into a 1-D array, passing the array and array size as parameters
//POST: removes the value fro the specified index and decreases the array size

