Sorting Algorithm Comparison

Program Name: Sorting Algorithm Comparison
Language: C
Author: Anwesh Humagain
Date: 14-Feb-2026
Course: COMP202

---

(a) data structures

the program uses a plain integer array to store the elements being sorted. the size is taken from the user at runtime so the array is declared as a variable length array.

two global long long variables are used to track performance across all sorting functions.

comparisons — incremented every time two elements are compared during sorting.
swaps — incremented every time two elements are exchanged. not counted for merge sort since it copies elements into temporary arrays rather than swapping in place.

long long is used instead of int because for large inputs the number of comparisons and swaps can grow very quickly and overflow a regular int.

---

(b) functions

1. print(int arr[], int n)
just goes through the array and prints every element. used before and after sorting to show what changed.

2. bubble_sort(int arr[], int n)
repeatedly compares adjacent elements and swaps them if they are in the wrong order. the largest unsorted element bubbles to the end each pass. counts every comparison and every swap.

3. selection_sort(int arr[], int n)
finds the smallest element in the unsorted portion and moves it to the front. does this for each position from left to right. counts comparisons and only counts a swap when the minimum is actually in a different position.

4. insertion_sort(int arr[], int n)
takes each element and slides it back into the correct position among the already sorted elements to its left. counts each comparison and each shift as a swap.

5. merge(int arr[], int left, int mid, int right)
helper for merge sort. takes two sorted halves and merges them back into the original array in sorted order using temporary arrays. counts comparisons during the merge step.

6. merge_sort(int arr[], int left, int right)
recursively splits the array in half until each piece has one element, then calls merge to put them back together in order. no swaps are used which is why swaps are not counted for this one.

---

(c) how main() works

main() asks the user how many elements to sort, then fills an array with random numbers between 1 and 1000 using srand and rand. it prints the array before sorting, shows a menu for the user to pick a sorting algorithm, resets the counters to zero, runs the chosen sort, then prints the sorted array and the final comparison and swap counts. merge sort skips the swap count since it does not swap elements directly.

---

(d) sample output

the output varies since the array is randomly generated each run. here is a typical run with 6 elements and bubble sort selected.
```
enter the number of elements: 6

numbers before sorting:
742 91 305 678 14 523

choose sorting algorithm:
1. bubble sort
2. selection sort
3. insertion sort
4. merge sort
enter your choice: 1

numbers after sorting:
14 91 305 523 678 742

performance:
total comparisons: 15
total swaps: 8
```