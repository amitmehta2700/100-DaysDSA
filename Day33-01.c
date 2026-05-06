/*Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x) {
    stack[++top] = x;
}
char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int precedence(char x) {
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    for(i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        if(isalnum(ch)) {             
            postfix[j++] = ch;
        }
        else if(ch == '(') {
            push(ch);
        }
        else if(ch == ')') {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else { 
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }
    while(top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("%s\n", postfix);
    return 0;
}