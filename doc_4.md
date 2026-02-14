Doubly Linked List

Program Name: Doubly Linked List
Language: C
Author: Anwesh Humagain
Date: 14-Feb-2026
Course: COMP202

---

(a) data structures

the program uses a doubly linked list. unlike a singly linked list where each node only knows what comes next, here each node knows both the node before it and the node after it.
```c
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
```

data holds the actual value stored in the node. next points to whoever comes after it and prev points to whoever came before it. the first node has prev as NULL and the last node has next as NULL since there is nothing on either end.

memory for each node is allocated at runtime using malloc so the list grows as needed rather than taking up a fixed block of memory upfront.

---

(b) functions

1. createNode(int data)
builds a fresh node with the given value and sets both prev and next to NULL. every node in the program gets made through this.

2. insertAfter(Node* prevNode, int data)
slots a new node in right after a given node. it first makes sure the given node actually exists, then creates the new node and rewires the pointers around it so nothing in the chain breaks.

3. deleteNode(Node** headRef, Node* delNode)
pulls a specific node out of the list and frees its memory. it takes care of three situations — when the node being removed is the head, when it has something before it, and when it has something after it. either way the remaining nodes stay properly connected.

4. printList(Node* head)
goes through the list from start to end and prints each value. keeps moving forward through next pointers until it hits NULL.

---

(c) how main() works

main() first builds a three node list with values 1, 2 and 3 and manually links the prev and next pointers between them. then it inserts 10 after node 2 and prints the list to show it worked. after that it deletes node 10 and prints again to confirm the list is back to how it was. each step prints the list so you can see exactly what changed.

---

(d) sample output

test case 1 — insertion
inserting 10 after node 2 changes the list from 1 2 3 to 1 2 10 3.

test case 2 — deletion
deleting node 10 brings the list back to 1 2 3.
```
original list: 1 2 3
after inserting 10 after node 2: 1 2 10 3
after deleting node 10: 1 2 3
```