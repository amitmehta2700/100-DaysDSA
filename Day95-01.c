/*Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void bucketSort(float arr[], int n) {
    struct Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        insertSorted(&buckets[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}