#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1)
        s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->items[(s->top)--];
}

bool isBalanced(const char *expr) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i]; i++) {
        char c = expr[i];

        // push opening brackets onto the stack
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        }
        // for closing brackets, check if it matches the last opened one
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&s)) return false;
            char open = pop(&s);
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{'))
                return false;
        }
    }

    // if stack is empty, all brackets were matched
    return isEmpty(&s);
}

int main() {
    const char *expressions[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };

    printf("Balanced Parentheses Checker\n\n");

    for (int i = 0; i < 3; i++) {
        printf("Expression %d: %s\n", i + 1, expressions[i]);
        printf("Result: %s\n\n", isBalanced(expressions[i]) ? "Balanced" : "Not balanced");
    }

    return 0;
}