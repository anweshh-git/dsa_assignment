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
