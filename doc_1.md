Balanced Parentheses Checker

Program Name: Balanced Parentheses Checker
Language: C
Author: Anwesh Humagain ,
Date: 14-Feb-2026
Course: COMP202

---

(a) Data Structures

The core data structure here is a stack built using a struct. It holds an array of characters and a top pointer to track where we are in the stack.
```c
typedef struct {
    char items[MAX];
    int top;
} Stack;
```

- char items[MAX] — this is where opening brackets get stored as we scan through the expression. MAX is set to 100.
- int top — tracks the current top of the stack. Starts at -1, which just means the stack is empty.

The idea is simple: every time we see an opening bracket we push it in, and every time we see a closing bracket we pop and check if they match.

---

(b) Functions

1. init(Stack *s)
Sets up the stack before use by setting top to -1.

2. isEmpty(Stack *s)
Returns true if the stack has nothing in it, false otherwise. Used before popping to avoid reading garbage values.

3. push(Stack *s, char c)
Puts a character on top of the stack. Only pushes if there is still space (top < MAX - 1).

4. pop(Stack *s)
Takes the top character off the stack and returns it. If the stack is already empty, it returns '\0' to avoid a crash.

5. isBalanced(const char *expr)
This is the main logic of the program. It goes through the expression one character at a time:
- If it sees (, [ or { it pushes it onto the stack.
- If it sees ), ] or } it pops the stack and checks if the brackets match.
- If the stack is empty when it tries to pop, or if the brackets don't match, it returns false.
- At the end, if the stack is empty it means every opening bracket had a matching closing bracket, so it returns true.

---

(c) How main() is structured

main() keeps things straightforward. It has three hardcoded expressions to test and loops through each one calling isBalanced(). For each expression it prints the input and whether it came out balanced or not. All the actual bracket-checking logic lives inside isBalanced(), so main() is just handling the input and printing results.

---

(d) Sample Output

Test Case 1
Input: a + (b - c) * (d
Output: Not balanced
```
Expression 1: a + (b - c) * (d
Result: Not balanced
```

Test Case 2
Input: m + [a - b * (c + d * {m)]
Output: Not balanced
```
Expression 2: m + [a - b * (c + d * {m)]
Result: Not balanced
```

Test Case 3
Input: a + (b - c)
Output: Balanced
```
Expression 3: a + (b - c)
Result: Balanced
```