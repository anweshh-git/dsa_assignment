#include <stdio.h>
#include <stdlib.h>

//structure for a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

//node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//insert a new node after a given node
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

//delete a node from the list
void deleteNode(Node** headRef, Node* delNode) {
    if (*headRef == NULL || delNode == NULL) return;
    
    //if node to be deleted is head node
    if (*headRef == delNode)
        *headRef = delNode->next;
    
    //change next pointer of previous node
    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;
    
    //change prev pointer of next node
    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;
    
    free(delNode);
}

//list forward traversal
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

