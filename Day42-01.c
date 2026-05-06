/*Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/
#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int main() {
    int n, i;
    int front = 0, rear = -1;
    int top = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Enqueue elements
    for(i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &queue[++rear]);
    }

    // Move queue elements to stack
    for(i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack back to queue
    rear = -1;
    while(top != -1) {
        queue[++rear] = stack[top--];
    }

    // Print reversed queue
    for(i = 0; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}