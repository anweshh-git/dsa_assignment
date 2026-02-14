min and max heap

Program Name: Min and Max Heap
Language: C
Author: Anwesh Humagain
Date: 14-Feb-2026
Course: COMP202

---

(a) data structures

the program uses a plain integer array to represent the heap. there is no separate tree structure — the heap is stored directly in the array and the parent-child relationships are calculated using index math.

for any node at index i:
- left child is at 2*i + 1
- right child is at 2*i + 2

the same array gets rearranged in place depending on whether you are building a max heap or a min heap.

---

(b) functions

1. swap(int *a, int *b)
swaps two integers using pointers. used by both maxheap and minheap whenever a parent and child need to be exchanged.

2. maxheap(int arr[], int n, int i)
looks at a node at index i and checks if either of its children is larger. if one is, it swaps the parent with the largest child and then calls itself recursively on the swapped position to keep fixing downward until the heap property is restored.

3. buildmaxheap(int arr[], int n)
builds the full max heap by calling maxheap on every non-leaf node starting from the bottom and working up to the root. after this the largest value will be at index 0.

4. minheap(int arr[], int n, int i)
same idea as maxheap but looks for the smallest child instead. swaps downward until the smallest value bubbles up to the top.

5. buildminheap(int arr[], int n)
builds the full min heap the same way as buildmaxheap but using minheap. after this the smallest value will be at index 0.

---

(c) how main() works

main() starts with one array of seven numbers and prints it as is. it then calls buildmaxheap on it and prints the result. after that it creates a second copy of the same array and calls buildminheap on it and prints that result too. two separate arrays are used so the original order can be tested for both heaps independently.

---

(d) sample output
```
before building heap: 12 4 6 1 8 10 18
max heap: 18 8 12 1 4 10 6
min heap: 1 4 6 12 8 10 18
```