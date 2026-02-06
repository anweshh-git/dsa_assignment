#include <stdio.h>
#include <stdlib.h>

//node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// new node creation
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//reverse traversal using recursion
void reverseTraverse(Node* head) {
    if (head == NULL) return;
    reverseTraverse(head->next);  
    printf("%d ", head->data);    
}

