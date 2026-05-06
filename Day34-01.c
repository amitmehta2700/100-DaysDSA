#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main() {
    char exp[100];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    for(i = 0; exp[i] != '\0'; i++) {

        if(isdigit(exp[i])) {
            push(exp[i] - '0');   
        }

        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

            b = pop();
            a = pop();

            switch(exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}