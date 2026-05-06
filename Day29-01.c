/*Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* rotateRight(struct Node* head, int k) {

    if(head == NULL || head->next == NULL)
        return head;

    int count = 1;
    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    struct Node* tail = temp;

    k = k % count;

    if(k == 0)
        return head;

    tail->next = head;

    int steps = count - k;
    struct Node* newTail = head;

    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    struct Node* head = createList(n);

    int k;
    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}