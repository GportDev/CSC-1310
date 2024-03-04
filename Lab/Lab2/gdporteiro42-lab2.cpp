/*
	Title:  Lab2.cpp
	Author: Gabriel Porteiro
	Date:  Feb 4
	Purpose:  Demonstrate my knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string, int, int);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << "\n" << sumOfNumbers(num) << endl;
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if(isMember(myArray, num, ARRAY_SIZE) == true) {
					cout << "\n\nThe number " << num << " is part of the array." << endl;
				} else {
					cout << "\n\nThe number " << num << " is not part of the array." << endl;
				}
				
				break;
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);

				//call string reverser function here
				stringReverser(userString, userString.length());

				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;

				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user"s string is a palindrome or not here.
				//when you print out the user"s string, print out the uppercase version that doesn"t have the spaces removed.
				if(isPalindrome(userStrModified, 0, userStrModified.length() - 1)) {
					cout << "The string " <<  userStrModified << " is a palindrome" << endl;
				} else {
					cout << "The string " <<  userStrModified << " is not a palindrome" << endl;
				}

				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << multiply(num1, num2) << endl;
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


// Function that sum all numbers from 1 to a target, recursively
int sumOfNumbers(int target) {
	if(target  == 1) {
		return 1;
	} else {
		return target + sumOfNumbers(target - 1);
	}
}

// Function to verify if a target number is member of a given array
bool isMember(int* array, int target, int size) {
	// Base case 1 when the size is 0 and value is not found
	if(size == 0) {
		return false;
	}

	// Base case 2 when the last element matches the target value -> Optimization to recursive algorithm
	if(array[size - 1] == target) {
		return true;
	}

	// Recursive case to search in the rest of the array
	return isMember(array, target, size - 1);
}	

// Function to reverse any given string
void stringReverser(string target, int length) {
	// Base case if the string is null
	if (length == 0) {
		return;
	}

	// Recursive case to print the reversed string
	cout << target[length - 1];
	stringReverser(target, length - 1);
}

// Function to verify if a given string is a palindrome or not
bool isPalindrome(string targetString, int start, int final) {
	// Base case for single characters or empty strings
	if(start >= final) {
		return true;
	}

	// Base case to check first and last character
	if(targetString[start] != targetString[final]) {
		return false;
	}

	// Recursive case that check all the other characters inside the string
	return isPalindrome(targetString, start + 1, final - 1);
}

// Function to multiply a number using the multiple add method
int multiply(int number, int factor) {
	// Base case when the factor is 0
	if (factor == 0) {
		return 0;
	}

	// Convert to positive when the factor is negative
	if (factor < 0) {
		return -multiply(number, -factor);;
	}

	// Recursive case to add number to the product of number and factor -1

	return number + multiply(number, factor - 1);
}