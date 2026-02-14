Linked List Reverse Traversal

Program Name: Linked List Reverse Traversal
Language: C
Author: Anwesh Humagain
Date: 14-Feb-2026
Course: COMP202

---

(a) data structures 

data structure used here is only linked list in a structure that holds the value and a pointer to the next node.
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

data is just the number stored in that node. next points to whoever comes after it in the list, and the very last node has next set to NULL so we know where the list ends.

memory for each node is allocated at runtime using malloc, so the list grows dynamically rather than being a fixed array(fixed size)

---

(b) functions

1. createNode(int data)
This is basically a helper that builds a fresh node. You pass in a number, it allocates memory for a new node, stores the number in it, sets next to NULL, and hands the node back. Every node in the program gets made through this.

2. reverseTraverse(Node* head)
This one uses recursion to print the list backwards. Instead of printing as it goes forward, it first dives all the way to the end of the list, then prints on the way back. So the last node ends up printing first and the first node prints last. The list itself never gets changed, no extra array needed either.

---

(c) structure of main()

main() does three things in order. It first builds the list by creating four nodes and chaining them together one by one to get 1 -> 2 -> 3 -> 4. Then it prints the list forward as a plain hardcoded string, and right after calls reverseTraverse() to print it backwards. Once that is done it goes through the list and frees every node to make sure there are no memory leaks before the program exits.

---

(d) Sample Output

Test Case 1
Input: 1 -> 2 -> 3 -> 4
Output: 4 3 2 1
```
Original list (forward): 1 2 3 4
Reverse traversal: 4 3 2 1
```