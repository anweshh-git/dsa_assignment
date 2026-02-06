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
