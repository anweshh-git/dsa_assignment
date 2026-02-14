Infix to Postfix Converter and Evaluator

Program Name: Infix to Postfix Converter and Evaluator
Language: C
Author: Anwesh Humagain
Date: 14-Feb-2026
Course: COMP202

---

(a) Data Structures

this program uses stacks implemented as arrays

operator Stack

char opStack[MAX] — stores operators and parentheses while converting infix to postfix.
int opTop — tracks the top of the operator stack. Starts at -1 meaning empty.

value Stack

int valStack[MAX] — stores integer operands while evaluating the postfix expression.
int valTop — tracks the top of the value stack. Starts at -1 meaning empty.

Both stacks share the same MAX size of 100. Keeping them separate makes the conversion and evaluation steps cleaner since they deal with different types of data.

---

(b) functions

1. pushOp(char c)
pushes a character onto the operator stack

2. popOp()
removes and returns the top character from the operator stack.

3. peekOp()
returns the top character of the operator stack without removing it.

4. isEmptyOp()
returns 1 if the operator stack is empty, 0 otherwise.

5. pushVal(int n)
pushes an integer onto the value stack.

6. popVal()
removes and returns the top integer from the value stack.

7. prec(char c)
returns the precedence level of an operator. + and - return 1, * and / return 2. higher the number greater becomes its priority. this is used during conversion to decide whether to pop operators before pushing a new one.

8. infixToPostfix(char *infix, char *postfix)
Converts an infix expression to postfix. It goes through the infix string one character at a time:
- Digits are directly added to the postfix output.
- Opening brackets are pushed onto the operator stack.
- Closing brackets cause operators to be popped into postfix until the matching opening bracket is found.
- For operators, any operator on the stack with equal or higher precedence is popped first before pushing the new one.
- After the full expression is scanned, any remaining operators on the stack are popped into postfix.

9. evaluate(char *postfix)
Evaluates a postfix expression and returns the result. It scans the postfix string:
- Digits are pushed onto the value stack.
- When an operator is found, two values are popped, the operation is applied, and the result is pushed back.
- At the end, the final result sitting on the stack is returned.

---

(c)structure of main()

main() runs two test cases back to back. For each one it copies an infix expression into a string, calls infixToPostfix() to convert it, then calls evaluate() on the result. It prints the original infix, the converted postfix, and the final computed result. There is no user input — the expressions are hardcoded to keep things simple.

---

(d) Sample Output

Test Case 1
Input:   3+4*2/(1-5)
Postfix: 342*15-/+
Result:  1
```
Infix:   3+4*2/(1-5)
Postfix: 342*15-/+
Result:  1
```

Test Case 2
Input:   (5+3)*2
Postfix: 53+2*
Result:  16
```
Infix:   (5+3)*2
Postfix: 53+2*
Result:  16
```