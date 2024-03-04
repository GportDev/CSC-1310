# Sorting Algorithms

Is an algorithm to arrange data in a specific order

## Bubble sort

Iterating between all positions of an array, comparing every two elements, this algorithm gonna compare the current with the next, if current is bigger than the next, they gonna switch positions. When the LAST iterated number have no smaller numbers at right, it will be locked in his position. This number never will be checked again.

|Best case|Average Case|Worst Case|
|----|-----|----|
|O(n)|O(nˆ2)|O(nˆ2)|


<br/>
<br/>

## Selection sort

Comparing all the numbers, bringing the smallest in the array to the front, every time it found the smallest it gonna bring to the front and lock, the new front position will be the next one. The comparison gonna rappen against all numbers each circle.

|Best case|Average Case|Worst Case|
|----|-----|-----|
|O(nˆ2)|O(nˆ2)|O(nˆ2)|


## Insertion sort

Move the number in the position it belongs. The array is slit in two parts, sorted and unsorted. Each iteration gonna compare the current element with the others and put it in the correct position at the sorted sub-array. The other numbers inside this part of the array gonna be placed into the next positions in order to open space to the newly sorted element.

|Best case|Average Case|Worst Case|
|----|-----|-----|
|O(n)|O(nˆ2)|O(nˆ2)|