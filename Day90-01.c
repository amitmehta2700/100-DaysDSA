/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40. The maximum time taken by any painter is 60, which is the minimum possible.*/
#include <stdio.h>

// Check if painting is possible within given maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (currTime + arr[i] > maxTime) {
            painters++;
            currTime = arr[i];

            if (painters > k) return 0;
        } else {
            currTime += arr[i];
        }
    }
    return 1;
}

int minTime(int arr[], int n, int k) {
    int left = 0, right = 0;

    // find range
    for (int i = 0; i < n; i++) {
        if (arr[i] > left)
            left = arr[i];
        right += arr[i];
    }

    int result = right;

    // binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            right = mid - 1;  // try smaller
        } else {
            left = mid + 1;   // need more time
        }
    }

    return result;
}

// Main function
int main() {
    int n, k;
    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter length of board %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));

    return 0;
}