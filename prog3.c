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

int main() {
    //create list
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    
    printf("Original list (forward): 1 2 3 4\n");
    printf("Reverse traversal: ");
    reverseTraverse(head);  
    printf("\n");
    //memory cleanup
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}