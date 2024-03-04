# Recursion

### Recursive algorithm
A recursive algorithm solves a problem by breaking that problem into smaller sub-problems, solving these sub-problems, and combining the solutions.

### Recursive functions
Call itself.

### Base case
Recursive algorithm has a base case, the main thing, the kik-off of the function

### Recursive case
The thing that make the function repeat. When the recursion will occur the algorithm check for something the avoid a infinite recursion loop, it could be an integer limiting iterations, a state, or anything else that in fact say to the algorithm that is time to stop.

## Using recursion to make math questions

### Greatest common divisor
Euclid's algorithm


# Search algorithm

## Linear search
Iterates all the entries inside an array and compare with the search case. The worst case is when the case do not exist in the array, because the algorithm will look in all entries and them will find that is not there.

_Average number of comparisons in LSA_ -> n/2 comparisons
_Maximum (Worst case scenario)_ -> n comparisons

## Binary search

First of all the numbers are sorted. Once is in order, the algorithm will go to the middle position and compare this with the searched element. If the element is bigger than the looked for, the algorithm will eliminate the lower half of the array. The opposite is true, if the middle element is lower than the looked for, the algorithm will eliminate the bigger part.

In each iteration that the searched element is not found, results in the elimination of half of the array

_Average number of comparisons in LSA_ -> ln(n)

## Efficiency and Growth rate

More elements = more iterations

# Big-O notation

A mathematical way to describe the efficiency class of an algorithm to some function of N. This is the absolute worst case this algorithm could ever get

|Algorithm| Big-O |   Graph|
|---------|-------|--------|
|Linear   | O(n)  | Linear |


Note: Big-Omega calculate the best case and Big-Theta calculates the average efficiency.

### Times

- Linear ->
- Quadratic ->
- Logartimic ->
- Exponential -> O(cˆN)

## Quick sort

Divide-and conquer strategy. It gonna find the pivot, a element that will divide the array by two. The ones in the left of the pivot gonna be less than it, the ones in the right gonna be bigger than the pivot. So the algorithm gonna compare each element with the pivot and swap it until have all the smaller in the left and all the bigger at right.

Then, the process will recursively occur again. Choose a pivot, sort the others.

```cpp
#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes the last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low  --> Starting index,
 high  --> Ending index */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code to test above
int main() {
    int arr[] = {29, 10, 14, 37, 13, 25, 22, 32, 19, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
```

## Merge sort

1. Split the array into half until found the smaller part (pair of elements). 
2. Then, sort each pair ascending, merging then into pairs.
3. Sort the elements between two pairs merging them into a group of 4.
4. Then do the same with the groups... keep going until have the whole array sorted.

## Radix sort

