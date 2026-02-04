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
bool push(stack *s, char c) {
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
//checking if expression has balanced number of brackets
bool isblanced(const char *e) { // e for expression
    char stack[100];
    int top = -1;
    
    for (int i = 0; e[i]; i++) {
        char c = e[i];
        
        //push opening brackets inside stacl
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        }
        //checing closing brackets
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) return false; 
            
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return false;
            }
        }
    }
    
    return top == -1; //is true if stack is empty
}
