#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

//stack for operators
char opStack[MAX];
int opTop = -1;

//stack for values
int valStack[MAX];
int valTop = -1;

//function prototypes
void pushOp(char c) { opStack[++opTop] = c; }
char popOp() { return opStack[opTop--]; }
char peekOp() { return opStack[opTop]; }
int isEmptyOp() { return opTop == -1; }

void pushVal(int n) { valStack[++valTop] = n; }
int popVal() { return valStack[valTop--]; }

//function to return precedence of operators
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}
//function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        
        if (isdigit(c)) postfix[j++] = c;         
        else if (c == '(') pushOp(c);            
        else if (c == ')') {                     
            while (!isEmptyOp() && peekOp() != '(')
                postfix[j++] = popOp();
            popOp(); // Remove '('
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!isEmptyOp() && peekOp() != '(' && 
                   prec(peekOp()) >= prec(c))
                postfix[j++] = popOp();
            pushOp(c);
        }
    }
    while (!isEmptyOp()) postfix[j++] = popOp();   //pop remaining operators
    postfix[j] = '\0';
}

