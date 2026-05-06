/*Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/
#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m;

    // Read number of elements to push
    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    // Push elements into stack
    for(int i = 0; i < n; i++) {
        int value;
        printf("Enter value to push: ");
        scanf("%d", &value);
        if(top < MAX - 1) {
            stack[++top] = value;
        }
    }

    // Read number of pops
    printf("Enter number of pops: ");
    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        if(top >= 0) {
            top--;
        }
    }

    // Print remaining stack from top to bottom
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}