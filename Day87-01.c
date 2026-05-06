/*Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/

#include <stdio.h>

int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == item)
            return mid + 1;
        else if (arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        int loc = binarySearch(arr, key, 0, j);

        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    binaryInsertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}