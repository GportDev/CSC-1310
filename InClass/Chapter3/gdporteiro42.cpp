/*
	In class pratice 1, chapter 3
	Gabriel Porteiro
	1/26/2024
*/

#include <iostream>

using namespace std;

int calculateSum(int [], int);

int main() {
	const int SIZE = 10;
	int array[SIZE] = {10, 9, 8, 7, 6 , 5, 4, 3, 2, 1};

	cout << "The sum of the elements is: " << calculateSum(array, SIZE) << endl; 

	return 0;
}

int calculateSum(int array[], int size) {

	// Base case
	if (size == 0) {
		return 0;
	} else {
		return array[0] + calculateSum(array + 1, size - 1);
	}
}