/*Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/

#include <stdio.h>

// Check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (pagesSum + arr[i] > maxPages) {
            students++;
            pagesSum = arr[i];

            if (students > m) return 0;
        } else {
            pagesSum += arr[i];
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1;

    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > left)
            left = arr[i];
        right += arr[i];
    }

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;
    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter pages in book %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int result = allocateBooks(arr, n, m);
    printf("%d\n", result);

    return 0;
}