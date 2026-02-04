#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100 //maximum stack expression size
typedef struct {
    char items[MAX];
    int top;

} stack;
//stack initialization
void initializationstack(stack *s) {
    s->top = -1;
}
//checking if stack is empty
bool isempty(stack *s) {
    return s->top == -1;
}
//push operation
bool push(Stack *s, char c) {
    if (s->top >= MAX_SIZE - 1) return false; // Stack overflow
    s->items[++(s->top)] = c;
    return true;
}
//pop operation
char pop(stack *s) {
    if (isempty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}
//peek operation
char peek(stack *s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top];
}
